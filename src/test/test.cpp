#include "lang/codegen/codegen_ctx.h"
#include "lang/compiler_context.h"
#include "lang/lexer/code_location.h"
#include "lang/lexer/token.h"
#include "lang/sema/sema_ctx.h"
#include "magic_enum.hpp"
#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/Analysis/CGSCCPassManager.h"
#include "llvm/Analysis/LoopAnalysisManager.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_os_ostream.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/TargetParser/Host.h"
#include <argparse/argparse.hpp>
#include <csignal>
#include <fmt/ranges.h>
#include <fstream>
#include <iostream>
#include <lang/parser/parser.h>
#include <llvm/Transforms/InstCombine/InstCombine.h>
#include <llvm/Transforms/Scalar.h>
#include <llvm/Transforms/Utils.h>
#include <ranges>
#include <sstream>
#include <variant>

template <typename... Ts>
struct overload : Ts...
{
    using Ts::operator()...;
};
template <class... Ts>
overload(Ts...) -> overload<Ts...>;

template <typename B1, typename B2>
class cat_streambuf : public std::streambuf
{
    B1* buf1;
    B2* buf2;
    std::vector<char> buffer;
    bool in_buf1 = true;

public:
    cat_streambuf(B1* sb1, B2* sb2) : buf1(sb1), buf2(sb2), buffer(1024) {}

    auto underflow() -> int override
    {
        if (gptr() == egptr())
        {
            auto size = [this] {
                if (in_buf1)
                {
                    if (auto size = buf1->sgetn(buffer.data(), buffer.size()))
                    {
                        return size;
                    }
                    in_buf1 = false;
                }

                return buf2->sgetn(buffer.data(), buffer.size());
            }();

            setg(buffer.data(), buffer.data(), buffer.data() + size);
        }
        return gptr() == egptr() ? std::char_traits<char>::eof() : std::char_traits<char>::to_int_type(*gptr());
    }
};

template <typename B1, typename B2>
cat_streambuf(B1*, B2*) -> cat_streambuf<B1, B2>;

constexpr auto serialize_location(const std::variant<code_range, code_location, std::monostate>& loc) -> std::string
{
    return std::visit(
        overload{[](const code_location& loc) { return fmt::format("@({}:{})", loc.line, loc.col); },
                 [](const code_range& loc) { return fmt::format("@({}:{}-{}:{})", loc.start.line, loc.start.col, loc.end.line, loc.end.col); },
                 [](std::monostate) { return std::string("(no loc)"); }},
        loc);
}

void dump_diagnostics(compiler_context& ctx)
{
    for (const auto& diagnostic : ctx.get_diagnostics())
    {
        std::cout << fmt::format("{}: {}: {}\n", magic_enum::enum_name(diagnostic.diagnostic_level),
                                 serialize_location(diagnostic.main_diagnostic.location), diagnostic.main_diagnostic.message);

        if (diagnostic.fix)
        {
            std::cout << fmt::format("    potential fix: {}\n", diagnostic.fix.value());
        }

        for (const auto& note : diagnostic.related)
        {
            std::cout << fmt::format("    note: {}: {}\n", serialize_location(note.location), note.message);
        }
    }

    if (ctx.get_error_count())
    {
        std::cout << fmt::format("compilation failed with {} errors\n", ctx.get_error_count());
    }
    if (ctx.get_warning_count())
    {
        std::cout << fmt::format("{} warnings diagnostics reported\n", ctx.get_warning_count());
    }
    if (ctx.get_info_count())
    {
        std::cout << fmt::format("{} info diagnostics reported\n", ctx.get_info_count());
    }

    if (ctx.get_error_count())
    {
        exit(-1);
    }
}

void optimize(llvm::Module& module, llvm::OptimizationLevel level)
{
    llvm::LoopAnalysisManager loop_analysis;
    llvm::FunctionAnalysisManager function_analysis;
    llvm::CGSCCAnalysisManager scc_analysis;
    llvm::ModuleAnalysisManager module_analysis;
    llvm::PassBuilder builder;

    builder.registerModuleAnalyses(module_analysis);
    builder.registerCGSCCAnalyses(scc_analysis);
    builder.registerFunctionAnalyses(function_analysis);
    builder.registerLoopAnalyses(loop_analysis);
    builder.crossRegisterProxies(loop_analysis, function_analysis, scc_analysis, module_analysis);

    llvm::ModulePassManager pass_mgr = builder.buildPerModuleDefaultPipeline(level);
    pass_mgr.run(module, module_analysis);
}

void emit_code(llvm::Module& module, const std::string& output)
{
    // -- code emit
    auto target_triple = llvm::sys::getDefaultTargetTriple();
    llvm::InitializeAllTargetInfos();
    llvm::InitializeAllTargets();
    llvm::InitializeAllTargetMCs();
    llvm::InitializeAllAsmParsers();
    llvm::InitializeAllAsmPrinters();

    std::string err;
    const auto* target = llvm::TargetRegistry::lookupTarget(target_triple, err);

    if (target == nullptr)
    {
        std::cerr << err;
        exit(-1);
    }

    const auto* cpu = "generic";
    const auto* feat = "";

    llvm::TargetOptions opt;
    auto relocation = std::optional<llvm::Reloc::Model>();
    auto* target_mach = target->createTargetMachine(target_triple, cpu, feat, opt, relocation);
    module.setDataLayout(target_mach->createDataLayout());
    module.setTargetTriple(target_triple);

    std::error_code errc;
    llvm::raw_fd_ostream dest(output, errc, llvm::sys::fs::OF_None);

    if (errc)
    {
        std::cerr << "Could not open file: " << errc.message();
        exit(-1);
    }

    llvm::legacy::PassManager pass;
    auto file_type = llvm::CGFT_ObjectFile;

    if (target_mach->addPassesToEmitFile(pass, dest, nullptr, file_type))
    {
        std::cerr << "TargetMachine can't emit a file of this type";
        exit(-1);
    }

    pass.run(module);
    dest.flush();
}

auto main(int argc, char** argv) -> int
{
    auto args = std::span(argv, size_t(argc));

    auto* prog_name = args[0];
    argparse::ArgumentParser program(prog_name);

    program.add_argument("files").remaining();

    try
    {
        program.parse_args(argc, argv);
    }
    catch (const std::runtime_error& err)
    {
        std::cerr << err.what() << std::endl;
        std::cerr << program;
        std::exit(1);
    }

    auto files = program.get<std::vector<std::string>>("files");

    if (files.empty())
    {
        std::cerr << prog_name << "no input file\n";
        exit(-1);
    }

    // -- parsing
    std::ifstream input(files.front());
    std::ifstream lib_types("stdlib/types");

    cat_streambuf streambuf(lib_types.rdbuf(), input.rdbuf());
    std::istream read_in(&streambuf);

    compiler_context ctx(read_in);
    lexer lexer(ctx);
    auto ast = parse(lexer, ctx);
    dump_diagnostics(ctx);
    sema_ctx sema(ctx);
    ast->semantic_analysis(sema);
    dump_diagnostics(ctx);
    codegen_ctx codegen(sema);
    ast->codegen(codegen);
    optimize(codegen.module(), llvm::OptimizationLevel::O2);

    std::cerr << "Running testcases";
    auto& module = codegen.module();
}


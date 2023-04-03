#include "lang/codegen/codegen_ctx.h"
#include "lang/compiler.h"
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

void dump_diagnostics(const compiler_context& context)
{
    for (const auto& diagnostic : context.get_diagnostics())
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

    if (context.get_error_count())
    {
        std::cout << fmt::format("compilation failed with {} errors\n", context.get_error_count());
    }
    if (context.get_warning_count())
    {
        std::cout << fmt::format("{} warnings diagnostics reported\n", context.get_warning_count());
    }
    if (context.get_info_count())
    {
        std::cout << fmt::format("{} info diagnostics reported\n", context.get_info_count());
    }

    if (context.get_error_count())
    {
        exit(-1);
    }
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

void write_token(std::ostream& out, const std::vector<token>& tokens)
{
    out << fmt::format(
        "[{}]",
        fmt::join(
            tokens | std::views::transform([](const token& token) {
                std::string data;
                if (token.has_value<literal_value<std::string>>())
                {
                    data = fmt::format(R"({{"value":"{}","literal":"{}"}})", token.get_literal<std::string>().value,
                                       token.get_literal<std::string>().literal_specifier);
                }
                else if (token.has_value<literal_value<intmax_t>>())
                {
                    data = fmt::format(R"({{"value":{},"literal":"{}"}})", token.get_literal<intmax_t>().value,
                                       token.get_literal<intmax_t>().literal_specifier);
                }
                else if (token.has_value<literal_value<long double>>())
                {
                    data = fmt::format(R"({{"value":{},"literal":"{}"}})", token.get_literal<long double>().value,
                                       token.get_literal<long double>().literal_specifier);
                }
                else if (token.has_value<std::string>())
                {
                    data = fmt::format(R"("{}")", token.get_value<std::string>());
                }
                else if (token.has_value<token::operators>())
                {
                    data = fmt::format(R"({{"id":{},"name":"{}"}})", token.get_value<token::operators>(),
                                       magic_enum::enum_name(token.get_value<token::operators>()));
                }
                else if (token.has_value<char>())
                {
                    data = fmt::format(R"("{}")", token.get_value<char>());
                }
                else if (token.has_value<std::monostate>())
                {
                    data = "null";
                }

                return fmt::format(
                    R"({{"id":{},"name":"{}","start_loc":{{"line":{},"column":{},"bytes":{}}},"end_loc":{{"line":{},"column":{},"bytes":{}}},"data":{}}})",
                    token.type(), magic_enum::enum_name(token.type()), token.location().line, token.location().col, token.location().bytes,
                    token.end_location().line, token.end_location().col, token.end_location().bytes, data);
            }),
            ","));
}

void with_option(argparse::ArgumentParser& program, const std::string_view& str, auto callback)
{
    if (program.present(str))
    {
        auto file = program.get<std::string>(str);
        std::ofstream out(file);

        if (!out)
        {
            std::cerr << "unable to open file '" << file << "'\n";
            exit(-1);
        }

        callback(out);
    }
}

void start(argparse::ArgumentParser& program)
{
    auto files = program.get<std::vector<std::string>>("files");
    auto output = program.get<std::string>("--output");

    if (files.empty())
    {
        std::cerr << "no input file\n";
        exit(-1);
    }

    std::ifstream input(files.front());
    std::ifstream lib_types("stdlib/types");

    cat_streambuf streambuf(lib_types.rdbuf(), input.rdbuf());
    std::istream read_in(&streambuf);

    compiler comp(read_in);

    comp.parse_src();
    dump_diagnostics(comp.get_compiler_ctx());

    with_option(program, "--emit-ast", [&comp](std::ostream& out) { out << comp.get_serialized_ast(); });
    with_option(program, "--emit-tokens", [&comp](std::ostream& out) { write_token(out, comp.get_tokens()); });

    comp.semantic_analysis();
    dump_diagnostics(comp.get_compiler_ctx());

    if (program.get<bool>("--syntax-only"))
    {
        exit(0);
    }

    comp.emit_ir();

    with_option(program, "--emit-raw-ir", [&comp](std::ostream& out) {
        llvm::raw_os_ostream raw_os(out);
        comp.get_raw_ir().print(raw_os, nullptr);
    });

    llvm::OptimizationLevel level = llvm::OptimizationLevel::O2;

    if (program.get<bool>("-O0"))
    {
        level = llvm::OptimizationLevel::O0;
    }
    if (program.get<bool>("-O1"))
    {
        level = llvm::OptimizationLevel::O1;
    }
    if (program.get<bool>("-O2"))
    {
        level = llvm::OptimizationLevel::O2;
    }
    if (program.get<bool>("-O3"))
    {
        level = llvm::OptimizationLevel::O3;
    }

    comp.optimize(level);

    with_option(program, "--emit-ir", [&comp](std::ostream& out) {
        llvm::raw_os_ostream raw_os(out);
        comp.get_optimized_ir().print(raw_os, nullptr);
    });

    emit_code(comp.get_optimized_ir(), output);
}

auto main(int argc, char** argv) -> int
{
    auto args = std::span(argv, size_t(argc));

    auto* prog_name = args[0];
    argparse::ArgumentParser program(prog_name);

    program.add_argument("--emit-tokens").help("emit tokens to file").metavar("token-out");
    program.add_argument("--emit-ast").help("emit AST to file").metavar("ast-out");
    program.add_argument("--emit-raw-ir").help("emit unoptimized IR").metavar("ir-out");
    program.add_argument("--emit-ir").help("emit IR").metavar("ir-out");
    program.add_argument("-o", "--output").required().help("specify the output file.").metavar("output");
    program.add_argument("-O0").default_value(false).implicit_value(true).help("disable optimization");
    program.add_argument("-O1").default_value(false).implicit_value(true).help("set optimization to level 1");
    program.add_argument("-O2").default_value(false).implicit_value(true).help("set optimization to level 2");
    program.add_argument("-O3").default_value(false).implicit_value(true).help("set optimization to level 3");
    program.add_argument("--syntax-only").default_value(false).implicit_value(true);
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

    start(program);
}


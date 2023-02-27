#include "lang/codegen/codegen_ctx.h"
#include "lang/compiler_context.h"
#include "lang/lexer/code_location.h"
#include "lang/lexer/token.h"
#include "lang/sema/sema_ctx.h"
#include "magic_enum.hpp"
#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
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

template <typename... Ts>
struct overload : Ts...
{
    using Ts::operator()...;
};
template <class... Ts>
overload(Ts...) -> overload<Ts...>;

[[noreturn]] void dump_errors(compiler_context& ctx)
{
    for (const auto& error : ctx.get_errors())
    {
        std::cout << "error "
                  << std::visit(overload{[](const code_location& loc) { return fmt::format("@({}:{})", loc.line, loc.col); },
                                         [](const code_range& loc) {
                                             return fmt::format("@({}:{}-{}:{})", loc.start.line, loc.start.col, loc.end.line, loc.end.col);
                                         }},
                                error.main_error)
                  << " " << error.message << '\n';
        if (error.fix)
        {
            std::cout << "    potential fix: " << error.fix.value() << '\n';
        }

        for (const auto& notes : error.related)
        {
            std::cout << fmt::format("    note @({}:{}-{}:{}): {}\n", notes.first.start.line, notes.first.start.col, notes.first.end.line,
                                     notes.first.end.col, notes.second);
        }
    }
    exit(-1);
}

auto main(int argc, char** argv) -> int
{
    auto* prog_name = argv[0];
    argparse::ArgumentParser program(prog_name);

    program.add_argument("--emit-tokens").append().help("emit tokens to file").metavar("token-out");
    program.add_argument("--emit-ast").append().help("emit AST to file").metavar("ast-out");
    program.add_argument("--emit-raw-ir").append().help("emit unoptimized IR").metavar("ir-out");
    program.add_argument("--emit-ir").append().help("emit IR").metavar("ir-out");
    program.add_argument("-o", "--output").required().help("specify the output file.").metavar("output");
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
    auto output = program.get<std::string>("--output");
    // auto token_out = program.get<std::string>("--emit-tokens");
    // auto token_json_out = program.get<std::string>("--emit-tokens");

    if (files.empty())
    {
        std::cerr << prog_name << "no input file\n";
        exit(-1);
    }

    // -- parsing
    std::ifstream input(files.front());
    compiler_context ctx(input);
    lexer lexer(ctx);

    auto ast = parse(lexer, ctx);

    if (!ctx.get_errors().empty())
    {
        dump_errors(ctx);
    }

    if (program.present("--emit-ast"))
    {
        auto file = program.get<std::string>("--emit-ast");
        std::ofstream out(file);

        if (!out)
        {
            std::cerr << "unable to open file '" << file << "'\n";
            exit(-1);
        }

        out << ast->serialize();
    }

    if (program.present("--emit-tokens"))
    {
        auto file = program.get<std::string>("--emit-tokens");
        std::ofstream out(file);

        if (!out)
        {
            std::cerr << "unable to open file '" << file << "'\n";
            exit(-1);
        }

        out << fmt::format(
            "[{}]",
            fmt::join(
                lexer.get_prev_tokens() | std::views::transform([](const token& token) {
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

    // -- semantic analysis
    sema_ctx sema(ctx);
    ast->semantic_analysis(sema);

    if (!ctx.get_errors().empty())
    {
        dump_errors(ctx);
    }

    // -- codegen
    codegen_ctx codegen(sema);
    ast->codegen(codegen);

    if (program.present("--emit-raw-ir"))
    {
        auto file = program.get<std::string>("--emit-raw-ir");
        std::ofstream out(file);

        if (!out)
        {
            std::cerr << "unable to open file '" << file << "'\n";
            exit(-1);
        }

        llvm::raw_os_ostream raw_os(out);
        codegen.module().print(raw_os, nullptr);
    }

    // -- optimization
    auto optimizer = std::make_unique<llvm::legacy::FunctionPassManager>(&codegen.module());
    optimizer->add(llvm::createPromoteMemoryToRegisterPass());
    optimizer->add(llvm::createInstructionCombiningPass());
    optimizer->add(llvm::createReassociatePass());
    optimizer->add(llvm::createNewGVNPass());
    optimizer->add(llvm::createCFGSimplificationPass());
    optimizer->doInitialization();

    for (auto& func : codegen.module().getFunctionList())
    {
        optimizer->run(func);
    }

    if (program.present("--emit-ir"))
    {
        auto file = program.get<std::string>("--emit-ir");
        std::ofstream out(file);

        if (!out)
        {
            std::cerr << "unable to open file '" << file << "'\n";
            exit(-1);
        }

        llvm::raw_os_ostream raw_os(out);
        codegen.module().print(raw_os, nullptr);
    }

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
    codegen.module().setDataLayout(target_mach->createDataLayout());
    codegen.module().setTargetTriple(target_triple);

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

    pass.run(codegen.module());
    dest.flush();
}

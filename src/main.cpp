#include "lang/codegen/codegen_ctx.h"
#include "lang/compiler_context.h"
#include "lang/lexer/code_location.h"
#include "lang/sema/sema_ctx.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/InstCombine/InstCombine.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Scalar/GVN.h"
#include "llvm/Transforms/Utils.h"
#include <csignal>
#include <fstream>
#include <iostream>
#include <lang/parser/parser.h>
#include <sstream>
#include <stacktrace.h>

void visit_ast(const base_ast& ast, size_t indent = 0)
{
    std::cerr << std::string(indent * 2, ' ') << AST_KIND_NAME[ast.get_ast_kind()] << '\n';
    ast.visit_children([indent](const auto& val) { visit_ast(val, indent + 1); });
}

template <typename... Ts> // (7)
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
    /*
    signal(SIGSEGV, +[](int) {
        std::cout << "crash:\n";
        stacktrace::dump_stacktrace();
        exit(-1);
    });*/

    if (argc != 2)
    {
        std::cerr << "i forgor";
        exit(-1);
    }

    std::ifstream input(argv[1]);

    compiler_context ctx(input);
    lexer lexer(ctx);

    auto ast = parse(lexer, ctx);

    if (!ctx.get_errors().empty())
    {
        dump_errors(ctx);
    }

    std::cerr << "--- AST dump ---\n";

    if (!ast)
    {
        return 0;
    }

    visit_ast(*ast);
    std::cerr << "\n";

    sema_ctx sema(ctx);
    ast->semantic_analysis(sema);

    if (!ctx.get_errors().empty())
    {
        dump_errors(ctx);
    }

    codegen_ctx codegen(sema);
    ast->codegen(codegen); // we should not have codegen errors

    std::cerr << "--- codegen dump (constant-folding) ---\n";
    codegen.module().print(llvm::errs(), nullptr);

    auto optimizer = std::make_unique<llvm::legacy::FunctionPassManager>(&codegen.module());
    optimizer->add(llvm::createPromoteMemoryToRegisterPass());
    optimizer->add(llvm::createInstructionCombiningPass());
    optimizer->add(llvm::createReassociatePass());
    optimizer->add(llvm::createGVNPass());
    optimizer->add(llvm::createCFGSimplificationPass());

    optimizer->doInitialization();

    for (auto& func : codegen.module().getFunctionList())
    {
        optimizer->run(func);
    }

    std::cerr << "--- codegen dump (constant-folding,promote-memory-to-register,inst-combine,reassociate,gnv,cfg-simplify) ---\n";
    codegen.module().print(llvm::errs(), nullptr);
}

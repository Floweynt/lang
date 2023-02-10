#include "lang/lexer/code_location.h"
#include "lang/sema/sema_ctx.h"
#include <csignal>
#include <fstream>
#include <iostream>
#include <lang/parser/parser.h>
#include <sstream>
#include <stacktrace.h>

void visit_ast(const base_ast& ast, size_t indent = 0)
{
    std::cout << std::string(indent * 2, ' ') << AST_KIND_NAME[ast.get_ast_kind()] << '\n';
    ast.visit_children([indent](const auto& i) { visit_ast(i, indent + 1); });
}

template <typename... Ts> // (7)
struct overload : Ts...
{
    using Ts::operator()...;
};
template <class... Ts>
overload(Ts...) -> overload<Ts...>;

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

    std::ifstream ss(argv[1]);
    compiler_context ctx(ss);
    lexer l(ctx);
    auto ast = parse(l, ctx);

    if (ast)
    {
        sema_ctx sema(ctx);
        ast->semantic_analysis(sema);
    }

    for (const auto& i : ctx.get_errors())
    {
        std::cout << "error "
                  << std::visit(overload{[](const code_location& loc) { return fmt::format("@({}:{})", loc.line, loc.col); },
                                         [](const code_range& loc) {
                                             return fmt::format("@({}:{}-{}:{})", loc.start.line, loc.start.col, loc.end.line, loc.end.col);
                                         }},
                                i.main_error)
                  << " " << i.message << '\n';
        if (i.fix)
        {
            std::cout << "    potential fix: " << i.fix.value() << '\n';
        }

        for (const auto& j : i.related)
        {
            std::cout << fmt::format("    note @({}:{}-{}:{}): {}\n", j.first.start.line, j.first.start.col, j.first.end.line, j.first.end.col,
                                     j.second);
        }
    }

    if (ast)
    {
        visit_ast(*ast);
    }
}

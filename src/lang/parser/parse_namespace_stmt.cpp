#include "lang/ast/namespace_stmt_ast.h"
#include "lang/lexer/token.h"
#include "parser_util.h"
#include <lang/parser/parser.h>

auto parse_namespace_stmt(lexer& lexer, compiler_context& ctx) -> ast_ref
{
    auto start = lexer.curr_token().location();
    lexer.consume();
    std::vector<std::string> ns_path;

    while (true)
    {
        if (!lexer.curr_token().is(token::TOK_IDENTIFIER))
            report_error_point(lexer, "expected identifier");
        ns_path.push_back(lexer.curr_token().identifier());

        lexer.consume();

        if (!lexer.curr_token().is(token::TOK_DOUBLECOLON))
        {
            break;
        }
    }

    if (!lexer.curr_token().is(token::TOK_BRACE_OPEN))
        report_error_point(lexer, "expected '{' after namespace decleration to create scoped block");

    std::vector<ast_ref> block;
    lexer.consume();
    while (!lexer.curr_token().is(token::TOK_BRACE_CLOSE))
    {
        auto stmt = parse_top_level_stmt(lexer, ctx);
        if (!stmt)
        {
            return nullptr;
        }
        block.push_back(std::move(stmt));
    }

    auto end = lexer.curr_token().end_location();
    lexer.consume();

    return std::make_unique<namespace_stmt>(start, end, std::move(ns_path), std::move(block));
}

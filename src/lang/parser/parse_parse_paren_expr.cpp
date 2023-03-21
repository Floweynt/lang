#include "parser_util.h"
#include <lang/parser/parser.h>
#include "lang/ast/paren_expr_ast.h"

auto parse_paren_expr(lexer& lexer, compiler_context& ctx) -> ast_ref
{
    auto start = lexer.curr_token().location();
    lexer.consume();
    auto expr = parse_expr(lexer, ctx);

    if (!expr)
    {
        return nullptr;
    }

    if (!lexer.curr_token().is(token::TOK_PAREN_CLOSE))
        report_error_point_msg(lexer, "expected ')', got expression", "insert closing paren");

    auto end = lexer.curr_token().end_location();
    lexer.consume();

    return std::make_unique<paren_expr>(start, end, std::move(expr));
}

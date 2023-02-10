#include "parser_util.h"
#include <lang/parser/parser.h>

ast_ref parse_paren_expr(lexer& l, compiler_context& ctx)
{
    auto start = l.curr_token().location();
    l.consume();
    auto expr = parse_expr(l, ctx);

    if (!expr)
        return nullptr;

    if (!l.curr_token().is(token::TOK_PAREN_CLOSE))
        report_error_point_msg(l, "expected ')', got expression", "insert closing paren");

    auto end = l.curr_token().end_location();
    l.consume();

    return std::make_unique<paren_expr>(start, end, std::move(expr));
}

#include "parser_util.h"
#include <lang/parser/parser.h>

ast_ref parse_top_level_stmt(lexer& l, compiler_context& ctx)
{
    switch (l.curr_token().type())
    {
    case token::TOK_KW_VAR:
    case token::TOK_KW_CONST:
    case token::TOK_KW_CONSTEVAL:
    case token::TOK_KW_COMPTIME:
        return expect_semi(parse_variable_def_expr(l, ctx), l, ctx);
    case token::TOK_KW_USING:
        return expect_semi(parse_using_expr(l, ctx), l, ctx);
    case token::TOK_KW_NAMESPACE:
        return parse_namespace_stmt(l, ctx);
    case token::TOK_KW_AUTO:
        return parse_function_decl_stmt(l, ctx);
    default:
        report_error_point(l, "expected top-level statement");
    }
}

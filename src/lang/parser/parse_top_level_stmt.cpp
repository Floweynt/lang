#include "parser_util.h"
#include <lang/parser/parser.h>

auto parse_top_level_stmt(lexer& lexer, compiler_context& ctx) -> ast_ref
{
    switch (lexer.curr_token().type())
    {
    case token::TOK_KW_VAR:
    case token::TOK_KW_CONST:
    case token::TOK_KW_CONSTEVAL:
    case token::TOK_KW_COMPTIME:
        return expect_semi(parse_variable_def_expr(lexer, ctx), lexer, ctx);
    case token::TOK_KW_USING:
        return expect_semi(parse_using_expr(lexer, ctx), lexer, ctx);
    case token::TOK_KW_NAMESPACE:
        return parse_namespace_stmt(lexer, ctx);
    case token::TOK_KW_FN:
        return parse_function_decl_stmt(lexer, ctx);
    default:
        report_error_point(lexer, "expected top-level statement");
    }
}

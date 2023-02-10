#include "lang/lexer/token.h"
#include <lang/ast/empty_ast.h>
#include <lang/parser/parser.h>

static auto do_parse_expr(lexer& l, compiler_context& ctx) -> ast_ref
{
    auto lhs = parse_unary_expr(l, ctx);
    if (!lhs)
    {
        return nullptr;
    }

    return parse_binary_op_expr(l, ctx, 0, std::move(lhs));
}

auto parse_expr(lexer& l, compiler_context& ctx) -> ast_ref
{
    switch (l.curr_token().type())
    {
    case token::TOK_KW_VAR:
    case token::TOK_KW_CONST:
    case token::TOK_KW_CONSTEVAL:
    case token::TOK_KW_COMPTIME:
        return parse_variable_def_expr(l, ctx);
    case token::TOK_KW_USING:
        return parse_using_expr(l, ctx);
    case token::TOK_BRACE_OPEN:
        return parse_block_expr(l, ctx);
    default:
        return do_parse_expr(l, ctx);
    }
}

auto parse_expr_as_statement(lexer& l, compiler_context& ctx) -> ast_ref
{
    if (l.curr_token().is(token::TOK_SEMICOLON))
    {
        auto ret = std::make_unique<emtpy_ast>(l.curr_token().location(), l.curr_token().end_location());
        l.consume();
        return ret;
    }

    auto expr = parse_expr(l, ctx);
    if (!expr)
    {
        return nullptr;
    }
    if (expr->does_require_semicolon_stmt())
    {
        return expect_semi(std::move(expr), l, ctx);
    }
    return expr;
}

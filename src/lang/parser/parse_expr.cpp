#include "lang/lexer/token.h"
#include <lang/ast/empty_ast.h>
#include <lang/parser/parser.h>

static auto do_parse_expr(lexer& lexer, compiler_context& ctx) -> ast_ref
{
    auto lhs = parse_unary_expr(lexer, ctx);
    if (!lhs)
    {
        return nullptr;
    }

    return parse_binary_op_expr(lexer, ctx, 0, std::move(lhs));
}

auto parse_expr(lexer& lexer, compiler_context& ctx) -> ast_ref
{
    switch (lexer.curr_token().type())
    {
    case token::TOK_KW_VAR:
    case token::TOK_KW_CONST:
    case token::TOK_KW_CONSTEVAL:
    case token::TOK_KW_COMPTIME:
        return parse_variable_def_expr(lexer, ctx);
    case token::TOK_KW_USING:
        return parse_using_expr(lexer, ctx);
    case token::TOK_BRACE_OPEN:
        return parse_block_expr(lexer, ctx);
    default:
        return do_parse_expr(lexer, ctx);
    }
}

auto parse_expr_as_statement(lexer& lexer, compiler_context& ctx) -> ast_ref
{
    if (lexer.curr_token().is(token::TOK_SEMICOLON))
    {
        auto ret = std::make_unique<empty_ast>(lexer.curr_token().location(), lexer.curr_token().end_location());
        lexer.consume();
        return ret;
    }

    auto expr = parse_expr(lexer, ctx);
    if (!expr)
    {
        return nullptr;
    }
    if (expr->does_require_semicolon_stmt())
    {
        return expect_semi(std::move(expr), lexer, ctx);
    }
    return expr;
}

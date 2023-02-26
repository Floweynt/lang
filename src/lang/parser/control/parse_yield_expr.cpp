#include "../parser_util.h"
#include "lang/ast/base_ast.h"
#include "lang/ast/control/yield_expr_ast.h"
#include "lang/compiler_context.h"
#include "lang/lexer/lexer.h"
#include "lang/lexer/token.h"
#include "lang/parser/parser.h"

auto parse_yield_expr(lexer& lexer, compiler_context& ctx) -> ast_ref
{
    auto start = lexer.curr_token().location();
    lexer.consume();
    if (!lexer.curr_token().is(token::TOK_PAREN_OPEN))
        report_error_point(lexer, "expected '(' after yield expression");

    lexer.consume();
    auto ast = parse_expr(lexer, ctx);
    if (!ast)
    {
        return nullptr;
    }

    if (!lexer.curr_token().is(token::TOK_PAREN_CLOSE))
        report_error_point(lexer, "expected ')' after yield expression");

    auto end = lexer.curr_token().end_location();
    lexer.consume();
    return std::make_unique<yield_expr>(start, end, std::move(ast));
}

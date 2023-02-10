#include "lang/ast/base_ast.h"
#include "lang/ast/control/yield_expr_ast.h"
#include "lang/compiler_context.h"
#include "lang/lexer/lexer.h"
#include "lang/lexer/token.h"
#include "../parser_util.h"
#include "lang/parser/parser.h"

auto parse_yield_expr(lexer& l, compiler_context& ctx) -> ast_ref 
{
    auto start = l.curr_token().location();
    l.consume();
    if(!l.curr_token().is(token::TOK_PAREN_OPEN))
        report_error_point(l, "expected '(' after yield expression");

    l.consume();
    auto ast = parse_expr(l, ctx);
    if(!ast)
        return nullptr;

    if(!l.curr_token().is(token::TOK_PAREN_CLOSE))
        report_error_point(l, "expected ')' after yield expression");

    auto end = l.curr_token().end_location();
    l.consume();
    return std::make_unique<yield_expr>(start, end, std::move(ast));
}

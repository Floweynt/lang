#include "../parser_util.h"
#include "lang/ast/base_ast.h"
#include "lang/ast/control/while_expr_ast.h"
#include "lang/lexer/code_location.h"
#include "lang/lexer/token.h"
#include <lang/parser/parser.h>
#include <memory>

auto parse_while_expr(lexer& lexer, compiler_context& ctx) -> ast_ref
{
    auto start = lexer.curr_token().location();
    lexer.consume();
    if (!lexer.curr_token().is(token::TOK_PAREN_OPEN))
        report_error_point(lexer, "expected '(' in while condition");
    lexer.consume();

    auto condition = parse_expr(lexer, ctx);

    if (!lexer.curr_token().is(token::TOK_PAREN_CLOSE))
        report_error_point(lexer, "expected ')' after while condition");
    lexer.consume();

    auto body = parse_expr(lexer, ctx);
    if (!body)
    {
        return nullptr;
    }
    ast_ref else_branch;

    auto end = body->get_end();

    if (lexer.curr_token().is(token::TOK_KW_ELSE))
    {
        lexer.consume();
        if (lexer.curr_token() == token::OP_ARROW)
        {
            lexer.consume();
            else_branch = parse_expr(lexer, ctx);
        }
        else
        {
            else_branch = parse_expr_as_statement(lexer, ctx);
        }

        if (!else_branch)
        {
            return nullptr;
        }
        end = else_branch->get_end();
    }

    return std::make_unique<while_expr>(start, end, std::move(condition), std::move(body), std::move(else_branch));
}

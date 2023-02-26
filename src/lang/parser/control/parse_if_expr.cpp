#include "../parser_util.h"
#include "lang/ast/base_ast.h"
#include "lang/lexer/code_location.h"
#include "lang/lexer/token.h"
#include <lang/parser/parser.h>
#include <memory>

auto parse_if_expr(lexer& lexer, compiler_context& ctx) -> ast_ref
{
    std::vector<std::pair<ast_ref, ast_ref>> branches;
    ast_ref else_branch;
    auto start = lexer.curr_token().location();
    code_location end{};

    do
    {
        if (lexer.curr_token().is(token::TOK_KW_ELSE))
        {
            lexer.consume();
        }

        if (lexer.curr_token().is(token::TOK_KW_IF))
        {
            lexer.consume(); // consume the if
            if (!lexer.curr_token().is(token::TOK_PAREN_OPEN))
                report_error_point_msg(lexer, "expected '(' after if", "wrap the specified condition in '()'");
            lexer.consume();

            auto cond = parse_expr(lexer, ctx);

            if (!lexer.curr_token().is(token::TOK_PAREN_CLOSE))
                report_error_point_msg(lexer, "expected ')' after if condition", "insert ')' after condition");
            lexer.consume();

            ast_ref body;
            if (lexer.curr_token() == token::OP_ARROW)
            {
                lexer.consume();
                body = parse_expr(lexer, ctx);
            }
            else
            {
                body = parse_expr_as_statement(lexer, ctx);
            }

            if (!body)
            {
                return nullptr;
            }
            end = body->get_end();

            branches.emplace_back(std::move(cond), std::move(body));
        }
        else
        {
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
            break;
        }
    } while (lexer.curr_token().is(token::TOK_KW_ELSE));

    return std::make_unique<if_expr>(start, end, std::move(branches), std::move(else_branch));
}

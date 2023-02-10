#include "lang/ast/base_ast.h"
#include "lang/lexer/code_location.h"
#include "lang/lexer/token.h"
#include "../parser_util.h"
#include <lang/parser/parser.h>
#include <memory>

ast_ref parse_if_expr(lexer& l, compiler_context& ctx)
{
    std::vector<std::pair<ast_ref, ast_ref>> branches;
    ast_ref else_branch;
    auto start = l.curr_token().location();
    code_location end{};

    do
    {
        if (l.curr_token().is(token::TOK_KW_ELSE))
            l.consume();

        if (l.curr_token().is(token::TOK_KW_IF))
        {
            l.consume(); // consume the if
            if (!l.curr_token().is(token::TOK_PAREN_OPEN))
                report_error_point_msg(l, "expected '(' after if", "wrap the specified condition in '()'");
            l.consume();

            auto cond = parse_expr(l, ctx);

            if (!l.curr_token().is(token::TOK_PAREN_CLOSE))
                report_error_point_msg(l, "expected ')' after if condition", "insert ')' after condition");
            l.consume();

            ast_ref body;
            if (l.curr_token() == token::OP_ARROW)
            {
                l.consume();
                body = parse_expr(l, ctx);
            }
            else
            {
                body = parse_expr_as_statement(l, ctx);
            }

            if (!body)
                return nullptr;
            end = body->get_end();

            branches.emplace_back(std::move(cond), std::move(body));
        }
        else
        {
            if (l.curr_token() == token::OP_ARROW)
            {
                l.consume();
                else_branch = parse_expr(l, ctx);
            }
            else
            {
                else_branch = parse_expr_as_statement(l, ctx);
            }
            
            if (!else_branch)
                return nullptr;
            end = else_branch->get_end();
            break;
        }
    } while (l.curr_token().is(token::TOK_KW_ELSE));

    return std::make_unique<if_expr>(start, end, std::move(branches), std::move(else_branch));
}

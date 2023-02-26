#include "parser_util.h"
#include <cstddef>
#include <lang/parser/parser.h>

auto parse_lambda_expr(lexer& lexer, compiler_context& ctx) -> ast_ref
{
    auto start = lexer.curr_token().location();
    lexer.consume();
    if (!lexer.curr_token().is(token::TOK_PAREN_OPEN))
        report_error_point(lexer, "expected '(' in lambda");
    lexer.consume();

    std::vector<ast_ref> args;

    if (lexer.curr_token().type() != token::TOK_PAREN_CLOSE)
    {
        while (true)
        {
            if (auto arg = parse_variable_def_expr(lexer, ctx))
            {
                args.push_back(std::move(arg));
            }
            else
            {
                return nullptr;
            }

            if (lexer.curr_token().type() == token::TOK_PAREN_CLOSE)
            {
                break;
            }

            if (lexer.curr_token().type() != token::TOK_COMMA)
                report_error_point_msg(lexer, "expected ')' or ',' in parameter list", "insert comma");
            lexer.consume();
        }
    }

    // parse body
    lexer.consume();

    ast_ref return_type;

    if (lexer.curr_token() == token::OP_ARROW)
    {
        lexer.consume();
        return_type = parse_type_expr(lexer, ctx);
    }

    if (!lexer.curr_token().is(token::TOK_BRACE_OPEN))
        report_error_point(lexer, "expected '{' in lambda to declare body");

    ast_ref body = parse_block_expr(lexer, ctx);
    if (!body)
    {
        return nullptr;
    }
    return std::make_unique<lambda_expr>(start, body->get_end(), std::move(args), std::move(return_type), std::move(body));
}

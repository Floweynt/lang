#include "parser_util.h"
#include <cstddef>
#include <lang/parser/parser.h>

ast_ref parse_lambda_expr(lexer& l, compiler_context& ctx)
{
    auto start = l.curr_token().location();
    l.consume();
    if (!l.curr_token().is(token::TOK_PAREN_OPEN))
        report_error_point(l, "expected '(' in lambda");
    l.consume();

    std::vector<ast_ref> args;

    if (l.curr_token().type() != token::TOK_PAREN_CLOSE)
    {
        while (true)
        {
            if (auto arg = parse_variable_def_expr(l, ctx))
                args.push_back(std::move(arg));
            else
                return nullptr;

            if (l.curr_token().type() == token::TOK_PAREN_CLOSE)
                break;

            if (l.curr_token().type() != token::TOK_COMMA)
                report_error_point_msg(l, "expected ')' or ',' in parameter list", "insert comma");
            l.consume();
        }
    }

    // parse body
    l.consume();

    ast_ref return_type;

    if (l.curr_token() == token::OP_ARROW)
    {
        l.consume();
        return_type = parse_type_expr(l, ctx);
    }

    if (!l.curr_token().is(token::TOK_BRACE_OPEN))
        report_error_point(l, "expected '{' in lambda to declare body");

    ast_ref body = parse_block_expr(l, ctx);
    if (!body)
        return nullptr;
    return std::make_unique<lambda_expr>(start, body->get_end(), std::move(args), std::move(return_type), std::move(body));
}

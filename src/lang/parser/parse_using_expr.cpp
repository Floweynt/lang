#include "lang/ast/base_ast.h"
#include "lang/lexer/token.h"
#include "parser_util.h"
#include <lang/parser/parser.h>

ast_ref parse_using_expr(lexer& l, compiler_context& ctx)
{
    auto start = l.curr_token().location();
    l.consume();

    if (!l.curr_token().is(token::TOK_IDENTIFIER))
        report_error_point(l, "expected type name");
    auto name = l.curr_token().identifier();
    l.consume();

    std::vector<ast_ref> args;

    if (l.curr_token().is(token::TOK_PAREN_OPEN))
    {
        l.consume();
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
        l.consume();
    }

    if (l.curr_token() != token::OP_ASSIGN)
        report_error_point(l, "expected '='");
    l.consume();
    auto type = parse_expr(l, ctx);
    if (!type)
        return nullptr;

    auto end = type->get_end();

    return std::make_unique<using_expr>(start, end, name, std::move(type), std::move(args));
}

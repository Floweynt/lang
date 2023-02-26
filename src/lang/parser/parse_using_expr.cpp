#include "lang/ast/base_ast.h"
#include "lang/lexer/token.h"
#include "parser_util.h"
#include <lang/parser/parser.h>

auto parse_using_expr(lexer& lexer, compiler_context& ctx) -> ast_ref
{
    auto start = lexer.curr_token().location();
    lexer.consume();

    if (!lexer.curr_token().is(token::TOK_IDENTIFIER))
        report_error_point(lexer, "expected type name");
    auto name = lexer.curr_token().identifier();
    lexer.consume();

    std::vector<ast_ref> args;

    if (lexer.curr_token().is(token::TOK_PAREN_OPEN))
    {
        lexer.consume();
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
        lexer.consume();
    }

    if (lexer.curr_token() != token::OP_ASSIGN)
        report_error_point(lexer, "expected '='");
    lexer.consume();
    auto type = parse_expr(lexer, ctx);
    if (!type)
    {
        return nullptr;
    }

    auto end = type->get_end();

    return std::make_unique<using_expr>(start, end, name, std::move(type), std::move(args));
}

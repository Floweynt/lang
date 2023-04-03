#include "lang/ast/function_decl_stmt_ast.h"
#include "lang/lexer/token.h"
#include "lang/parser/parser.h"
#include "parser_util.h"

auto parse_function_decl_stmt(lexer& lexer, compiler_context& ctx) -> ast_ref
{
    auto start = lexer.curr_token().location();
    lexer.consume();

    ast_ref attributes;
    if (lexer.curr_token().is(token::TOK_ATTR_OPEN))
    {
        attributes = parse_attribute_list(lexer, ctx);
    }

    if (!lexer.curr_token().is(token::TOK_IDENTIFIER))
        report_error_point(lexer, "expected name in function decl");

    std::string name = lexer.curr_token().identifier();

    lexer.consume();
    if (!lexer.curr_token().is(token::TOK_PAREN_OPEN))
        report_error_point(lexer, "expected '(' in function decl");
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

    if (lexer.curr_token().is(token::TOK_SEMICOLON))
    {
        auto end = lexer.curr_token().end_location();
        lexer.consume();

        return std::make_unique<function_decl_stmt>(start, end, std::move(args), std::move(return_type), nullptr, name, std::move(attributes));
    }

    if (!lexer.curr_token().is(token::TOK_BRACE_OPEN))
        report_error_point(lexer, "expected '{' in function decl to declare body");

    ast_ref body = parse_block_expr(lexer, ctx);
    if (!body)
    {
        return nullptr;
    }

    return std::make_unique<function_decl_stmt>(start, body->get_end(), std::move(args), std::move(return_type), std::move(body), name,
                                                std::move(attributes));
}

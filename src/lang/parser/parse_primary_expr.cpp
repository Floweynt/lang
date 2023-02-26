#include "lang/ast/function_call_expr_ast.h"
#include "lang/lexer/token.h"
#include "parser_util.h"
#include <lang/parser/parser.h>

template <typename T>
static auto parse_literal_expr(lexer& lexer) -> ast_ref
{
    const auto& value = lexer.curr_token().get_value<literal_value<T>>();
    auto ret = std::make_unique<literal_expr<T>>(curr_token_loc(lexer), value.value, value.literal_specifier);
    lexer.consume();
    return std::move(ret);
}

static auto simple_parse_primary_expr(lexer& lexer, compiler_context& ctx) -> ast_ref
{
    switch (lexer.curr_token().type())
    {
    default:
        report_error_point(lexer, "expected primary expression");
    case token::TOK_IDENTIFIER:
        return parse_identifier_expr(lexer, ctx);
    case token::TOK_LANG_IDENTIFIER:
        return parse_lang_identifier_expr(lexer, ctx);
    case token::TOK_INTEGER:
        return parse_literal_expr<intmax_t>(lexer);
    case token::TOK_FLOATING:
        return parse_literal_expr<long double>(lexer);
    case token::TOK_STRING:
        return parse_literal_expr<std::string>(lexer);
    case token::TOK_CHAR:
        return parse_char_literal_expr(lexer, ctx);
    case token::TOK_PAREN_OPEN:
        return parse_paren_expr(lexer, ctx);
    case token::TOK_BKSLASH:
        return parse_lambda_expr(lexer, ctx);
    case token::TOK_KW_IF:
        return parse_if_expr(lexer, ctx);
    case token::TOK_KW_YIELD:
        return parse_yield_expr(lexer, ctx);
    case token::TOK_KW_WHILE:
        return parse_while_expr(lexer, ctx);
    case token::TOK_KW_RETURN:
        return parse_return_expr(lexer, ctx);
    }
}

auto parse_primary_expr(lexer& lexer, compiler_context& ctx) -> ast_ref
{
    auto begin = lexer.curr_token().location();
    auto expr = simple_parse_primary_expr(lexer, ctx);
    if (!expr)
    {
        return nullptr;
    }

    while (lexer.curr_token().is(token::TOK_PAREN_OPEN) || lexer.curr_token().is(token::TOK_BRACKET_OPEN))
    {
        if (lexer.curr_token().is(token::TOK_PAREN_OPEN))
        {
            std::vector<ast_ref> args;
            lexer.consume();
            while (!lexer.curr_token().is(token::TOK_PAREN_CLOSE))
            {
                if (auto arg = parse_expr(lexer, ctx))
                {
                    args.push_back(std::move(arg));
                }
                else
                {
                    return nullptr;
                }

                if (lexer.curr_token().is(token::TOK_PAREN_CLOSE))
                {
                    break;
                }

                if (!lexer.curr_token().is(token::TOK_COMMA))
                    report_error_point(lexer, "expected ')' or ',' in argument list");
                lexer.consume();
            }

            expr = std::make_unique<function_call_expr>(begin, lexer.curr_token().end_location(), std::move(expr), std::move(args));
            lexer.consume();
        }
        else if (lexer.curr_token().is(token::TOK_BRACKET_OPEN))
        {
            // TODO: implement
            __builtin_unreachable();
            /*
            std::vector<ast_ref> args;
            l.consume();
            while (1)
            {
                if (auto arg = parse_expr(l, ctx))
                    args.push_back(std::move(arg));
                else
                    return nullptr;

                if (l.curr_token().is(token::TOK_PAREN_CLOSE))
                    break;

                if (l.curr_token().is(token::TOK_COMMA))
                    report_error_point(l, "expected ')' or ',' in argument list");
                l.consume();
            }

            expr = std::make_unique<function_call_expr>(begin, l.curr_token().end_location(), std::move(expr), std::move(args));
            l.consume();*/
        }
    }

    return expr;
}

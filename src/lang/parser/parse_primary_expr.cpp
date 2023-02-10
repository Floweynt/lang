#include "lang/ast/functional_call_expr_ast.h"
#include "lang/lexer/token.h"
#include "parser_util.h"
#include <lang/parser/parser.h>

template <typename T>
static ast_ref parse_literal_expr(lexer& l, compiler_context& ctx)
{
    const auto& value = l.curr_token().get_value<literal_value<T>>();
    auto ret = std::make_unique<literal_expr<T>>(curr_token_loc(l), value.value, value.literal_specifier);
    l.consume();
    return std::move(ret);
}

static ast_ref simple_parse_primary_expr(lexer& l, compiler_context& ctx)
{
    switch (l.curr_token().type())
    {
    default:
        report_error_point(l, "expected primary expression");
    case token::TOK_IDENTIFIER:
        return parse_identifier_expr(l, ctx);
    case token::TOK_LANG_IDENTIFIER:
        return parse_lang_identifier_expr(l, ctx);
    case token::TOK_INTEGER:
        return parse_literal_expr<intmax_t>(l, ctx);
    case token::TOK_FLOATING:
        return parse_literal_expr<long double>(l, ctx);
    case token::TOK_STRING:
        return parse_literal_expr<std::string>(l, ctx);
    case token::TOK_CHAR:
        return parse_char_literal_expr(l, ctx);
    case token::TOK_PAREN_OPEN:
        return parse_paren_expr(l, ctx);
    case token::TOK_BKSLASH:
        return parse_lambda_expr(l, ctx);
    case token::TOK_KW_IF:
        return parse_if_expr(l, ctx);
    case token::TOK_KW_YIELD:
        return parse_yield_expr(l, ctx);
    case token::TOK_KW_RETURN:
        return parse_return_expr(l, ctx);
    }
}

ast_ref parse_primary_expr(lexer& l, compiler_context& ctx)
{
    auto begin = l.curr_token().location();
    auto expr = simple_parse_primary_expr(l, ctx);
    if (!expr)
        return nullptr;

    while (l.curr_token().is(token::TOK_PAREN_OPEN) || l.curr_token().is(token::TOK_BRACKET_OPEN))
    {
        if (l.curr_token().is(token::TOK_PAREN_OPEN))
        {
            std::vector<ast_ref> args;
            l.consume();
            while (!l.curr_token().is(token::TOK_PAREN_CLOSE))
            {
                if (auto arg = parse_expr(l, ctx))
                    args.push_back(std::move(arg));
                else
                    return nullptr;

                if (l.curr_token().is(token::TOK_PAREN_CLOSE))
                    break;

                if (!l.curr_token().is(token::TOK_COMMA))
                    report_error_point(l, "expected ')' or ',' in argument list");
                l.consume();
            }

            expr = std::make_unique<function_call_expr>(begin, l.curr_token().end_location(), std::move(expr), std::move(args));
            l.consume();
        }
        else if (l.curr_token().is(token::TOK_BRACKET_OPEN))
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

#include "lang/ast/base_ast.h"
#include "lang/attribute_ast.h"
#include "lang/lexer/lexer.h"
#include "lang/lexer/token.h"
#include "lang/parser/parser.h"
#include "parser_util.h"

static auto parse_attribute_entry(lexer& lexer, compiler_context& ctx) -> ast_ref
{
    auto start = lexer.curr_token().location();
    std::string name = lexer.curr_token().identifier();

    if (lexer.curr_token().is(token::TOK_PAREN_OPEN))
    {
        lexer.consume();
        std::vector<ast_ref> args;

        while (true)
        {
            if (auto arg = parse_expr(lexer, ctx))
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

        auto end = lexer.curr_token().end_location();
        lexer.consume();

        return std::make_unique<attribute_entry_stmt>(start, end, name, std::move(args));
    }

    auto entry = std::make_unique<attribute_entry_stmt>(start, lexer.curr_token().end_location(), name, std::vector<ast_ref>());
    lexer.consume();
    return entry;
}

auto parse_attribute_list(lexer& lexer, compiler_context& ctx) -> ast_ref
{
    auto start = lexer.curr_token().location();
    lexer.consume();
    std::vector<ast_ref> attributes;

    while (true)
    {
        attributes.push_back(parse_attribute_entry(lexer, ctx));

        if (lexer.curr_token().is(token::TOK_ATTR_CLOSE))
        {
            break;
        }

        if (!lexer.curr_token().is(token::TOK_COMMA))
            report_error_point(lexer, "expected ',' in attribute list");
    }

    auto end = lexer.curr_token().end_location();
    lexer.consume();

    return std::make_unique<attribute_list_stmt>(start, end, std::move(attributes));
}

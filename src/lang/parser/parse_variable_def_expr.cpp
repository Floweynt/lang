#include "lang/ast/keyword_ast.h"
#include "lang/ast/variable_decl_expr_ast.h"
#include "lang/lexer/code_location.h"
#include "parser_util.h"
#include <lang/parser/parser.h>

auto parse_variable_def_expr(lexer& lexer, compiler_context& ctx) -> ast_ref
{
    // we must consume modifiers
    std::vector<ast_ref> modifiers;

    auto start = lexer.curr_token().location();

    if (lexer.curr_token().is(token::TOK_KW_CONSTEVAL))
    {
        lexer.consume();
        modifiers.push_back(std::make_unique<consteval_kw>(curr_token_loc(lexer)));
    }
    else
    {
        if (lexer.curr_token().is(token::TOK_KW_COMPTIME))
        {
            lexer.consume();
            modifiers.push_back(std::make_unique<consteval_kw>(curr_token_loc(lexer)));
        }

        if (lexer.curr_token().is(token::TOK_KW_CONST))
        {
            lexer.consume();
            modifiers.push_back(std::make_unique<const_kw>(curr_token_loc(lexer)));
        }
        else if (lexer.curr_token().is(token::TOK_KW_VAR))
        {
            lexer.consume();
            modifiers.push_back(std::make_unique<var_kw>(curr_token_loc(lexer)));
        }
    }

    if (!lexer.curr_token().is(token::TOK_IDENTIFIER))
        report_error_point(lexer, "expected variable name");

    auto name = lexer.curr_token().identifier();
    code_location end = lexer.curr_token().end_location();

    lexer.consume();

    bool is_packed = false;
    if (lexer.curr_token().is(token::TOK_ELLIPSIS))
    {
        is_packed = true;
        lexer.consume();
    }

    ast_ref type;

    if (lexer.curr_token().is(token::TOK_COLON))
    {
        lexer.consume();
        type = parse_type_expr(lexer, ctx);
        end = type->get_end();
    }

    ast_ref init = nullptr;

    if (lexer.curr_token() == token::OP_ASSIGN)
    {
        lexer.consume();
        init = parse_expr(lexer, ctx);
        if (!init)
        {
            return nullptr;
        }
        end = init->get_end();
    }

    return std::make_unique<variable_decl_expr>(start, end, name, std::move(modifiers), std::move(type), std::move(init), is_packed);
}

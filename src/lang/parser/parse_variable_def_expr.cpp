#include "parser_util.h"
#include <lang/parser/parser.h>

ast_ref parse_variable_def_expr(lexer& l, compiler_context& ctx)
{
    // we must consume modifiers
    std::vector<ast_ref> modifiers;

    auto start = l.curr_token().location();

    if (l.curr_token().is(token::TOK_KW_CONSTEVAL))
    {
        l.consume();
        modifiers.push_back(std::make_unique<consteval_kw>(curr_token_loc(l)));
    }
    else
    {
        if (l.curr_token().is(token::TOK_KW_COMPTIME))
        {
            l.consume();
            modifiers.push_back(std::make_unique<consteval_kw>(curr_token_loc(l)));
        }

        if (l.curr_token().is(token::TOK_KW_CONST))
        {
            l.consume();
            modifiers.push_back(std::make_unique<const_kw>(curr_token_loc(l)));
        }
        else if (l.curr_token().is(token::TOK_KW_VAR))
        {
            l.consume();
            modifiers.push_back(std::make_unique<var_kw>(curr_token_loc(l)));
        }
    }

    if (!l.curr_token().is(token::TOK_IDENTIFIER))
        report_error_point(l, "expected variable name");

    auto name = l.curr_token().identifier();
    l.consume();

    bool is_packed = false;
    if (l.curr_token().is(token::TOK_ELLIPSIS))
    {
        is_packed = true;
        l.consume();
    }

    if (!l.curr_token().is(token::TOK_COLON))
        report_error_point(l, "expected ':' in variable definition");
    l.consume();

    auto type = parse_type_expr(l, ctx);

    auto end = type->get_end();

    ast_ref init = nullptr;

    if (l.curr_token() == token::OP_ASSIGN)
    {
        l.consume();
        init = parse_expr(l, ctx);
        if(!init)
            return nullptr;
        end = init->get_end();
    }

    return std::make_unique<variable_decl_expr>(start, end, name, std::move(modifiers), std::move(type), std::move(init), is_packed);
}

#include "parser_util.h"
#include <lang/parser/parser.h>

auto parse_type_expr(lexer& lexer, compiler_context& ctx) -> ast_ref
{
    if (lexer.curr_token().type() == token::TOK_KW_AUTO)
    {
        lexer.consume();
        return std::make_unique<auto_kw>(curr_token_loc(lexer));
    }
    return parse_unary_expr(lexer, ctx);
}

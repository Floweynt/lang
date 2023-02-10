#include "parser_util.h"
#include <lang/parser/parser.h>

ast_ref parse_type_expr(lexer& l, compiler_context& ctx)
{
    if (l.curr_token().type() == token::TOK_KW_AUTO)
    {
        l.consume();
        return std::make_unique<auto_kw>(curr_token_loc(l));
    }
    return parse_unary_expr(l, ctx);
}

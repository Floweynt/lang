#include "parser_util.h"
#include <lang/parser/parser.h>

ast_ref parse_char_literal_expr(lexer& l, compiler_context& ctx)
{
    auto ret = std::make_unique<char_literal_expr>(curr_token_loc(l), l.curr_token().get_value<char>());
    l.consume();
    return std::move(ret);
}

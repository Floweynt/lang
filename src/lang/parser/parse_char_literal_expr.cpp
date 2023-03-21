#include "parser_util.h"
#include "lang/ast/char_literal_expr_ast.h"
#include <lang/parser/parser.h>

auto parse_char_literal_expr(lexer& lexer, compiler_context& /*ctx*/) -> ast_ref
{
    auto ret = std::make_unique<char_literal_expr>(curr_token_loc(lexer), lexer.curr_token().get_value<char>());
    lexer.consume();
    return std::move(ret);
}

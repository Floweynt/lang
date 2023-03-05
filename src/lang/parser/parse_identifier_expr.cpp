#include "parser_util.h"
#include <lang/parser/parser.h>

auto parse_identifier_expr(lexer& lexer, compiler_context& ctx) -> ast_ref
{
    auto start = lexer.curr_token().location();
    std::string id_name = lexer.curr_token().identifier();

    lexer.consume();
    return parse_post_identifier(lexer, ctx, std::make_unique<name_ref_expr>(start, lexer.curr_token().end_location(), id_name));
}

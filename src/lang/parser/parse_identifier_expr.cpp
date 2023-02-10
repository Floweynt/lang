#include "parser_util.h"
#include <lang/parser/parser.h>

ast_ref parse_identifier_expr(lexer& l, compiler_context& ctx)
{
    auto start = l.curr_token().location();
    std::string id_name = l.curr_token().identifier();

    l.consume();
    return std::make_unique<name_ref_expr>(start, l.curr_token().end_location(), id_name);
}

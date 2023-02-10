#include <lang/parser/parser.h>

ast_ref parse_lang_identifier_expr(lexer& l, compiler_context& ctx)
{
    auto tok = l.curr_token();
    l.consume();
    return std::make_unique<lang_name_ref_expr>(tok.location(), tok.end_location(), tok.identifier());
}

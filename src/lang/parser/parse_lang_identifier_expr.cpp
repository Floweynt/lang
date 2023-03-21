#include "lang/ast/lang_name_ref_expr_ast.h"
#include <lang/parser/parser.h>

auto parse_lang_identifier_expr(lexer& lexer, compiler_context& ctx) -> ast_ref
{
    auto tok = lexer.curr_token();
    lexer.consume();
    return parse_post_identifier(lexer, ctx, std::make_unique<lang_name_ref_expr>(tok.location(), tok.end_location(), tok.identifier()));
}

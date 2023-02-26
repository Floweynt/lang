#include "parser_util.h"
#include <lang/parser/parser.h>

auto expect_semi(ast_ref ref, lexer& lexer, compiler_context& ctx) -> ast_ref
{
    if (!lexer.curr_token().is(token::TOK_SEMICOLON))
        report_error_point(lexer, "expected semicolon at the end of a statement");
    lexer.consume();
    return ref;
}

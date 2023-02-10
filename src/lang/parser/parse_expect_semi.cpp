#include "parser_util.h"
#include <lang/parser/parser.h>

ast_ref expect_semi(ast_ref r, lexer& l, compiler_context& ctx)
{
    if (!l.curr_token().is(token::TOK_SEMICOLON))
        report_error_point(l, "expected semicolon at the end of a statement");
    l.consume();
    return r;
}

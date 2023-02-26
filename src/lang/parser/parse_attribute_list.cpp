#include "lang/ast/base_ast.h"
#include "lang/lexer/lexer.h"
#include "lang/lexer/token.h"
#include "parser_util.h"

auto parse_attribute_list(lexer& lexer, compiler_context& ctx) -> ast_ref
{
    lexer.consume();

    // we must parse an identifier based ast
    if (!lexer.curr_token().is(token::TOK_IDENTIFIER))
    {
        report_error_point(lexer, "expected identifier in attribute list");
    }
}

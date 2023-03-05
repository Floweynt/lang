#include "lang/ast/base_ast.h"
#include "lang/ast/name_ref_expr_ast.h"
#include "lang/ast/namespaced_name_ref_expr_ast.h"
#include "lang/lexer/lexer.h"
#include "lang/lexer/token.h"
#include "lang/parser/parser.h"
#include "parser_util.h"
#include <memory>
#include <type_traits>

auto parse_post_identifier(lexer& lexer, compiler_context& ctx, ast_ref ref) -> ast_ref
{
    ast_ref current = std::move(ref);

    while (lexer.curr_token().is(token::TOK_DOUBLECOLON))
    {
        lexer.consume();
        if (!lexer.curr_token().is(token::TOK_IDENTIFIER))
            report_error_point(lexer, "expected identifier");

        current = std::make_unique<namespaced_name_ref_expr>(
            std::move(current),
            std::make_unique<name_ref_expr>(lexer.curr_token().location(), lexer.curr_token().end_location(), lexer.curr_token().identifier()));
        lexer.consume();
    }

    return current;
}

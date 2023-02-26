#include "lang/ast/struct_literal_expr.h"
#include "lang/compiler_context.h"
#include "lang/lexer/token.h"
#include "parser_util.h"
#include <lang/parser/parser.h>
#include <memory>

auto parse_struct_literal_expr(lexer& lexer, compiler_context& ctx) -> ast_ref
{
    auto start = lexer.curr_token().location();
    lexer.consume();

    if (!lexer.curr_token().is(token::TOK_BRACE_OPEN))
        report_error_point(lexer, "expected '{' for struct literal");
    lexer.consume();

    std::vector<ast_ref> members;

    while (!lexer.curr_token().is(token::TOK_BRACE_CLOSE))
    {
        auto decl = parse_variable_def_expr(lexer, ctx);
        if (!lexer.curr_token().is(token::TOK_SEMICOLON))
            report_error_point(lexer, "expected ';' at end of member-variable definition");
        lexer.consume();

        members.push_back(std::move(decl));
    }
    auto end = lexer.curr_token().end_location();
    lexer.consume();
    return std::make_unique<struct_literal_expr>(start, end, std::move(members));
}

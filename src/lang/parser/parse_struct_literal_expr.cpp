#include "lang/ast/struct_literal_expr.h"
#include "lang/compiler_context.h"
#include "lang/lexer/token.h"
#include "parser_util.h"
#include <lang/parser/parser.h>
#include <memory>

ast_ref parse_struct_literal_expr(lexer& l, compiler_context& ctx)
{
    auto start = l.curr_token().location();
    l.consume();

    if (!l.curr_token().is(token::TOK_BRACE_OPEN))
        report_error_point(l, "expected '{' for struct literal");
    l.consume();

    std::vector<ast_ref> members;

    while (!l.curr_token().is(token::TOK_BRACE_CLOSE))
    {
        auto decl = parse_variable_def_expr(l, ctx);
        if (!l.curr_token().is(token::TOK_SEMICOLON))
            report_error_point(l, "expected ';' at end of member-variable definition");
        l.consume();

        members.push_back(std::move(decl));
    }
    auto end = l.curr_token().end_location();
    l.consume();
    return std::make_unique<struct_literal_expr>(start, end, std::move(members));
}

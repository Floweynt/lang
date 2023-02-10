#include "lang/ast/block_expr_ast.h"
#include "parser_util.h"
#include <lang/parser/parser.h>

ast_ref parse_block_expr(lexer& l, compiler_context& ctx)
{
    auto start = l.curr_token().location();
    l.consume();
    std::vector<ast_ref> statements;

    while (!l.curr_token().is(token::TOK_BRACE_CLOSE))
    {
        auto stmt = parse_expr_as_statement(l, ctx);
        if (!stmt)
            return nullptr;
        statements.push_back(std::move(stmt));
    }

    auto end = l.curr_token().location();
    l.consume();

    return std::make_unique<block_expr>(start, end, std::move(statements));
}

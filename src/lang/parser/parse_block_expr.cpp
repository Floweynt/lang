#include "lang/ast/block_expr_ast.h"
#include "parser_util.h"
#include <lang/parser/parser.h>

auto parse_block_expr(lexer& lexer, compiler_context& ctx) -> ast_ref
{
    auto start = lexer.curr_token().location();
    lexer.consume();
    std::vector<ast_ref> statements;

    while (!lexer.curr_token().is(token::TOK_BRACE_CLOSE))
    {
        auto stmt = parse_expr_as_statement(lexer, ctx);
        if (!stmt)
        {
            return nullptr;
        }
        statements.push_back(std::move(stmt));
    }

    auto end = lexer.curr_token().location();
    lexer.consume();

    return std::make_unique<block_expr>(start, end, std::move(statements));
}

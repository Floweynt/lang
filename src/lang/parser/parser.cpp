#include "lang/ast/top_level_blk_ast.h"
#include <lang/parser/parser.h>

auto parse(lexer& lexer, compiler_context& ctx) -> ast_ref
{
    try
    {
        std::vector<ast_ref> statements;
        auto start = lexer.curr_token().location();

        while (!lexer.curr_token().is(token::TOK_EOF))
        {
            auto stmt = parse_top_level_stmt(lexer, ctx);
            if (!stmt)
            {
                return nullptr;
            }
            statements.push_back(std::move(stmt));
        }

        if (statements.empty())
        {
            return nullptr;
        }

        return std::make_unique<top_level_blk>(start, statements.back()->get_end(), std::move(statements));
    }
    catch (lexer_error)
    {
        return nullptr;
    }
}

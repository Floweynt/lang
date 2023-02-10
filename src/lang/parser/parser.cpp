#include <lang/parser/parser.h>

ast_ref parse(lexer& l, compiler_context& c)
{
    try
    {
        std::vector<ast_ref> statements;
        auto start = l.curr_token().location();

        while (!l.curr_token().is(token::TOK_EOF))
        {
            auto stmt = parse_top_level_stmt(l, c);
            if (!stmt)
                return nullptr;
            statements.push_back(std::move(stmt));
        }

        if (statements.empty())
            return nullptr;

        return std::make_unique<top_level_blk>(start, statements.back()->get_end(), std::move(statements));
    }
    catch (lexer_error)
    {
        return nullptr;
    }
}

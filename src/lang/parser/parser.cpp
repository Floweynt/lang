#include "lang/parser/parser.h"
#include "lang/ast/base_ast.h"
#include "lang/ast/module_ast.h"
#include "lang/ast/top_level_blk_ast.h"
#include "lang/compiler_context.h"
#include "lang/lexer/token.h"
#include "parser_util.h"
#include <memory>

static auto parse_module(lexer& lexer, compiler_context& ctx) -> ast_ref
{
    auto start = lexer.curr_token().location();
    std::vector<std::vector<std::string>> module_imports;

    while (lexer.curr_token().is(token::TOK_KW_IMPORT))
    {
        lexer.consume();

        if (!lexer.curr_token().is(token::TOK_STRING))
            report_error_point(lexer, "import keyword should be followed by string representing path-to-file");
        lexer.consume();

        std::vector<std::string> path_segments;

        do
        {
            if (!lexer.curr_token().is(token::TOK_IDENTIFIER))
                report_error_point(lexer, "expected identifier in import statement; import statement should be of format 'import path.to.module'");
            path_segments.push_back(lexer.curr_token().identifier());
            lexer.consume();

            if (lexer.curr_token().is(token::TOK_SEMICOLON))
            {
                break;
            }

            if (!lexer.curr_token().is(token::TOK_OPERATOR) || lexer.curr_token() == token::OP_MEMBER)
                report_error_point(lexer, "expected dot after identifier; import statement should be of format 'import path.to.module'");
            lexer.consume();
        } while (true);

        lexer.consume();
        module_imports.emplace_back(std::move(path_segments));
    }

    auto stmt_start = lexer.curr_token().location();
    std::vector<ast_ref> statements;

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

    auto block = std::make_unique<top_level_blk>(stmt_start, statements.back()->get_end(), std::move(statements));
    auto module = std::make_unique<module_ast>(start, block->get_end(), std::move(module_imports), std::move(block));
    return module;
}

auto parse(lexer& lexer, compiler_context& ctx) -> ast_ref
{
    try
    {
        return parse_module(lexer, ctx);
    }
    catch (lexer_error)
    {
        return nullptr;
    }
}

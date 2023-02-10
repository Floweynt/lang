#include "parser_util.h"
#include <lang/parser/parser.h>

ast_ref parse_namespace_stmt(lexer& l, compiler_context& ctx)
{
    auto start = l.curr_token().location();
    l.consume();
    std::vector<std::string> ns_path;

    while (true)
    {
        if (!l.curr_token().is(token::TOK_IDENTIFIER))
            report_error_point(l, "expected identifier");
        ns_path.push_back(l.curr_token().identifier());

        l.consume();

        if (l.curr_token() != token::OP_NS)
            break;
    }

    if (!l.curr_token().is(token::TOK_BRACE_OPEN))
        report_error_point(l, "expected '{' after namespace decleration to create scoped block");

    std::vector<ast_ref> block;
    l.consume();
    while (!l.curr_token().is(token::TOK_BRACE_CLOSE))
    {
        auto stmt = parse_top_level_stmt(l, ctx);
        if (!stmt)
            return nullptr;
        block.push_back(std::move(stmt));
    }

    auto end = l.curr_token().end_location();
    l.consume();

    return std::make_unique<namespace_stmt>(start, end, std::move(ns_path), std::move(block));
}

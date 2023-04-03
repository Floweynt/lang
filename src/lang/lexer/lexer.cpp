#include "lang/lexer/lexer.h"
#include <magic_enum.hpp>

auto lex_tok(lex_context& ctx) -> token;

lexer::lexer(compiler_context& ctx) : my_context({ctx.io(), {}, 0, 0, 1, 1, 0, 1, 1, ctx}), tok(lex_tok(my_context)), index()
{
    prev_tokens.push_back(tok);
}

void lexer::consume()
{
    tok = lex_tok(my_context);
    prev_tokens.push_back(tok);
}

auto lexer::curr_token() -> const token& { return tok; }

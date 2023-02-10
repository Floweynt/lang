#include <lang/lexer/lexer.h>

auto lex_tok(lex_context& ctx) -> token;

lexer::lexer(compiler_context& ctx) : my_context({ctx.io(), 1, 1, 0, {}, true, ctx}), tok(lex_tok(my_context)) {}

void lexer::consume() { tok = lex_tok(my_context); }
const token& lexer::curr_token() { return tok; }

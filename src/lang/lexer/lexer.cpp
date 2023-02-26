#include <lang/lexer/lexer.h>
#include <magic_enum.hpp>

auto lex_tok(lex_context& ctx) -> token;

lexer::lexer(compiler_context& ctx) : my_context({ctx.io(), {}, 0, 0, 1, 1, 0, 1, 1, ctx}), tok(lex_tok(my_context)), index()
{
    std::cout << fmt::format("tok_debug: {} ({}:{} - {}:{})\n", magic_enum::enum_name(tok.type()), tok.location().line, tok.location().col,
                             tok.end_location().line, tok.end_location().col);
}

void lexer::consume()
{
    tok = lex_tok(my_context);
    std::cout << fmt::format("tok_debug: {} ({}:{} - {}:{})\n", magic_enum::enum_name(tok.type()), tok.location().line, tok.location().col,
                             tok.end_location().line, tok.end_location().col);
}
auto lexer::curr_token() -> const token& { return tok; }

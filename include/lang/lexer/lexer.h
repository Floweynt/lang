#pragma once

#include "token.h"
#include <lang/compiler_context.h>
#include <queue>
#include <stdexcept>

struct lex_context
{
    std::istream& in;
    std::deque<char> buffer;
    size_t peek_index;

    size_t bytes, col, line;
    size_t pbytes, pcol, pline;

    compiler_context& ctx;
};

class lexer_error
{
};

class lexer
{
    lex_context my_context;
    token tok;
    size_t index;

    std::vector<token> prev_tokens;

public:
    lexer(compiler_context& ctx);
    void consume();
    auto curr_token() -> const token&;

    [[nodiscard]] constexpr auto get_prev_tokens() const -> const auto& { return prev_tokens; }
};

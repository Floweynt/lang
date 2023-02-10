#pragma once

#include "token.h"
#include <lang/compiler_context.h>
#include <queue>
#include <stdexcept>

struct lex_context
{
    std::istream& in;
    size_t line, col, bytes;
    std::vector<char> buffer;
    bool should_consume_new_ch;

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

public:
    lexer(compiler_context& ctx);
    void consume();
    const token& curr_token();
};

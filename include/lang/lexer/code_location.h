#pragma once

#include <cstddef>

struct code_location
{
    size_t line, col, bytes;
};

struct code_range
{
    code_location start;
    code_location end;
};

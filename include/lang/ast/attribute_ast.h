#pragma once

#include "lang/ast/base_ast.h"

class attribute_entry_ast : base_ast
{
    std::string name;
    std::vector<ast_ref> args;

public:
};

class attribute_ast
{
};

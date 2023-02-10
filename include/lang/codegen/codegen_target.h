#pragma once
#include <llvm/IR/Value.h>

class codegen_target
{
public:
    virtual llvm::Value do_codegen() = 0;
    virtual ~codegen_target() = default;
};

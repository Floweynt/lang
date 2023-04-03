#pragma once

#include <llvm/IR/Value.h>

class codegen_target
{
public:
    virtual auto do_codegen() -> llvm::Value = 0;
    virtual ~codegen_target() = default;
};

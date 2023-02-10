#pragma once
#include "lang/compiler_context.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
// this context contains some duplicate info in relation to sema_ctx

class codegen_ctx
{
    llvm::LLVMContext my_llvm_ctx;
    llvm::IRBuilder<> ir_builder;
    std::unique_ptr<llvm::Module> curr_module;
    compiler_context& compiler_ctx;

public:
    codegen_ctx(compiler_context& ctx) : ir_builder(my_llvm_ctx), compiler_ctx(ctx) {}

    constexpr auto& llvm_ctx() { return my_llvm_ctx; }
    constexpr auto& builder() { return ir_builder; }
    constexpr auto& module() { return *curr_module; }
    constexpr auto& get_ctx() { return compiler_ctx; }
};

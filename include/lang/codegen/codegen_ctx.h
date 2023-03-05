#pragma once
#include "lang/codegen/codegen_ctx.h"
#include "lang/compiler_context.h"
#include "lang/sema/sema_ctx.h"
#include "lang/sema/types.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include <concepts>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/NoFolder.h>
#include <llvm/IR/Value.h>
#include <memory>
// this context contains some duplicate info in relation to sema_ctx

class codegen_value;

// this the "context" passed into all of codegen, representing the state of the code generation
class codegen_ctx
{
    // standard LLVM
    llvm::LLVMContext my_llvm_ctx;
    llvm::IRBuilder<> ir_builder;
    std::unique_ptr<llvm::Module> curr_module;

    // cached void type
    llvm::StructType* unit_ty;

    // we need to keep some info the the semantic analysis stage
    const sema_ctx& ctx;

    // current namespace, composed of `curr_namespace.size()` entries
    std::vector<std::string> curr_namespace;

    // the current list of variables of some scope
    std::deque<std::pair<std::unordered_map<std::string, codegen_value>, bool>> scoped_vars;

    // the return type of the first function one would encounter by going up the AST
    type_descriptor func_return_ty;

public:
    codegen_ctx(sema_ctx& ctx);
    constexpr auto llvm_ctx() -> auto& { return my_llvm_ctx; }
    constexpr auto builder() -> auto& { return ir_builder; }
    constexpr auto module() -> auto& { return *curr_module; }
    constexpr auto get_sema_ctx() -> auto& { return ctx; }
    [[nodiscard]] constexpr auto get_unit_ty() const { return unit_ty; }

    [[nodiscard]] constexpr auto get_func_return_ty() const { return func_return_ty; }
    [[nodiscard]] constexpr auto set_func_return_ty(type_descriptor ty) { func_return_ty = ty; }

    inline auto get_primitive(primitive_type::kind type) { this->get_sema_ctx().langtype(type)->get_llvm_type(*this); }
    auto get_void_val() -> codegen_value;

    void push_local_stack();
    void pop_local_stack();

    void push_namespace_stack(const std::vector<std::string>& str);
    void pop_namespace_stack(size_t n);

    auto get_variable(const std::string& str) -> codegen_value;
    void add_variable(const std::string& str, const codegen_value& desc);

    auto convert_to(type_descriptor target, const codegen_value& from) -> codegen_value;

    // builder helpers
    inline auto get_insert_block() { return builder().GetInsertBlock(); }
    inline void set_insert_block(llvm::BasicBlock* block) { builder().SetInsertPoint(block); }
    inline auto parent_function() { return get_insert_block()->getParent(); }

    inline auto make_new_block(const std::string& name = "") -> llvm::BasicBlock*
    {
        return llvm::BasicBlock::Create(llvm_ctx(), name, parent_function());
    }

    inline auto insert_to_new_block(const std::string& name = "") -> llvm::BasicBlock*
    {
        auto* block = make_new_block(name);
        set_insert_block(block);
        return block;
    }

    inline auto insert_to(llvm::BasicBlock* target, const std::invocable<codegen_ctx&> auto& func)
    {
        auto* prev = get_insert_block();
        set_insert_block(target);
        func(*this);
        set_insert_block(prev);
    }
};

#pragma once

#include "lang/ast/base_ast.h"
#include "lang/ast/variable_decl_expr_ast.h"
#include "lang/codegen/codegen_ctx.h"
#include "lang/codegen/codegen_value.h"
#include "lang/sema/types.h"
#include <llvm/IR/GlobalValue.h>
#include <llvm/IR/Verifier.h>

inline auto do_codegen_func(codegen_ctx& context, llvm::GlobalValue::LinkageTypes linkage, const std::string& name, type_descriptor this_ty,
                            const std::vector<ast_ref>& args, const ast_ref& body, bool is_lambda) -> codegen_value
{
    auto* parent = context.get_insert_block();
    context.push_local_stack();
    const auto* parent_ret_ty = context.get_func_return_ty();

    context.set_func_return_ty(dynamic_cast<const trivial_function_type*>(this_ty)->get_return_ty());

    llvm::Function* fn = llvm::Function::Create((llvm::FunctionType*)(this_ty->get_llvm_type(context)), linkage, name, context.module());

    llvm::BasicBlock* block = llvm::BasicBlock::Create(context.llvm_ctx(), "func_entry", fn);
    context.set_insert_block(block);

    // we need to initialize the arg variables
    for (auto& value : fn->args())
    {
        const auto* arg_ty = args[value.getArgNo()].get()->get_sema_result().ty;
        const auto& name = dynamic_cast<variable_decl_expr*>(args[value.getArgNo()].get())->get_name();
        auto var = codegen_value::make_local(context, arg_ty, codegen_value::make_constant(arg_ty, &value), "param_" + name);
        context.add_variable(name, var);
        value.setName("p_" + name);
    }

    // we do not care about the body's value
    (void)body->codegen(context);

    if (context.get_insert_block()->getTerminator() == nullptr)
    {
        if (dynamic_cast<const trivial_function_type*>(this_ty)->get_return_ty() == context.get_sema_ctx().langtype(primitive_type::UNIT))
        {
            context.builder().CreateRet(context.get_void_val().get_value(context));
        }
        else
        {
            context.builder().CreateUnreachable();
        }
    }

    context.set_func_return_ty(parent_ret_ty);
    context.pop_local_stack();
    context.set_insert_block(parent);

    if (llvm::verifyFunction(*fn, &llvm::errs()))
    {
        // TODO: handle codegen failrues safely
    }

    if (!is_lambda)
    {
        context.add_variable(name, codegen_value::make_constant(this_ty, fn));
    }

    return codegen_value::make_constant(this_ty, fn);
}

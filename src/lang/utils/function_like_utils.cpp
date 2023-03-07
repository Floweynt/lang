#pragma once

#include "lang/ast/base_ast.h"
#include "lang/ast/block_expr_ast.h"
#include "lang/ast/control/return_expr_ast.h"
#include "lang/ast/variable_decl_expr_ast.h"
#include "lang/codegen/codegen_ctx.h"
#include "lang/codegen/codegen_value.h"
#include "lang/sema/sema_ctx.h"
#include "lang/sema/types.h"
#include "lang/utils/utils.h"
#include <llvm/IR/Function.h>
#include <llvm/IR/GlobalValue.h>
#include <llvm/IR/Verifier.h>

auto do_sema_func(sema_ctx& context, const std::vector<ast_ref>& args, const ast_ref& body, const ast_ref& return_type, const std::string& name)
    -> semantic_analysis_result
{
    std::vector<type_descriptor> arg_types;
    bool is_valid = false;
    bool should_fail = false;

    auto& parent_scope = context.get_current_scope();

    context.push_local_stack();
    for (const auto& arg : args)
    {
        auto [arg_type, valid, _, _] = arg->semantic_analysis(context);
        arg_types.push_back(arg_type);

        if (arg_type == context.langtype(primitive_type::ERROR))
        {
            should_fail = true;
        }
        is_valid &= valid;
    }

    type_descriptor return_ty = nullptr; // this should be deduced

    bool body_valid = true;

    if (return_type)
    {
        auto [return_type_specifier_ty, return_type_valid, can_consteval, _] = return_type->semantic_analysis(context);

        if (return_type_specifier_ty != context.langtype(primitive_type::META))
        {
            context.get_compiler_ctx().report_diagnostic({
                {return_type->range(), "type specifier must refer to a type (the expressions should have type 'metatype', but got \'" +
                                           return_type_specifier_ty->get_name() + "\')"},
                std::nullopt,
            });

            return {context.make_simple_lambda_function(context.langtype(primitive_type::ERROR), arg_types), false};
        }

        if (!can_consteval)
        {
            throw std::runtime_error("internal error: meta type must be consteval");
        }

        return_ty = return_type->compiler_eval(context).get_value<type_descriptor>();

        if (!name.empty())
        {
            parent_scope.get_vars()[name] = context.make_simple_lambda_function(return_ty, arg_types);
        }

        body_valid = body->semantic_analysis(context).is_valid;
        context.pop_local_stack();

        struct visitor
        {
            sema_ctx& context;
            type_descriptor return_ty;
            bool valid;

            void operator()(const base_ast& ast)
            {
                if (ast.get_ast_kind() == RETURN_EXPR)
                {
                    const auto* returned_ty = dynamic_cast<const return_expr&>(ast).get_value()->get_sema_result().ty;
                    if (!context.exists_conversion(returned_ty, return_ty) && returned_ty != context.langtype(primitive_type::ERROR))
                    {
                        valid = false;
                        context.get_compiler_ctx().report_diagnostic({
                            {ast.range(), "type returned '" + returned_ty->get_name() + "' cannot be converted to specified return type of '" +
                                              return_ty->get_name() + "'"},
                        });
                    }
                }
                else
                {
                    ast.visit_children(*this);
                }
            }
        };

        visitor my_visitor{context, return_ty, true};
        my_visitor(*body);

        if (!my_visitor.valid)
        {
            body_valid = false;
        }
    }
    else
    {
        if (!name.empty())
        {
            parent_scope.get_vars()[name] = context.langtype(primitive_type::UNDEDUCED);
        }

        body_valid = body->semantic_analysis(context).is_valid;
        context.pop_local_stack();

        return_ty = dynamic_cast<block_expr*>(body.get())->deduce_return_type(context);
        if (return_ty == context.langtype(primitive_type::ERROR))
        {
            return {context.make_simple_lambda_function(return_ty, arg_types), false};
        }
    }

    if (!body_valid)
    {
        return {context.make_simple_lambda_function(return_ty, arg_types), false};
    }

    if (!name.empty())
    {
        context.set_variable(name, context.make_simple_lambda_function(return_ty, arg_types));
    }

    return {should_fail ? context.langtype(primitive_type::ERROR) : context.make_simple_lambda_function(return_ty, arg_types), is_valid};
}

auto do_codegen_func(codegen_ctx& context, llvm::GlobalValue::LinkageTypes linkage, const std::string& name, type_descriptor this_ty,
                     const std::vector<ast_ref>& args, const ast_ref& body, bool is_lambda) -> codegen_value
{
    auto* parent = context.get_insert_block();
    context.push_local_stack();
    const auto* parent_ret_ty = context.get_func_return_ty();

    context.set_func_return_ty(dynamic_cast<const trivial_function_type*>(this_ty)->get_return_ty());

    llvm::Function* func = nullptr;
    if ((func = context.module().getFunction(name)) == nullptr)
    {
        func = llvm::Function::Create((llvm::FunctionType*)(this_ty->get_llvm_type(context)), linkage, name, context.module());
    }

    llvm::BasicBlock* block = llvm::BasicBlock::Create(context.llvm_ctx(), "func_entry", func);
    context.set_insert_block(block);

    // we need to initialize the arg variables
    for (auto& value : func->args())
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

    if (llvm::verifyFunction(*func, &llvm::errs()))
    {
        // TODO: handle codegen failrues safely
    }

    if (!is_lambda)
    {
        context.add_variable(name, codegen_value::make_constant(this_ty, func));
    }

    return codegen_value::make_constant(this_ty, func);
}

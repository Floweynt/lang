#include "lang/ast/function_decl_stmt_ast.h"
#include "lang/ast/block_expr_ast.h"
#include "lang/ast/variable_decl_expr_ast.h"
#include "lang/codegen/codegen_ctx.h"
#include "lang/codegen/codegen_value.h"
#include "lang/sema/types.h"
#include <llvm/IR/Verifier.h>
#include <llvm/Support/raw_ostream.h>
#include <memory>
#include <optional>
#include <stdexcept>
#include <vector>

function_decl_stmt::function_decl_stmt(code_location start, code_location end, std::vector<ast_ref> args, ast_ref return_type, ast_ref body,
                                       std::string name)
    : base_ast(start, end, FUN_DECL_STMT), args(std::move(args)), return_type(std::move(return_type)), body(std::move(body)), name(std::move(name))
{
}

void function_decl_stmt::visit_children(const std::function<void(const base_ast&)>& consumer) const
{
    for (const auto& arg : args)
    {
        consumer(*arg);
    }
    if (return_type)
    {
        consumer(*return_type);
    }
    consumer(*body);
}

auto function_decl_stmt::do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result
{
    std::vector<type_descriptor> arg_types;
    bool is_valid = false;
    bool should_fail = false;
    for (const auto& arg : args)
    {
        auto [arg_type, valid, _] = arg->semantic_analysis(context);
        arg_types.push_back(arg_type);

        if (arg_type == context.langtype(primitive_type::ERROR))
        {
            should_fail = true;
        }
        is_valid &= valid;
    }

    type_descriptor return_ty = nullptr; // this should be deduced
    auto [_1, body_valid, _2] = body->semantic_analysis(context);

    if (return_type)
    {
        auto [return_type_specifier_ty, return_type_valid, _] = return_type->semantic_analysis(context);

        if (return_type_specifier_ty != context.langtype(primitive_type::ERROR))
        {
            context.get_compiler_ctx().report_error(error{
                return_type->range(),
                "type specifier must refer to a type (the expressions should have type 'metatype', but got \'" +
                    return_type_specifier_ty->get_name() + "\')",
                std::nullopt,
            });

            return {context.make_simple_lambda_function(context.langtype(primitive_type::ERROR), arg_types), false};
        }

        // TODO: evaluate
        // also, we must verify that the return type from block is converible to the specified return type
    }
    else
    {
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

    if(!should_fail)
    {
        context.add_variable(name, context.make_simple_lambda_function(return_ty, arg_types));
    }

    return {should_fail ? context.langtype(primitive_type::ERROR) : context.make_simple_lambda_function(return_ty, arg_types), is_valid};
}

auto function_decl_stmt::do_codegen(codegen_ctx& context) const -> codegen_value
{
    auto* parent = context.builder().GetInsertBlock();
    context.push_local_stack();

    llvm::Function* fn = llvm::Function::Create((llvm::FunctionType*)(get_sema_result().ty->get_llvm_type(context)),
                                                llvm::GlobalValue::ExternalLinkage, name, context.module());

    llvm::BasicBlock* block = llvm::BasicBlock::Create(context.llvm_ctx(), "", fn);
    context.builder().SetInsertPoint(block);

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

    if (dynamic_cast<const trivial_function_type*>(get_sema_result().ty)->get_return_ty() == context.get_sema_ctx().langtype(primitive_type::UNIT))
    {
        context.builder().CreateRet(context.get_void_val().get_value(context));
    }
    else if(block->getTerminator() == nullptr)
    {
        context.builder().CreateUnreachable();
    }

    context.pop_local_stack();
    context.add_variable(name, codegen_value::make_constant(get_sema_result().ty, fn));
    context.builder().SetInsertPoint(parent);

    if (llvm::verifyFunction(*fn, &llvm::errs()))
    {
        // throw std::runtime_error("internal error: codegen failed, function is invalid");
    }

    return codegen_value::make_constant(get_sema_result().ty, fn);
}

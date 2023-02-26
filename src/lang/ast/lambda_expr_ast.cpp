#include "lang/ast/lambda_expr_ast.h"
#include "lang/ast/block_expr_ast.h"
#include "lang/ast/variable_decl_expr_ast.h"
#include "lang/codegen/codegen_ctx.h"
#include "lang/sema/types.h"
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/GlobalValue.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/Verifier.h>
#include <memory>
#include <optional>
#include <vector>

lambda_expr::lambda_expr(code_location start, code_location end, std::vector<ast_ref> args, ast_ref return_type, ast_ref body)
    : base_ast(start, end, LAMBDA_EXPR), args(std::move(args)), return_type(std::move(return_type)), body(std::move(body))
{
}

void lambda_expr::visit_children(const std::function<void(const base_ast&)>& consumer) const
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

auto lambda_expr::do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result
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
        return_ty = dynamic_cast<block_expr&>(*body).deduce_return_type(context);
        if (return_ty == context.langtype(primitive_type::ERROR))
        {
            return {context.make_simple_lambda_function(return_ty, arg_types), false};
        }
    }

    if (!body_valid)
    {
        return {context.make_simple_lambda_function(return_ty, arg_types), false};
    }

    return {should_fail ? context.make_simple_lambda_function(return_ty, arg_types) : context.langtype(primitive_type::ERROR), is_valid};
}

static auto gen_random(size_t len) -> std::string
{
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i)
    {
        tmp_s += "1234567890abcdef"[rand() % 16];
    }

    return tmp_s;
}

auto lambda_expr::do_codegen(codegen_ctx& context) const -> codegen_value
{
    auto* parent = context.builder().GetInsertBlock();
    context.push_local_stack();

    llvm::Function* fn = llvm::Function::Create((llvm::FunctionType*)(get_sema_result().ty->get_llvm_type(context)),
                                                llvm::GlobalValue::ExternalLinkage, "__lambda_" + gen_random(32), context.module());

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
    else
    {
        context.builder().CreateUnreachable();
    }

    context.pop_local_stack();
    context.builder().SetInsertPoint(parent);

    if (llvm::verifyFunction(*fn, &llvm::errs()))
    {
        // throw std::runtime_error("internal error: codegen failed, function is invalid");
    }

    return codegen_value::make_constant(get_sema_result().ty, fn);
}

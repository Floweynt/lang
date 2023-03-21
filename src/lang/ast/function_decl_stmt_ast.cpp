#include "lang/ast/function_decl_stmt_ast.h"
#include "lang/ast/base_ast.h"
#include "lang/ast/block_expr_ast.h"
#include "lang/ast/variable_decl_expr_ast.h"
#include "lang/codegen/codegen_ctx.h"
#include "lang/codegen/codegen_value.h"
#include "lang/raii_guard.h"
#include "lang/sema/types.h"
#include "lang/utils/function_like_utils.h"
#include "lang/utils/utils.h"
#include <fmt/ranges.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/raw_ostream.h>
#include <memory>
#include <optional>
#include <ranges>
#include <stdexcept>
#include <vector>

function_decl_stmt::function_decl_stmt(code_location start, code_location end, std::vector<ast_ref> args, ast_ref return_type, ast_ref body,
                                       std::string name, ast_ref attributes)
    : base_ast(start, end, FUN_DECL_STMT), args(std::move(args)), return_type(std::move(return_type)), body(std::move(body)),
      attributes(std::move(attributes)), name(std::move(name))
{
}

void function_decl_stmt::visit_children(const std::function<void(const base_ast&)>& consumer) const
{
    if (attributes)
    {
        consumer(*attributes);
    }

    for (const auto& arg : args)
    {
        consumer(*arg);
    }
    if (return_type)
    {
        consumer(*return_type);
    }
    if (body)
    {
        consumer(*body);
    }
}

auto function_decl_stmt::do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result
{
    if (!body)
    {
        // prototype sema
        if (!return_type || return_type->get_ast_kind() == AUTO_KW)
        {
            context.get_compiler_ctx().report_diagnostic({{range(), "forward decleration must have return type"}});
            return {context.langtype(primitive_type::ERROR), false};
        }

        std::vector<type_descriptor> arg_types;
        bool is_valid = false;
        bool should_fail = false;

        context.push_local_stack();
        for (const auto& arg : args)
        {
            auto [arg_type, valid, _t, _t] = arg->semantic_analysis(context);
            arg_types.push_back(arg_type);

            if (arg_type == context.langtype(primitive_type::ERROR))
            {
                should_fail = true;
            }
            is_valid &= valid;
        }
        context.pop_local_stack();

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

        const auto* return_ty = return_type->compiler_eval(context).get_value<type_descriptor>();

        context.add_variable(name, context.make_simple_lambda_function(return_ty, arg_types));
        return {should_fail ? context.langtype(primitive_type::ERROR) : context.make_simple_lambda_function(return_ty, arg_types), is_valid};
    }

    return do_sema_func(context, args, body, return_type, name);
}

auto function_decl_stmt::do_codegen(codegen_ctx& context) const -> codegen_value
{
    const auto* this_ty = get_sema_result().ty;

    if (!body)
    {
        llvm::Function* proto =
            llvm::Function::Create((llvm::FunctionType*)(this_ty->get_llvm_type(context)), llvm::Function::ExternalLinkage, name, context.module());

        for (auto& value : proto->args())
        {
            value.setName(dynamic_cast<variable_decl_expr*>(args[value.getArgNo()].get())->get_name());
        }

        context.add_variable(name, codegen_value::make_constant(this_ty, proto));
        return codegen_value::make_null();
    }

    return do_codegen_func(context, llvm::GlobalValue::ExternalLinkage, name, this_ty, args, body, false);
}

auto function_decl_stmt::serialize() const -> std::string
{
    return fmt::format("(function_decleration_statement \"{}\" {} ({}) {} {})", name, attributes ? attributes->serialize() : "null",
                       fmt::join(args | std::ranges::views::transform([](const ast_ref& entry) { return entry->serialize(); }), " "),
                       return_type ? return_type->serialize() : "null", body ? body->serialize() : "null");
}

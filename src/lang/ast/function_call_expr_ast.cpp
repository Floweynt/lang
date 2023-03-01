#include "lang/ast/function_call_expr_ast.h"
#include "lang/codegen/codegen_value.h"
#include "lang/sema/types.h"
#include <fmt/ranges.h>
#include <optional>
#include <ranges>

function_call_expr::function_call_expr(code_location start, code_location end, ast_ref callee, std::vector<ast_ref> args)
    : base_ast(start, end, FUNCTION_CALL_EXPR), callee(std::move(callee)), args(std::move(args))
{
}

void function_call_expr::visit_children(const std::function<void(const base_ast&)>& consumer) const
{
    for (const auto& arg : args)
    {
        consumer(*arg);
    }
}

auto function_call_expr::do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result
{
    // perform semantic analysis
    std::vector<type_descriptor> types;

    bool call_types_valid = true;
    for (const auto& arg : args)
    {
        auto [ty, valid, _] = arg->semantic_analysis(context);
        if (!valid)
        {
            call_types_valid = false;
        }
        types.push_back(ty);
    }
    auto [invokee_ty, valid, _] = callee->semantic_analysis(context);

    // there has been an error trying to invoke stuff
    if (invokee_ty == context.langtype(primitive_type::ERROR))
    {
        return {context.langtype(primitive_type::ERROR), false};
    }

    const auto* invoke_result = invokee_ty->invoke_result(context, types);
    // the call types are not valid
    if (!call_types_valid)
    {
        return {invoke_result, false}; // if it magically still works, we can just use that type
    }

    if (invoke_result == context.langtype(primitive_type::ERROR))
    {
        std::vector<std::pair<code_range, std::string>> notes;

        notes.emplace_back(callee->range(), "invokee type is " + invokee_ty->get_name());

        for (size_t i = 0; i < args.size(); i++)
        {
            notes.emplace_back(args[i]->range(), "argument " + std::to_string(i) + " has type " + types[i]->get_name());
        }

        context.get_compiler_ctx().report_error(error{
            range(),
            "unable to invoke function with specified argument types; either the invokee cannot be called as a function, or you messed up arguments",
            std::nullopt, notes});
        return {context.langtype(primitive_type::ERROR), false};
    }

    return {invoke_result, true};
}

auto function_call_expr::do_codegen(codegen_ctx& context) const -> codegen_value
{
    std::vector<codegen_value> values(args.size());
    std::transform(args.begin(), args.end(), values.begin(), [&context](const ast_ref& ast) { return ast->codegen(context); });
    return callee->get_sema_result().ty->invoke_codegen(context, callee->codegen(context), values);
}

auto function_call_expr::serialize() const -> std::string
{
    return fmt::format("(function_call_expression {} ({}))", callee->serialize(),
                       fmt::join(args | std::ranges::views::transform([](const ast_ref& entry) { return entry->serialize(); }), " "));
}

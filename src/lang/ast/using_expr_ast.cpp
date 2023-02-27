#include "lang/ast/using_expr_ast.h"
#include "lang/sema/types.h"
#include <fmt/ranges.h>
#include <ranges>
#include <stdexcept>
#include <utility>

auto using_expr::do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result
{
    auto [ty, is_valid, is_consteval] = type->semantic_analysis(context);
    if (ty != context.langtype(primitive_type::META))
    {
        context.get_compiler_ctx().report_error(error{
            type->range(),
            "type specifier must refer to a type (the expressions should have type 'metatype', but got \'" + ty->get_name() + "\')",
            std::nullopt,
        });
        return {context.langtype(primitive_type::UNIT), false};
    }

    if (!is_consteval)
    {
        throw std::runtime_error("internal error: metatype should be consteval");
    }

    context.add_comptime_value(name, type->compiler_eval(context));
    return {context.langtype(primitive_type::UNIT), is_valid};
}

using_expr::using_expr(code_location start, code_location end, std::string name, ast_ref initializer, std::vector<ast_ref> args)
    : base_ast(start, end, USING_STMT), name(std::move(name)), type(std::move(initializer)), args(std::move(args))
{
}

void using_expr::visit_children(const std::function<void(const base_ast&)>& consumer) const
{
    consumer(*type);
    for (const auto& arg : args)
    {
        consumer(*arg);
    }
}

auto using_expr::serialize() const -> std::string
{
    return fmt::format("(using_statement \"{}\" {} ({}))", name, type->serialize(),
                       fmt::join(args | std::views::transform([](const ast_ref& ref) { return ref->serialize(); }), " "));
}

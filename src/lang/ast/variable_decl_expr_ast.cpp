#include "lang/ast/variable_decl_expr_ast.h"
#include "lang/ast/base_ast.h"
#include "lang/codegen/codegen_value.h"
#include "lang/sema/types.h"
#include <fmt/ranges.h>
#include <optional>
#include <ranges>
#include <stdexcept>
#include <utility>

// DO NOT REORDER
#include "lang/utils/utils.h"
auto variable_decl_expr::do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result
{
    type_descriptor type = nullptr;
    bool is_convert_valid = true;

    if (!ty || ty->get_ast_kind() == AUTO_KW)
    {
        if (!initializer)
        {
            context.get_compiler_ctx().report_diagnostic({
                {range(), "do not use auto keyword without initializer: cannot deduce type"},
            });
            return {context.langtype(primitive_type::ERROR), false};
        }

        auto [init_type, is_init_valid, _, _] = initializer->semantic_analysis(context);
        if (!is_init_valid)
        {
            return {init_type, false};
        }

        type = init_type;
    }
    else
    {
        auto [start, end, can_consteval, _] = ty->semantic_analysis(context);
        if (start != context.langtype(primitive_type::META))
        {
            context.get_compiler_ctx().report_diagnostic({
                {ty->range(), "type specifier should be of type metatype; either insert decltype(...), or fix the type signature"},
            });

            return {context.langtype(primitive_type::ERROR), false};
        }

        if (!can_consteval)
        {
            throw std::runtime_error("internal error: metatype related function should be comptime");
        }

        auto value = ty->compiler_eval(context);
        type = value.get_value<type_descriptor>();

        if (initializer)
        {
            const auto* init_ty = initializer->semantic_analysis(context).ty;
            if (!context.exists_conversion(type, init_ty))
            {
                context.get_compiler_ctx().report_diagnostic({{initializer->range(), "unable to convert initializer of type '" + init_ty->get_name() +
                                                                                         "' to variable of type '" + type->get_name() + "'"}});
                is_convert_valid = false;
            }
        }
    }

    if (!context.add_variable(name, type))
    {
        context.get_compiler_ctx().report_diagnostic({
            {range(), "duplicate variable name declared; the variable has been previously declared"},
        });
        return {type, false};
    }

    return {type, (initializer ? initializer->semantic_analysis(context).is_valid : true) && is_convert_valid};
}

variable_decl_expr::variable_decl_expr(code_location start, code_location end, std::string name, std::vector<ast_ref> modifiers, ast_ref ty,
                                       ast_ref initializer, bool is_packed)
    : base_ast(start, end, VARIABLE_DECL_STMT), name(std::move(name)), modifiers(std::move(modifiers)), ty(std::move(ty)), is_packed(is_packed),
      initializer(std::move(initializer))
{
}

void variable_decl_expr::visit_children(const std::function<void(const base_ast&)>& consumer) const
{
    for (const auto& modifier : modifiers)
    {
        consumer(*modifier);
    }
    if (ty)
    {
        consumer(*ty);
    }
    if (initializer)
    {
        consumer(*initializer);
    }
}

auto variable_decl_expr::do_codegen(codegen_ctx& context) const -> codegen_value
{
    codegen_value var{};
    const auto* var_type = get_sema_result().ty;

    if (initializer)
    {
        var = codegen_value::make_local(context, var_type, context.convert_to(var_type, initializer->codegen(context)), "local_" + name);
    }
    else
    {
        var = codegen_value::make_local(context, var_type, std::nullopt, "local_" + name);
    }

    context.add_variable(name, var);
    return var;
}

auto variable_decl_expr::serialize() const -> std::string
{
    return fmt::format("(variable_decl_expression \"{}\" {} ({}) {} {})", name, is_packed,
                       fmt::join(modifiers | std::views::transform([](const ast_ref& ref) { return ref->serialize(); }), " "),
                       ty ? ty->serialize() : "null", initializer ? initializer->serialize() : "null");
}

#include "lang/ast/namespaced_name_ref_expr_ast.h"
#include "lang/ast/name_ref_expr_ast.h"
#include "lang/sema/ct_value.h"
#include "lang/sema/sema_ctx.h"
#include "lang/sema/types.h"
#include <fmt/ranges.h>
#include <ranges>
#include <stdexcept>
#include <utility>

auto namespaced_name_ref_expr::do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result
{
    // we do semantic analysis on the right-hand-side expressions
    auto [lhs_type, lhs_fail, can_consteval, _] = lhs->semantic_analysis(context);
    type_descriptor namespace_target = nullptr;

    if (lhs_type == context.langtype(primitive_type::META))
    {
        // the type to actually do scope resolution on is not the type of the expressions (meta)
        // but the actual type itself, which is an value of type metatype
        if (!can_consteval)
        {
            throw std::runtime_error("internal error: compile time value 'metatype' needs to be able to be compile time evaluated");
        }

        auto val = lhs->compiler_eval(context);
        namespace_target = val.get_value<type_descriptor>();
    }
    else
    {
        namespace_target = lhs_type;
    }

    // we make sure that the right hand side is an name
    if (rhs->get_ast_kind() != NAME_REF)
    {
        context.get_compiler_ctx().report_diagnostic({{rhs->range(), "expected identifier after namespace scope resolution operator ::"}});
        return {context.langtype(primitive_type::ERROR), false};
    }

    // we obtain the type after scope resolution
    // this could either be metatype, indicating the form is lhs::member_type
    // it could also be error, which means the programmer messed up
    // it could also be any other type, meaning that it is probably lhs::static_constant or lhs::scoped_global_variable
    const auto* resolved_name = namespace_target->resolve_name(context, dynamic_cast<name_ref_expr*>(rhs.get())->get_name());

    // handle the case for errors
    if (resolved_name == context.langtype(primitive_type::ERROR))
    {
        context.get_compiler_ctx().report_diagnostic({{rhs->range(), "cannot resolve nested scope"}});
        return {context.langtype(primitive_type::ERROR), false};
    }
    if (resolved_name == context.langtype(primitive_type::META))
    {
        return {resolved_name, true, true};
    }

    return {resolved_name, true, false};
}

auto namespaced_name_ref_expr::do_consteval(sema_ctx& context) const -> ct_value
{
    // we do semantic analysis on the right-hand-side expressions
    auto [lhs_type, lhs_fail, can_consteval, _] = lhs->semantic_analysis(context);
    type_descriptor namespace_target = nullptr;

    if (lhs_type == context.langtype(primitive_type::META))
    {
        // the type to actually do scope resolution on is not the type of the expressions (meta)
        // but the actual type itself, which is an value of type metatype
        if (!can_consteval)
        {
            throw std::runtime_error("internal error: compile time value 'metatype' needs to be able to be compile time evaluated");
        }

        auto val = lhs->compiler_eval(context);
        namespace_target = val.get_value<type_descriptor>();
    }
    else
    {
        namespace_target = lhs_type;
    }

    const auto* resolved_name = namespace_target->resolve_name(context, dynamic_cast<name_ref_expr*>(rhs.get())->get_name());

    if (resolved_name == context.langtype(primitive_type::META))
    {
        return namespace_target->constexpr_eval_resolve_name(context, dynamic_cast<name_ref_expr*>(rhs.get())->get_name());
    }

    throw std::runtime_error("internal error: not implemented");
}

namespaced_name_ref_expr::namespaced_name_ref_expr(ast_ref lhs, ast_ref rhs)
    : base_ast(lhs->get_start(), rhs->get_end(), NAMESPACED_NAME_AST), lhs(std::move(lhs)), rhs(std::move(rhs))
{
}

void namespaced_name_ref_expr::visit_children(const std::function<void(const base_ast&)>& consumer) const {}

auto namespaced_name_ref_expr::do_codegen(codegen_ctx& context) const -> codegen_value { throw std::runtime_error("internal error: no!"); }

auto namespaced_name_ref_expr::serialize() const -> std::string
{
    return fmt::format("(namespaced_name_expression {} {})", lhs->serialize(), rhs->serialize());
}

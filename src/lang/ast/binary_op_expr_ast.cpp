
#include "lang/ast/binary_op_expr_ast.h"
#include "lang/ast/base_ast.h"
#include "lang/ast/name_ref_expr_ast.h"
#include "lang/ast/operator_types.h"
#include "lang/sema/types.h"
#include <optional>
#include <stdexcept>

binary_op_expr::binary_op_expr(binary_op_type ty, code_range operator_range, ast_ref lhs, ast_ref rhs)
    : base_ast(lhs->get_start(), rhs->get_end(), BINOP_EXPR), op(ty), lhs(std::move(lhs)), rhs(std::move(rhs)), operator_location(operator_range)
{
}

void binary_op_expr::visit_children(const std::function<void(const base_ast&)>& f) const
{
    f(*lhs);
    f(*rhs);
}

semantic_analysis_result binary_op_expr::do_semantic_analysis(sema_ctx& c) const
{
    if (op == OP_NAMESPACED_REFERENCE)
    {
        // we do semantic analysis on the right-hand-side expressions
        auto [lhs_type, lhs_fail, can_consteval] = lhs->semantic_analysis(c);
        type_descriptor namespace_target;

        if (lhs_type == c.langtype(primitive_type::META))
        {
            // the type to actually do scope resolution on is not the type of the expressions (meta)
            // but the actual type itself, which is an value of type metatype
            if (!can_consteval)
                throw std::runtime_error("internal error: compile time value 'metatype' needs to be able to be compile time evaluated");

            auto val = lhs->do_consteval(c);
            namespace_target = val.get_value<type_descriptor>();
        }
        else
        {
            namespace_target = lhs_type;
        }

        // we make sure that the right hand side is an name
        if (rhs->get_ast_kind() != NAME_REF)
        {
            c.get_compiler_ctx().report_error(error{rhs->range(), "expected identifier after namespace scope resolution operator ::"});
            return {c.langtype(primitive_type::ERROR), false};
        }

        // we obtain the type after scope resolution
        // this could either be metatype, indicating the form is lhs::member_type
        // it could also be error, which means the programmer messed up
        // it could also be any other type, meaning that it is probably lhs::static_constant or lhs::scoped_global_variable
        auto resolved_name = namespace_target->resolve_name(c, dynamic_cast<name_ref_expr*>(rhs.get())->get_name());

        // handle the case for errors
        if (resolved_name == c.langtype(primitive_type::ERROR))
        {
            c.get_compiler_ctx().report_error(error{rhs->range(), "cannot resolve nested scope"});
            return {c.langtype(primitive_type::ERROR), false};
        }
        else if (resolved_name == c.langtype(primitive_type::META))
        {
            return {resolved_name, true, true};
        }
        else
        {
            return {resolved_name, true, false};
        }
    }

    auto [lhs_type, lhs_fail, _1] = lhs->semantic_analysis(c);
    auto [rhs_type, rhs_fail, _2] = rhs->semantic_analysis(c);

    if (!lhs_fail || !rhs_fail)
        return {c.langtype(primitive_type::ERROR), false};

    auto result_type = c.binary_operator_result(op, lhs_type, rhs_type);

    if (result_type == c.langtype(primitive_type::ERROR))
    {
        c.get_compiler_ctx().report_error(
            error{operator_location,
                  std::string("unknown overload for operator `") + OPERATOR_SYMBOLS[op] + "`; perhaps you failed to provide an overload?",
                  std::nullopt,
                  {{
                       lhs->range(),
                       "left-hand side type is: " + lhs_type->get_name(),
                   },
                   {rhs->range(), "right-hand side type is: " + rhs_type->get_name()}}});

        return {c.langtype(primitive_type::ERROR), false};
    }

    return {result_type, true};
}

ct_value binary_op_expr::do_consteval(sema_ctx& c) const
{
    if (op == OP_NAMESPACED_REFERENCE)
    {
        // we do semantic analysis on the right-hand-side expressions
        auto [lhs_type, lhs_fail, can_consteval] = lhs->semantic_analysis(c);
        type_descriptor namespace_target;

        if (lhs_type == c.langtype(primitive_type::META))
        {
            // the type to actually do scope resolution on is not the type of the expressions (meta)
            // but the actual type itself, which is an value of type metatype
            if (!can_consteval)
                throw std::runtime_error("internal error: compile time value 'metatype' needs to be able to be compile time evaluated");

            auto val = lhs->do_consteval(c);
            namespace_target = val.get_value<type_descriptor>();
        }
        else
        {
            namespace_target = lhs_type;
        }

        auto resolved_name = namespace_target->resolve_name(c, dynamic_cast<name_ref_expr*>(rhs.get())->get_name());

        if (resolved_name == c.langtype(primitive_type::META))
        {
            return namespace_target->constexpr_eval_resolve_name(c, dynamic_cast<name_ref_expr*>(rhs.get())->get_name());
        }

        throw std::runtime_error("internal error: not implemented");
    }

    throw std::runtime_error("internal error: unable to consteval this expressions");
}

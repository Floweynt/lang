
#include "lang/ast/binary_op_expr_ast.h"
#include "lang/ast/base_ast.h"
#include "lang/ast/name_ref_expr_ast.h"
#include "lang/ast/operator_types.h"
#include "lang/codegen/codegen_ctx.h"
#include "lang/codegen/codegen_value.h"
#include "lang/sema/sema_ctx.h"
#include "lang/sema/types.h"
#include <llvm/IR/Value.h>
#include <optional>
#include <stdexcept>

binary_op_expr::binary_op_expr(binary_op_type ty, code_range operator_range, ast_ref lhs, ast_ref rhs)
    : base_ast(lhs->get_start(), rhs->get_end(), BINOP_EXPR), op(ty), lhs(std::move(lhs)), rhs(std::move(rhs)), operator_location(operator_range)
{
}

void binary_op_expr::visit_children(const std::function<void(const base_ast&)>& consumer) const
{
    consumer(*lhs);
    consumer(*rhs);
}

auto binary_op_expr::do_semantic_analysis(sema_ctx& c) const -> semantic_analysis_result
{
    if (op == OP_NAMESPACED_REFERENCE)
    {
        // we do semantic analysis on the right-hand-side expressions
        auto [lhs_type, lhs_fail, can_consteval] = lhs->semantic_analysis(c);
        type_descriptor namespace_target = nullptr;

        if (lhs_type == c.langtype(primitive_type::META))
        {
            // the type to actually do scope resolution on is not the type of the expressions (meta)
            // but the actual type itself, which is an value of type metatype
            if (!can_consteval)
            {
                throw std::runtime_error("internal error: compile time value 'metatype' needs to be able to be compile time evaluated");
            }

            auto val = lhs->compiler_eval(c);
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
        const auto* resolved_name = namespace_target->resolve_name(c, dynamic_cast<name_ref_expr*>(rhs.get())->get_name());

        // handle the case for errors
        if (resolved_name == c.langtype(primitive_type::ERROR))
        {
            c.get_compiler_ctx().report_error(error{rhs->range(), "cannot resolve nested scope"});
            return {c.langtype(primitive_type::ERROR), false};
        }
        if (resolved_name == c.langtype(primitive_type::META))
        {
            return {resolved_name, true, true};
        }

        return {resolved_name, true, false};
    }

    auto [lhs_type, lhs_fail, _1] = lhs->semantic_analysis(c);
    auto [rhs_type, rhs_fail, _2] = rhs->semantic_analysis(c);

    if (!lhs_fail || !rhs_fail)
    {
        return {c.langtype(primitive_type::ERROR), false};
    }

    const auto* result_type = c.binary_operator_result(op, lhs_type, rhs_type);

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

auto binary_op_expr::do_consteval(sema_ctx& context) const -> ct_value
{
    if (op == OP_NAMESPACED_REFERENCE)
    {
        // we do semantic analysis on the right-hand-side expressions
        auto [lhs_type, lhs_fail, can_consteval] = lhs->semantic_analysis(context);
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

    throw std::runtime_error("internal error: unable to consteval this expressions");
}

#define do_simple_codegen(integral, floating, name)                                                                                                  \
    if (rhs_type->is_primitive() && lhs_type->is_primitive() && rhs_type->is_integral() && lhs_type->is_integral() &&                                \
        rhs_type->is_signed_integral() == lhs_type->is_signed_integral())                                                                            \
    {                                                                                                                                                \
        return codegen_value::make_constant(return_ty, ctx.builder().integral(lhs_value, rhs_value, name "_integral_temp"));                         \
    }                                                                                                                                                \
    else if ((rhs_type->is_primitive() && lhs_type->is_primitive()) && (rhs_type->is_floating() && lhs_type->is_floating()))                         \
    {                                                                                                                                                \
        return codegen_value::make_constant(return_ty, ctx.builder().floating(lhs_value, rhs_value, name "_floating_temp"));                         \
    }                                                                                                                                                \
    return codegen_value::make_null()

namespace
{
    using binop_builder = llvm::Value* (llvm::IRBuilder<>::*)(llvm::Value*, llvm::Value*, const char*);

    auto try_primitive_operator_codegen(binary_op_type type, type_descriptor return_ty, codegen_value lhs, type_descriptor lhs_type,
                                        codegen_value rhs, type_descriptor rhs_type, codegen_ctx& ctx) -> codegen_value
    {
        auto* lhs_value = lhs.get_value(ctx);
        auto* rhs_value = rhs.get_value(ctx);
        switch (type)
        {
        case OP_ADD:
            do_simple_codegen(CreateAdd, CreateFAdd, "primitive_add");
        case OP_SUB:
            do_simple_codegen(CreateSub, CreateFSub, "primitive_sub");
        case OP_MUL:
            do_simple_codegen(CreateMul, CreateFMul, "primitive_mult");
        case OP_DIV:
            if ((rhs_type->is_primitive() && lhs_type->is_primitive()))
            {
                if (rhs_type->is_signed_integral() && lhs_type->is_signed_integral())
                {
                    return codegen_value::make_constant(return_ty, ctx.builder().CreateSDiv(lhs_value, rhs_value, "primitive_div_integral_temp"));
                }
                if (rhs_type->is_unsigned_integral() && lhs_type->is_unsigned_integral())
                {
                    return codegen_value::make_constant(return_ty, ctx.builder().CreateUDiv(lhs_value, rhs_value, "primitive_div_integral_temp"));
                }
                return codegen_value::make_null();
            }
            else if ((rhs_type->is_primitive() && lhs_type->is_primitive()) && (rhs_type->is_floating() && lhs_type->is_floating()))
            {
                return codegen_value::make_constant(return_ty, ctx.builder().CreateFDiv(lhs_value, rhs_value, "primitive_div_floating_temp"));
            }
            return codegen_value::make_null();
        case OP_EQ:
            if ((rhs_type->is_primitive() && lhs_type->is_primitive()) && (rhs_type->is_integral() && lhs_type->is_integral()))
            {
                return codegen_value::make_constant(return_ty, ctx.builder().CreateICmpEQ(lhs_value, rhs_value, "primitive_cmp_eq_integral_temp"));
            }
        case OP_NEQ:
            if ((rhs_type->is_primitive() && lhs_type->is_primitive()) && (rhs_type->is_integral() && lhs_type->is_integral()))
            {
                return codegen_value::make_constant(return_ty, ctx.builder().CreateICmpNE(lhs_value, rhs_value, "primitive_cmp_eq_integral_temp"));
            }
        case OP_BAD_BINARY:
        case OP_NAMESPACED_REFERENCE:
        case OP_MEMBER_ACCESS:
        case OP_BITWISE_AND:
        case OP_BITWISE_XOR:
        case OP_BITWISE_OR:
        case OP_SHR:
        case OP_SHL:
        case OP_LOGICAL_AND:
        case OP_LOGICAL_OR:
        case OP_SPACESHIP:
        case OP_LESS:
        case OP_LEQ:
        case OP_GREATER:
        case OP_GEQ:
        case OP_MOD:
        case OP_ASSIGN:
            lhs.store_value(ctx, rhs);
            return lhs;
        case OP_ADD_ASSIGN:
        case OP_SUB_ASSIGN:
        case OP_MUL_ASSIGN:
        case OP_DIV_ASSIGN:
        case OP_MOD_ASSIGN:
        case OP_SHL_ASSIGN:
        case OP_SHR_ASSIGN:
        case OP_AND_ASSIGN:
        case OP_XOR_ASSIGN:
        case OP_OR_ASSIGN:
            break;
        }

        return codegen_value::make_null();
    }
} // namespace

auto binary_op_expr::do_codegen(codegen_ctx& context) const -> codegen_value
{
    // !! i cannot do codegen for scope operators
    if (op == OP_NAMESPACED_REFERENCE)
    {
        throw std::runtime_error("todo: implement");
    }

    auto lhs_value = lhs->codegen(context);
    auto rhs_value = rhs->codegen(context);

    auto value =
        try_primitive_operator_codegen(op, get_sema_result().ty, lhs_value, lhs->get_sema_result().ty, rhs_value, rhs->get_sema_result().ty, context);

    if (value.get_type() == nullptr)
    {
        throw std::runtime_error("TODO: implement");
    }

    return value;
}

auto binary_op_expr::serialize() const -> std::string
{
    return fmt::format("(binary_op_expression \"{}\" {} {})", OPERATOR_SYMBOLS[op], lhs->serialize(), rhs->serialize());
}


#include "lang/ast/binary_op_expr_ast.h"
#include "lang/ast/base_ast.h"
#include "lang/ast/name_ref_expr_ast.h"
#include "lang/ast/operator_types.h"
#include "lang/codegen/codegen.h"
#include "lang/codegen/codegen_ctx.h"
#include "lang/codegen/codegen_value.h"
#include "lang/sema/sema_ctx.h"
#include "lang/sema/types.h"
#include "lang/utils/utils.h"
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Instruction.h>
#include <llvm/IR/Value.h>
#include <optional>
#include <stdexcept>

binary_op_expr::binary_op_expr(binary_op_type op_ty, code_range operator_range, ast_ref lhs, ast_ref rhs)
    : base_ast(lhs->get_start(), rhs->get_end(), BINOP_EXPR), op(op_ty), lhs(std::move(lhs)), rhs(std::move(rhs)), operator_location(operator_range)
{
}

void binary_op_expr::visit_children(const std::function<void(const base_ast&)>& consumer) const
{
    consumer(*lhs);
    consumer(*rhs);
}

auto binary_op_expr::do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result
{
    auto [lhs_type, lhs_fail, _t, lhs_value_category] = lhs->semantic_analysis(context);
    auto [rhs_type, rhs_fail, _t, _t] = rhs->semantic_analysis(context);

    if (!lhs_fail || !rhs_fail)
    {
        return {context.langtype(primitive_type::ERROR), false};
    }

    bool works = true;
    if (!lhs_value_category && op >= OP_ASSIGN)
    {
        context.get_compiler_ctx().report_diagnostic({{lhs->range(), "lhs must be a lvalue for assignment"}});
        works = false;
    }

    const auto* result_type = context.binary_operator_result(op, lhs_type, rhs_type);

    if (result_type == context.langtype(primitive_type::ERROR))
    {
        context.get_compiler_ctx().report_diagnostic(
            {{operator_location,
              std::string("unknown overload for operator `") + BINARY_OPERATOR_SYMBOLS[op] + "`; perhaps you failed to provide an overload?"},
             std::nullopt,
             {{
                  lhs->range(),
                  "left-hand side type is: " + lhs_type->get_name(),
              },
              {rhs->range(), "right-hand side type is: " + rhs_type->get_name()}}});

        return {context.langtype(primitive_type::ERROR), false};
    }

    return {result_type, works};
}

auto binary_op_expr::do_consteval(sema_ctx& context) const -> ct_value
{
    throw std::runtime_error("internal error: unable to consteval this expression");
}

auto binary_op_expr::do_codegen(codegen_ctx& context) const -> codegen_value
{
    auto lhs_value = lhs->codegen(context);
    auto rhs_value = rhs->codegen(context);

    auto* simple_codegen = context.get_binary_op_handler({op, lhs->get_sema_result().ty, rhs->get_sema_result().ty});

    if (simple_codegen == nullptr)
    {
        throw std::runtime_error("TODO: implement");
    }

    return codegen_value::make_constant(get_sema_result().ty, simple_codegen(context, lhs_value, rhs_value, get_sema_result().ty));
}

auto binary_op_expr::serialize() const -> std::string
{
    return fmt::format("(binary_op_expression \"{}\" {} {})", BINARY_OPERATOR_SYMBOLS[op], lhs->serialize(), rhs->serialize());
}

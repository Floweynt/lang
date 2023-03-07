#include "lang/ast/unary_op_expr_ast.h"
#include "lang/ast/operator_types.h"
#include "lang/codegen/codegen.h"
#include "lang/codegen/codegen_ctx.h"
#include "lang/codegen/codegen_value.h"
#include "lang/sema/types.h"
#include <llvm/IR/Constants.h>
#include <llvm/IR/Value.h>
#include <stdexcept>
#include "lang/utils/utils.h"

auto unary_op_expr::do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result
{

    auto [op_type, op_valid, _, _] = expr->semantic_analysis(context);

    if (!op_valid)
    {
        return {context.langtype(primitive_type::ERROR), false};
    }

    const auto* result_type = context.unary_operator_result(op, op_type);

    if (result_type == context.langtype(primitive_type::ERROR))
    {
        context.get_compiler_ctx().report_diagnostic(
            {{operator_range, "unknown overload for unary operator; perhaps you failed to provide an overload?"},
             std::nullopt,
             {{
                 expr->range(),
                 "operand type is: " + op_type->get_name(),
             }}});

        return {context.langtype(primitive_type::ERROR), false};
    }

    return {result_type, true};
}

unary_op_expr::unary_op_expr(code_location start, code_location end, code_range operator_range, unary_op_type ty, ast_ref expr)
    : base_ast(start, end, UNARY_EXPR), op(ty), expr(std::move(expr)), operator_range(operator_range)
{
}

void unary_op_expr::visit_children(const std::function<void(const base_ast&)>& consumer) const { return consumer(*expr); }

namespace
{
    auto try_primitive_operator_codegen(unary_op_type op, type_descriptor expr_type, const codegen_value& expr_value, codegen_ctx& ctx)
    {
        auto* llvm_type = expr_type->get_llvm_type(ctx);
        auto* llvm_value = expr_value.get_value(ctx);

        if (expr_type->is_integral())
        {
            switch (op)
            {
            case OP_INC: {
                auto add_result = codegen_value::make_constant(
                    expr_type, ctx.builder().CreateAdd(llvm_value, llvm::ConstantInt::get(llvm_type, 1), codegen_name("unary_pre_inc")));
                expr_value.store_value(ctx, add_result);
                return add_result;
            }
            case OP_DEC: {
                auto dec_result = codegen_value::make_constant(
                    expr_type, ctx.builder().CreateAdd(llvm_value, llvm::ConstantInt::get(llvm_type, -1), codegen_name("unary_pre_dec")));
                expr_value.store_value(ctx, dec_result);
                return dec_result;
            }
            case OP_LOGICAL_NOT:
                return codegen_value::make_constant(
                    expr_type, ctx.builder().CreateICmpEQ(llvm_value, llvm::ConstantInt::get(llvm_type, 0), codegen_name("unary_lnot")));
            case OP_BITWISE_NOT:
                return codegen_value::make_constant(expr_type, ctx.builder().CreateNot(llvm_value, codegen_name("unary_bnot")));
            case OP_NEGATE:
                return codegen_value::make_constant(expr_type, ctx.builder().CreateNeg(llvm_value, codegen_name("unary_neg")));
            default:
                break;
            }

            return codegen_value::make_null();
        }

        return codegen_value::make_null();
    }
} // namespace

auto unary_op_expr::do_codegen(codegen_ctx& context) const -> codegen_value
{
    auto result = try_primitive_operator_codegen(op, get_sema_result().ty, expr->codegen(context), context);

    if (result.get_type() == nullptr)
    {
        throw std::runtime_error("internal error: unable to implement");
    }

    return result;
}

auto unary_op_expr::serialize() const -> std::string { return fmt::format("(unary_op_expression \"\" ({}))", expr->serialize()); }

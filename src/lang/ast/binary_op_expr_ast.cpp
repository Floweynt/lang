
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

binary_op_expr::binary_op_expr(binary_op_type ty, code_range operator_range, ast_ref lhs, ast_ref rhs)
    : base_ast(lhs->get_start(), rhs->get_end(), BINOP_EXPR), op(ty), lhs(std::move(lhs)), rhs(std::move(rhs)), operator_location(operator_range)
{
}

void binary_op_expr::visit_children(const std::function<void(const base_ast&)>& consumer) const
{
    consumer(*lhs);
    consumer(*rhs);
}

auto binary_op_expr::do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result
{
    auto [lhs_type, lhs_fail, _, lhs_value_category] = lhs->semantic_analysis(context);
    auto [rhs_type, rhs_fail, _, _] = rhs->semantic_analysis(context);

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
        context.get_compiler_ctx().report_diagnostic({{operator_location, std::string("unknown overload for operator `") + OPERATOR_SYMBOLS[op] +
                                                                              "`; perhaps you failed to provide an overload?"},
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

namespace
{
    using binop_builder = llvm::Value* (llvm::IRBuilder<>::*)(llvm::Value*, llvm::Value*, const char*);

    auto promote_type_int(type_descriptor lhs_type, type_descriptor rhs_type, llvm::Value* value, codegen_ctx& ctx) -> llvm::Value*
    {
        auto* lhs_llvm_type = (llvm::IntegerType*)lhs_type->get_llvm_type(ctx);
        auto* rhs_llvm_type = (llvm::IntegerType*)rhs_type->get_llvm_type(ctx);

        auto* target_type = lhs_llvm_type->getBitWidth() > rhs_llvm_type->getBitWidth() ? lhs_llvm_type : rhs_llvm_type;

        return ctx.builder().CreateCast(lhs_type->is_unsigned_integral() ? llvm::Instruction::ZExt : llvm::Instruction::SExt, value, target_type,
                                        codegen_name("binop_promote_int"));
    }

    auto do_assign_and_return_value(codegen_ctx& ctx, codegen_value assignee, type_descriptor type, llvm::Value* val)
    {
        auto value = codegen_value::make_constant(type, val);
        assignee.store_value(ctx, value);
        return value;
    }

    auto primitive_operator_integral_codegen(binary_op_type type, type_descriptor return_ty, codegen_value lhs, type_descriptor lhs_type,
                                             codegen_value rhs, type_descriptor rhs_type, codegen_ctx& ctx)
    {
        auto* lhs_llvm_val = promote_type_int(lhs_type, rhs_type, lhs.get_value(ctx), ctx);
        auto* rhs_llvm_val = promote_type_int(lhs_type, rhs_type, rhs.get_value(ctx), ctx);

        switch (type)
        {
        case OP_ADD:
            return codegen_value::make_constant(return_ty, ctx.builder().CreateAdd(lhs_llvm_val, rhs_llvm_val, codegen_name("binop_add_tmp")));
        case OP_SUB:
            return codegen_value::make_constant(return_ty, ctx.builder().CreateSub(lhs_llvm_val, rhs_llvm_val, codegen_name("binop_sub_tmp")));
        case OP_MUL:
            return codegen_value::make_constant(return_ty, ctx.builder().CreateMul(lhs_llvm_val, rhs_llvm_val, codegen_name("binop_mul_tmp")));
        case OP_DIV:
            return codegen_value::make_constant(
                return_ty, lhs_type->is_signed_integral() ? ctx.builder().CreateSDiv(lhs_llvm_val, rhs_llvm_val, codegen_name("binop_sdiv_tmp"))
                                                          : ctx.builder().CreateUDiv(lhs_llvm_val, rhs_llvm_val, codegen_name("binop_udiv_tmp")));
        case OP_MOD:
            return codegen_value::make_constant(
                return_ty, lhs_type->is_signed_integral() ? ctx.builder().CreateSRem(lhs_llvm_val, rhs_llvm_val, codegen_name("binop_srem_tmp"))
                                                          : ctx.builder().CreateURem(lhs_llvm_val, rhs_llvm_val, codegen_name("binop_urem_tmp")));
        case OP_EQ:
            return codegen_value::make_constant(return_ty, ctx.builder().CreateICmpEQ(lhs_llvm_val, rhs_llvm_val, codegen_name("binop_cmpeq_tmp")));
        case OP_NEQ:
            return codegen_value::make_constant(return_ty, ctx.builder().CreateICmpNE(lhs_llvm_val, rhs_llvm_val, codegen_name("binop_cmpneq_tmp")));
        case OP_LESS:
            return codegen_value::make_constant(
                return_ty, lhs_type->is_signed_integral() ? ctx.builder().CreateICmpSLT(lhs_llvm_val, rhs_llvm_val, codegen_name("binop_cmpslt_tmp"))
                                                          : ctx.builder().CreateICmpULT(lhs_llvm_val, rhs_llvm_val, "binop_cmpult_tmp"));
        case OP_GREATER:
            return codegen_value::make_constant(
                return_ty, lhs_type->is_signed_integral() ? ctx.builder().CreateICmpSGT(lhs_llvm_val, rhs_llvm_val, codegen_name("binop_cmpsgt_tmp"))
                                                          : ctx.builder().CreateICmpUGT(lhs_llvm_val, rhs_llvm_val, "binop_cmpugt_tmp"));
        case OP_GEQ:
            return codegen_value::make_constant(
                return_ty, lhs_type->is_signed_integral() ? ctx.builder().CreateICmpSGE(lhs_llvm_val, rhs_llvm_val, codegen_name("binop_cmpsge_tmp"))
                                                          : ctx.builder().CreateICmpUGE(lhs_llvm_val, rhs_llvm_val, "binop_cmpuge_tmp"));
        case OP_LEQ:
            return codegen_value::make_constant(
                return_ty, lhs_type->is_signed_integral() ? ctx.builder().CreateICmpSLE(lhs_llvm_val, rhs_llvm_val, codegen_name("binop_cmpsle_tmp"))
                                                          : ctx.builder().CreateICmpULE(lhs_llvm_val, rhs_llvm_val, "binop_cmpule_tmp"));
        case OP_BITWISE_AND:
            return codegen_value::make_constant(return_ty, ctx.builder().CreateAnd(lhs_llvm_val, rhs_llvm_val, codegen_name("binop_and_tmp")));
        case OP_BITWISE_OR:
            return codegen_value::make_constant(return_ty, ctx.builder().CreateOr(lhs_llvm_val, rhs_llvm_val, codegen_name("binop_or_tmp")));
        case OP_BITWISE_XOR:
            return codegen_value::make_constant(return_ty, ctx.builder().CreateXor(lhs_llvm_val, rhs_llvm_val, codegen_name("binop_xor_tmp")));
        case OP_SHR:
            if (rhs_type->is_signed_integral())
            {
                return codegen_value::make_null();
            }

            return codegen_value::make_constant(return_ty, rhs_type->is_signed_integral()
                                                               ? ctx.builder().CreateAShr(lhs_llvm_val, rhs_llvm_val, codegen_name("binop_shr_tmp"))
                                                               : ctx.builder().CreateLShr(lhs_llvm_val, rhs_llvm_val, codegen_name("binop_shr_tmp")));
        case OP_SHL:
            if (rhs_type->is_signed_integral() || lhs_type->is_signed_integral())
            {
                return codegen_value::make_null();
            }

            return codegen_value::make_constant(return_ty, ctx.builder().CreateShl(lhs_llvm_val, rhs_llvm_val, codegen_name("binop_shl_tmp")));
        default:
            break;
        }

        if (lhs_llvm_val->getType()->getIntegerBitWidth() >= rhs_llvm_val->getType()->getIntegerBitWidth())
        {
            switch (type)
            {
            case OP_ADD_ASSIGN:
                return do_assign_and_return_value(ctx, lhs, return_ty,
                                                  ctx.builder().CreateAdd(lhs_llvm_val, rhs_llvm_val, codegen_name("binop_add_assign_tmp")));
            case OP_SUB_ASSIGN:
                return do_assign_and_return_value(ctx, lhs, return_ty,
                                                  ctx.builder().CreateSub(lhs_llvm_val, rhs_llvm_val, codegen_name("binop_sub_assign_tmp")));
            case OP_MUL_ASSIGN:
                return do_assign_and_return_value(ctx, lhs, return_ty,
                                                  ctx.builder().CreateMul(lhs_llvm_val, rhs_llvm_val, codegen_name("binop_mul_assign_tmp")));
            case OP_DIV_ASSIGN:
                return do_assign_and_return_value(ctx, lhs, return_ty,
                                                  lhs_type->is_signed_integral()
                                                      ? ctx.builder().CreateSDiv(lhs_llvm_val, rhs_llvm_val, codegen_name("binop_sdiv_assign_tmp"))
                                                      : ctx.builder().CreateUDiv(lhs_llvm_val, rhs_llvm_val, codegen_name("binop_udiv_assign_tmp")));
            case OP_MOD_ASSIGN:
                return do_assign_and_return_value(ctx, lhs, return_ty,
                                                  lhs_type->is_signed_integral()
                                                      ? ctx.builder().CreateSRem(lhs_llvm_val, rhs_llvm_val, codegen_name("binop_srem_assign_tmp"))
                                                      : ctx.builder().CreateURem(lhs_llvm_val, rhs_llvm_val, codegen_name("binop_urem_assign_tmp")));
            case OP_AND_ASSIGN:
                return do_assign_and_return_value(ctx, lhs, return_ty,
                                                  ctx.builder().CreateAnd(lhs_llvm_val, rhs_llvm_val, codegen_name("binop_and_assign_tmp")));
            case OP_XOR_ASSIGN:
                return do_assign_and_return_value(ctx, lhs, return_ty,
                                                  ctx.builder().CreateXor(lhs_llvm_val, rhs_llvm_val, codegen_name("binop_xor_assign_tmp")));
            case OP_OR_ASSIGN:
                return do_assign_and_return_value(ctx, lhs, return_ty,
                                                  ctx.builder().CreateOr(lhs_llvm_val, rhs_llvm_val, codegen_name("binop_or_assign_tmp")));
            default:
            }
        }

        return codegen_value::make_null();
    }

    auto try_primitive_operator_codegen(binary_op_type type, type_descriptor return_ty, codegen_value lhs, type_descriptor lhs_type,
                                        codegen_value rhs, type_descriptor rhs_type, codegen_ctx& ctx) -> codegen_value
    {
        if (lhs_type->is_primitive() && type == OP_ASSIGN)
        {
            lhs.store_value(ctx, rhs);
            return lhs;
        }

        if (lhs_type->is_integral() && rhs_type->is_integral() && lhs_type->is_signed_integral() == rhs_type->is_signed_integral())
        {
            return primitive_operator_integral_codegen(type, return_ty, lhs, lhs_type, rhs, rhs_type, ctx);
        }

        return codegen_value::make_null();
    }
} // namespace

auto binary_op_expr::do_codegen(codegen_ctx& context) const -> codegen_value
{
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

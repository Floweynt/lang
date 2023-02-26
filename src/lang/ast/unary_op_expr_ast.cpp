#include "lang/ast/unary_op_expr_ast.h"
#include "lang/codegen/codegen_ctx.h"
#include <llvm/IR/Value.h>
#include <stdexcept>

auto unary_op_expr::do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result
{

    auto [op_type, op_valid, _] = expr->semantic_analysis(context);

    if (!op_valid)
    {
        return {context.langtype(primitive_type::ERROR), false};
    }

    const auto* result_type = context.unary_operator_result(op, op_type);

    if (result_type == context.langtype(primitive_type::ERROR))
    {
        context.get_compiler_ctx().report_error(error{operator_range,
                                                      "unknown overload for unary operator; perhaps you failed to provide an overload?",
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

auto unary_op_expr::do_codegen(codegen_ctx& context) const -> codegen_value { throw std::runtime_error("todo: implement"); }

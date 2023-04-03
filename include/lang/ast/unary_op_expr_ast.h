#pragma once

#include "lang/ast/base_ast.h"

class unary_op_expr : public base_ast
{
    unary_op_type op;
    ast_ref expr;
    code_range operator_range;

protected:
    auto do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result override;
    auto do_codegen(codegen_ctx& context) const -> codegen_value override;

public:
    unary_op_expr(code_location start, code_location end, code_range operator_range, unary_op_type type, ast_ref expr);
    
    void visit_children(const std::function<void(const base_ast&)>& consumer) const override;
    auto serialize() const -> std::string override;

    [[nodiscard]] constexpr auto get_operator() const { return op; }
    [[nodiscard]] constexpr auto get_expr() const -> const auto& { return expr; }
    [[nodiscard]] constexpr auto get_operator_range() const -> const auto& { return operator_range; }
};

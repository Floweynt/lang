#pragma once

#include <lang/ast/base_ast.h>

class unary_op_expr : public base_ast
{
private:
    unary_op_type op;
    ast_ref expr;
    code_range operator_range;

protected:
    virtual semantic_analysis_result do_semantic_analysis(sema_ctx& c) const override;

public:
    unary_op_expr(code_location start, code_location end, code_range operator_range, unary_op_type op, ast_ref expr);
    virtual void visit_children(const std::function<void(const base_ast&)>& f) const override;

    constexpr auto get_operator() const { return op; }
    constexpr const auto& get_expr() const { return expr; }
    constexpr const auto& get_operator_range() const { return operator_range; }
};

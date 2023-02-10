#pragma once

#include "lang/ast/operator_types.h"
#include "lang/sema/types.h"
#include <lang/ast/base_ast.h>

class binary_op_expr : public base_ast
{
private:
    binary_op_type op;
    ast_ref lhs, rhs;
    const code_range operator_location;

protected:
    virtual semantic_analysis_result do_semantic_analysis(sema_ctx& c) const override;

public:
    binary_op_expr(binary_op_type ty, code_range operator_range, ast_ref lhs, ast_ref rhs);
    virtual void visit_children(const std::function<void(const base_ast&)>& f) const override;
    virtual ct_value do_consteval(sema_ctx& c) const override;

    // getters
    constexpr const auto& get_lhs() const { return lhs; }
    constexpr const auto& get_rhs() const { return lhs; }
    constexpr auto get_operator() const { return op; }
    constexpr const auto& get_operator_location() const { return operator_location; }
};

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
    auto do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result override;
    auto do_consteval(sema_ctx& context) const -> ct_value override;
    auto do_codegen(codegen_ctx& context) const -> codegen_value override;

public:
    binary_op_expr(binary_op_type op_ty, code_range operator_range, ast_ref lhs, ast_ref rhs);
    void visit_children(const std::function<void(const base_ast&)>& consumer) const override;
    auto serialize() const -> std::string override;

    // getters
    [[nodiscard]] constexpr auto get_lhs() const -> const auto& { return lhs; }
    [[nodiscard]] constexpr auto get_rhs() const -> const auto& { return lhs; }
    [[nodiscard]] constexpr auto get_operator() const { return op; }
    [[nodiscard]] constexpr auto get_operator_location() const -> const auto& { return operator_location; }
};

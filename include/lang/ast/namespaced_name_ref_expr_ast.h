#pragma once

#include "lang/ast/base_ast.h"
#include <vector>

class namespaced_name_ref_expr : public base_ast
{
    ast_ref lhs;
    ast_ref rhs;

protected:
    auto do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result override;
    auto do_consteval(sema_ctx& context) const -> ct_value override;
    auto do_codegen(codegen_ctx& context) const -> codegen_value override;

public:
    namespaced_name_ref_expr(ast_ref lhs, ast_ref rhs);
    void visit_children(const std::function<void(const base_ast&)>& consumer) const override;
    auto serialize() const -> std::string override;

    constexpr auto get_lhs() const -> const auto& { return lhs; }
    constexpr auto get_rhs() const -> const auto& { return lhs; }
};

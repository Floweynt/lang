#pragma once
#include "lang/ast/base_ast.h"
#include <utility>

class if_expr : public base_ast
{
    std::vector<std::pair<ast_ref, ast_ref>> branches;
    ast_ref else_branch;

protected:
    auto do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result override;
    auto do_codegen(codegen_ctx& context) const -> codegen_value override;

public:
    if_expr(code_location start, code_location end, std::vector<std::pair<ast_ref, ast_ref>> branches, ast_ref else_branch);
    void visit_children(const std::function<void(const base_ast&)>& consumer) const override;
    auto serialize() const -> std::string override;
};

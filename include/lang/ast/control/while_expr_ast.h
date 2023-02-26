#pragma once
#include <lang/ast/base_ast.h>
#include <utility>

class while_expr : public base_ast
{
    ast_ref condition;
    ast_ref body;
    ast_ref else_branch;

protected:
    auto do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result override;
    auto do_codegen(codegen_ctx& context) const -> codegen_value override;

public:
    while_expr(code_location start, code_location end, ast_ref condition, ast_ref body, ast_ref else_branch);
    void visit_children(const std::function<void(const base_ast&)>& consumer) const override;
};

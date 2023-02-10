#pragma once
#include <lang/ast/base_ast.h>
#include <utility>

class if_expr : public base_ast
{
    std::vector<std::pair<ast_ref, ast_ref>> branches;
    ast_ref else_branch;

protected:
    virtual semantic_analysis_result do_semantic_analysis(sema_ctx& c) const override;

public:
    if_expr(code_location start, code_location end, std::vector<std::pair<ast_ref, ast_ref>> branches, ast_ref else_branch);
    virtual void visit_children(const std::function<void(const base_ast&)>& f) const override;
};

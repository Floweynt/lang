#pragma once

#include <lang/ast/base_ast.h>

class variable_decl_expr : public base_ast
{
    std::string name;
    std::vector<ast_ref> modifiers;
    ast_ref ty;
    bool is_packed;
    ast_ref initializer;

protected:
    virtual semantic_analysis_result do_semantic_analysis(sema_ctx& c) const override;

public:
    variable_decl_expr(code_location start, code_location end, std::string name, std::vector<ast_ref> modifiers, ast_ref ty, ast_ref initializer,
                       bool is_packed);
    void visit_children(const std::function<void(const base_ast&)>& f) const override;
};

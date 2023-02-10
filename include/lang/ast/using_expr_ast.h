#pragma once

#include <lang/ast/base_ast.h>

class using_expr : public base_ast
{
    std::string name;
    ast_ref type;

    std::vector<ast_ref> args;

protected:
    virtual semantic_analysis_result do_semantic_analysis(sema_ctx& c) const override;

public:
    using_expr(code_location start, code_location end, std::string name, ast_ref initializer, std::vector<ast_ref> args);
    void visit_children(const std::function<void(const base_ast&)>& f) const override;
};

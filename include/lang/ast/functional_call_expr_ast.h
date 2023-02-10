#pragma once

#include <lang/ast/base_ast.h>

class function_call_expr : public base_ast
{
    ast_ref callee;
    std::vector<ast_ref> args;

protected:
    virtual semantic_analysis_result do_semantic_analysis(sema_ctx& c) const override;

public:
    function_call_expr(code_location start, code_location end, ast_ref callee, std::vector<ast_ref> args);
    virtual void visit_children(const std::function<void(const base_ast&)>& f) const override;

    constexpr const auto& get_callee() const { return callee; }
    constexpr const auto& get_args() const { return args; }
};

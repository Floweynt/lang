#pragma once

#include <lang/ast/base_ast.h>

class paren_expr : public base_ast
{
    ast_ref body;

protected:
    inline virtual semantic_analysis_result do_semantic_analysis(sema_ctx& c) const override { return body->semantic_analysis(c); }

public:
    inline paren_expr(code_location start, code_location end, ast_ref body) : base_ast(start, end, PAREN_EXPR), body(std::move(body)) {}
    inline virtual void visit_children(const std::function<void(const base_ast&)>& f) const override { f(*body); }
    inline virtual ct_value do_consteval(sema_ctx& c) const override { return body->do_consteval(c); }

    constexpr const auto& get_body() const { return body; }
};

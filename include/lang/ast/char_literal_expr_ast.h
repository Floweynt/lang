#pragma once
#include <lang/ast/base_ast.h>

class char_literal_expr : public base_ast
{
    char val;

protected:
    virtual semantic_analysis_result do_semantic_analysis(sema_ctx& c) const override;

public:
    char_literal_expr(code_location start, code_location end, char val);
    virtual void visit_children(const std::function<void(const base_ast&)>& f) const override;
    virtual ct_value do_consteval(sema_ctx& c) const override;

    constexpr auto get_value() const { return val; }
};

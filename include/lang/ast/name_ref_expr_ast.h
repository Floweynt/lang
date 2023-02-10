#pragma once
#include <lang/ast/base_ast.h>

class name_ref_expr : public base_ast
{
    std::string name;

protected:
    virtual semantic_analysis_result do_semantic_analysis(sema_ctx& c) const override;

public:
    name_ref_expr(code_location start, code_location end, const std::string& name);
    virtual void visit_children(const std::function<void(const base_ast&)>& f) const override;
    virtual ct_value do_consteval(sema_ctx &c) const override;

    constexpr const auto& get_name() const { return name; }
};

#pragma once
#include "base_ast.h"

class struct_literal_expr : public base_ast
{
    std::vector<ast_ref> members;

protected:
    virtual semantic_analysis_result do_semantic_analysis(sema_ctx& c) const override;

public:
    struct_literal_expr(code_location start, code_location end, std::vector<ast_ref> members);
    virtual void visit_children(const std::function<void(const base_ast&)>& f) const override;

    constexpr const auto& get_members() const { return members; }
};

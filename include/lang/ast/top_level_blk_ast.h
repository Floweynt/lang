#pragma once

#include <lang/ast/base_ast.h>

class top_level_blk : public base_ast
{
    std::vector<ast_ref> statements;

protected:
    virtual semantic_analysis_result do_semantic_analysis(sema_ctx& c) const override;

public:
    top_level_blk(code_location start, code_location end, std::vector<ast_ref> statements);
    void visit_children(const std::function<void(const base_ast&)>& f) const override;

    constexpr const auto& get_statements() const { return statements; }
};

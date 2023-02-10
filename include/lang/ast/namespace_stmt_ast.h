#pragma once

#include <lang/ast/base_ast.h>

class namespace_stmt : public base_ast
{
    std::vector<std::string> id;
    std::vector<ast_ref> statements;

protected:
    virtual semantic_analysis_result do_semantic_analysis(sema_ctx& c) const override;

public:
    namespace_stmt(code_location start, code_location end, std::vector<std::string> id, std::vector<ast_ref> statements);
    virtual void visit_children(const std::function<void(const base_ast&)>& f) const override;

    constexpr const auto& get_id() const { return id; }
    constexpr const auto& get_statements() const { return statements; }
};

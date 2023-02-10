#pragma once

#include <lang/ast/base_ast.h>

class function_decl_stmt : public base_ast
{
    std::vector<ast_ref> args;
    ast_ref return_type;
    ast_ref body;
    std::string name;

protected:
    virtual semantic_analysis_result do_semantic_analysis(sema_ctx& c) const override;

public:
    function_decl_stmt(code_location start, code_location end, std::vector<ast_ref> args, ast_ref return_type, ast_ref body, std::string name);
    virtual void visit_children(const std::function<void(const base_ast&)>& f) const override;

    constexpr const auto& get_args() const { return args; }
    constexpr const auto& get_return_type() { return return_type; }
    constexpr const auto& get_body() const { return body; }
    constexpr const auto& get_name() const { return name; }
};

#pragma once

#include "lang/ast/base_ast.h"

class function_call_expr : public base_ast
{
    ast_ref callee;
    std::vector<ast_ref> args;

protected:
    auto do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result override;
    auto do_codegen(codegen_ctx& context) const -> codegen_value override;

public:
    function_call_expr(code_location start, code_location end, ast_ref callee, std::vector<ast_ref> args);
    void visit_children(const std::function<void(const base_ast&)>& consumer) const override;
    auto serialize() const -> std::string override;

    [[nodiscard]] constexpr auto get_callee() const -> const auto& { return callee; }
    [[nodiscard]] constexpr auto get_args() const -> const auto& { return args; }
};

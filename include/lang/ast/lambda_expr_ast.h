#pragma once

#include <lang/ast/base_ast.h>

class lambda_expr : public base_ast
{
    std::vector<ast_ref> args;
    ast_ref return_type;
    ast_ref body;

protected:
    auto do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result override;
    auto do_codegen(codegen_ctx& context) const -> codegen_value override;

public:
    lambda_expr(code_location start, code_location end, std::vector<ast_ref> args, ast_ref return_type, ast_ref body);
    void visit_children(const std::function<void(const base_ast&)>& consumer) const override;
    auto serialize() const -> std::string override;

    [[nodiscard]] constexpr auto get_args() const -> const auto& { return args; }
    [[nodiscard]] constexpr auto get_return_type() -> const auto& { return return_type; }
    [[nodiscard]] constexpr auto get_body() const -> const auto& { return body; }
};

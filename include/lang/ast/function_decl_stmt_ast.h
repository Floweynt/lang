#pragma once

#include <lang/ast/base_ast.h>

class function_decl_stmt : public base_ast
{
    std::vector<ast_ref> args;
    ast_ref return_type;
    ast_ref body;
    ast_ref attributes;
    std::string name;

protected:
    auto do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result override;
    auto do_codegen(codegen_ctx& context) const -> codegen_value override;

public:
    function_decl_stmt(code_location start, code_location end, std::vector<ast_ref> args, ast_ref return_type, ast_ref body, std::string name,
                       ast_ref attributes);
    void visit_children(const std::function<void(const base_ast&)>& consumer) const override;
    auto serialize() const -> std::string override;

    [[nodiscard]] constexpr auto get_args() const -> const auto& { return args; }
    constexpr auto get_return_type() -> const auto& { return return_type; }
    [[nodiscard]] constexpr auto get_body() const -> const auto& { return body; }
    [[nodiscard]] constexpr auto get_attributes() const -> const auto& { return attributes; }
    [[nodiscard]] constexpr auto get_name() const -> const auto& { return name; }
};

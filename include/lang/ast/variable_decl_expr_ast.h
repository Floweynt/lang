#pragma once

#include <lang/ast/base_ast.h>

class variable_decl_expr : public base_ast
{
    std::string name;
    std::vector<ast_ref> modifiers;
    ast_ref ty;
    bool is_packed;
    ast_ref initializer;

protected:
    auto do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result override;
    auto do_codegen(codegen_ctx& context) const -> codegen_value override;

public:
    variable_decl_expr(code_location start, code_location end, std::string name, std::vector<ast_ref> modifiers, ast_ref ty, ast_ref initializer,
                       bool is_packed);
    void visit_children(const std::function<void(const base_ast&)>& consumer) const override;
    auto serialize() const -> std::string override;

    constexpr auto get_name() const -> const auto& { return name; }
    constexpr auto get_modifiers() const -> const auto& { return modifiers; }
    constexpr auto get_type() const -> const auto& { return ty; }
    constexpr auto is_pack() const { return is_packed; }
    constexpr auto get_initializer() const -> const auto& { return initializer; }
};

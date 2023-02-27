#pragma once

#include <lang/ast/base_ast.h>

class namespace_stmt : public base_ast
{
    std::vector<std::string> id;
    std::vector<ast_ref> statements;

protected:
    auto do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result override;
    auto do_codegen(codegen_ctx& context) const -> codegen_value override;

public:
    namespace_stmt(code_location start, code_location end, std::vector<std::string> id, std::vector<ast_ref> statements);
    void visit_children(const std::function<void(const base_ast&)>& consumer) const override;
    auto serialize() const -> std::string override;

    [[nodiscard]] constexpr auto get_id() const -> const auto& { return id; }
    [[nodiscard]] constexpr auto get_statements() const -> const auto& { return statements; }
};

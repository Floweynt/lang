#pragma once

#include <lang/ast/base_ast.h>

class top_level_blk : public base_ast
{
    std::vector<ast_ref> statements;

protected:
    auto do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result override;
    auto do_codegen(codegen_ctx& context) const -> codegen_value override;

public:
    top_level_blk(code_location start, code_location end, std::vector<ast_ref> statements);
    void visit_children(const std::function<void(const base_ast&)>& consumer) const override;
    auto serialize() const -> std::string override;

    [[nodiscard]] constexpr auto get_statements() const -> const auto& { return statements; }
};

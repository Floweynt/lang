#pragma once
#include "base_ast.h"

class struct_literal_expr : public base_ast
{
    std::vector<ast_ref> members;

protected:
    auto do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result override;
    auto do_codegen(codegen_ctx& context) const -> codegen_value override;

public:
    struct_literal_expr(code_location start, code_location end, std::vector<ast_ref> members);
    void visit_children(const std::function<void(const base_ast&)>& consumer) const override;

    [[nodiscard]] constexpr auto get_members() const -> const auto& { return members; }
};

#pragma once

#include "lang/ast/base_ast.h"
#include "lang/sema/sema_ctx.h"
#include "lang/sema/types.h"

class block_expr : public base_ast
{
    std::vector<ast_ref> statements;

protected:
    auto do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result override;
    auto do_codegen(codegen_ctx& context) const -> codegen_value override;

public:
    block_expr(code_location start, code_location end, std::vector<ast_ref> statements);
    void visit_children(const std::function<void(const base_ast&)>& consumer) const override;
    auto serialize() const -> std::string override;

    auto deduce_return_type(sema_ctx& context) -> type_descriptor;
    auto deduce_break_type(sema_ctx& context) -> type_descriptor;

    [[nodiscard]] constexpr auto get_statements() const -> const auto& { return statements; }
};

#pragma once
#include "lang/ast/base_ast.h"
#include "lang/lexer/code_location.h"

class return_expr : public base_ast
{
    ast_ref value;

protected:
    auto do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result override;
    auto do_codegen(codegen_ctx& context) const -> codegen_value override;

public:
    return_expr(code_location start, code_location end, ast_ref value) : base_ast(start, end, RETURN_EXPR), value(std::move(value)) {}
    void visit_children(const std::function<void(const base_ast&)>& consumer) const override;

    [[nodiscard]] constexpr auto get_value() const -> const auto& { return value; }
};

#pragma once
#include "lang/ast/base_ast.h"
#include "lang/lexer/code_location.h"

class return_expr : public base_ast
{
    ast_ref value;
protected:
    semantic_analysis_result do_semantic_analysis(sema_ctx &c) const override;
public:
    return_expr(code_location start, code_location end, ast_ref value) : base_ast(start, end, RETURN_EXPR), value(std::move(value)) {}
    void visit_children(const std::function<void (const base_ast &)> &f) const override;

    [[nodiscard]] constexpr auto get_value() const -> const auto& { return value; }
};

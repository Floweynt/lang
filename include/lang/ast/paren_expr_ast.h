#pragma once

#include <lang/ast/base_ast.h>

class paren_expr : public base_ast
{
    ast_ref body;

protected:
    inline auto do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result override { return body->semantic_analysis(context); }
    inline auto do_consteval(sema_ctx& context) const -> ct_value override { return body->compiler_eval(context); }
    inline auto do_codegen(codegen_ctx& context) const -> codegen_value override { return body->codegen(context); }

public:
    inline paren_expr(code_location start, code_location end, ast_ref body) : base_ast(start, end, PAREN_EXPR), body(std::move(body)) {}
    inline void visit_children(const std::function<void(const base_ast&)>& consumer) const override { consumer(*body); }

    [[nodiscard]] constexpr auto get_body() const -> const auto& { return body; }
};

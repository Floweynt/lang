#pragma once
#include <lang/ast/base_ast.h>

class char_literal_expr : public base_ast
{
    char val;

protected:
    auto do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result override;
    auto do_consteval(sema_ctx& context) const -> ct_value override;
    auto do_codegen(codegen_ctx& context) const -> codegen_value override;

public:
    char_literal_expr(code_location start, code_location end, char val);
    void visit_children(const std::function<void(const base_ast&)>& consumer) const override;

    [[nodiscard]] constexpr auto get_value() const { return val; }
};

#pragma once

#include <lang/ast/base_ast.h>

class lang_name_ref_expr : public base_ast
{
    std::string name;

protected:
    auto do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result override;
    auto do_codegen(codegen_ctx& context) const -> codegen_value override;

public:
    lang_name_ref_expr(code_location start, code_location end, std::string name);
    void visit_children(const std::function<void(const base_ast&)>& consumer) const override;
    auto do_consteval(sema_ctx& context) const -> ct_value override;
    auto serialize() const -> std::string override;

    [[nodiscard]] constexpr auto get_name() const -> const auto& { return name; }
};

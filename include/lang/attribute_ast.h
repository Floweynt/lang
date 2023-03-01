#pragma once

#include "lang/ast/base_ast.h"

class attribute_entry_stmt : public base_ast
{
    std::string name;
    std::vector<ast_ref> args;

protected:
    auto do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result override;
    auto do_codegen(codegen_ctx& context) const -> codegen_value override;

public:
    attribute_entry_stmt(code_location start, code_location end, std::string name, std::vector<ast_ref> args);
    void visit_children(const std::function<void(const base_ast&)>& consumer) const override;
    auto serialize() const -> std::string override;

    constexpr auto get_name() const -> const auto& { return name; }
    constexpr auto get_args() const -> const auto& { return args; }
};

class attribute_list_stmt : public base_ast
{
    std::vector<ast_ref> attributes;

protected:
    auto do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result override;
    auto do_codegen(codegen_ctx& context) const -> codegen_value override;

public:
    attribute_list_stmt(code_location start, code_location end, std::vector<ast_ref> attributes);
    void visit_children(const std::function<void(const base_ast&)>& consumer) const override;
    auto serialize() const -> std::string override;

    constexpr auto get_attributes() const -> const auto& { return attributes; }
};

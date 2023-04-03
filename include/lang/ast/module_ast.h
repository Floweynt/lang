#pragma once

#include "lang/ast/base_ast.h"
#include "lang/ast/top_level_blk_ast.h"
#include "lang/lexer/code_location.h"
#include <string>
#include <vector>

class module_ast : public base_ast
{
    std::vector<std::vector<std::string>> module_imports;
    ast_ref block;

protected:
    auto do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result override;
    auto do_codegen(codegen_ctx& context) const -> codegen_value override;

public:
    module_ast(code_location start, code_location end, std::vector<std::vector<std::string>> module_imports, ast_ref block);

    void visit_children(const std::function<void(const base_ast&)>& consumer) const override;
    auto serialize() const -> std::string override;

    constexpr auto get_module_imports() const -> const auto& { return module_imports; }
    constexpr auto get_block() const -> const auto& { return block; }
};

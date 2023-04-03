#pragma once

#include "lang/ast/base_ast.h"
#include "lang/codegen/codegen_ctx.h"

class using_expr : public base_ast
{
    std::string name;
    ast_ref type;

    std::vector<ast_ref> args;

protected:
    auto do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result override;
    inline auto do_codegen(codegen_ctx& /*context*/) const -> codegen_value override
    {
        return codegen_value::make_null(); // we dont need to do anything
    }

public:
    using_expr(code_location start, code_location end, std::string name, ast_ref initializer, std::vector<ast_ref> args);
    void visit_children(const std::function<void(const base_ast&)>& consumer) const override;
    auto serialize() const -> std::string override;
};

#pragma once

#include "lang/sema/sema_ctx.h"
#include "lang/sema/types.h"
#include <lang/ast/base_ast.h>

class block_expr : public base_ast
{
    std::vector<ast_ref> statements;

protected:
    virtual semantic_analysis_result do_semantic_analysis(sema_ctx& c) const override;

public:
    block_expr(code_location start, code_location end, std::vector<ast_ref> statements);
    virtual void visit_children(const std::function<void(const base_ast&)>& f) const override;
    virtual type_descriptor deduce_return_type(sema_ctx& c);

    constexpr const auto& get_statements() const { return statements; }
};

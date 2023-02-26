#include "lang/ast/namespace_stmt_ast.h"
#include "lang/codegen/codegen_ctx.h"
#include "lang/sema/types.h"
#include <llvm/IR/Constants.h>

auto namespace_stmt::do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result
{
    bool is_valid = true;
    for (const auto& stmt : statements)
    {
        is_valid = is_valid && stmt->semantic_analysis(context).is_valid;
    }
    return {context.langtype(primitive_type::UNIT), is_valid};
}

namespace_stmt::namespace_stmt(code_location start, code_location end, std::vector<std::string> id, std::vector<ast_ref> statements)
    : base_ast(start, end, NS_STMT), id(std::move(id)), statements(std::move(statements))
{
}

void namespace_stmt::visit_children(const std::function<void(const base_ast&)>& consumer) const
{
    for (const auto& stmt : statements)
    {
        consumer(*stmt);
    }
}

auto namespace_stmt::do_codegen(codegen_ctx& context) const -> codegen_value
{
    // TODO: push and pop namespace
    for (const auto& stmt : statements)
    {
        stmt->codegen(context);
    }
    return codegen_value::make_null();
}

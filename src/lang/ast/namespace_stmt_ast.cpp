#include "lang/ast/namespace_stmt_ast.h"
#include "lang/sema/types.h"

semantic_analysis_result namespace_stmt::do_semantic_analysis(sema_ctx& c) const
{
    bool is_valid = true;
    for (const auto& i : statements)
        is_valid &= i->semantic_analysis(c).is_valid;
    return {c.langtype(primitive_type::UNIT), is_valid};
}

namespace_stmt::namespace_stmt(code_location start, code_location end, std::vector<std::string> id, std::vector<ast_ref> statements)
    : base_ast(start, end, NS_STMT), id(std::move(id)), statements(std::move(statements))
{
}

void namespace_stmt::visit_children(const std::function<void(const base_ast&)>& f) const
{
    for (const auto& i : statements)
        f(*i);
}

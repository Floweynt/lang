#include "lang/ast/struct_literal_expr.h"
#include "lang/sema/types.h"

semantic_analysis_result struct_literal_expr::do_semantic_analysis(sema_ctx& c) const
{
    bool is_valid = true;
    for (const auto& i : members)
        is_valid &= i->semantic_analysis(c).is_valid;

    return {c.langtype(primitive_type::META), is_valid};
}

struct_literal_expr::struct_literal_expr(code_location start, code_location end, std::vector<ast_ref> members)
    : base_ast(start, end, STRUCT_LITERAL_EXPR), members(std::move(members))
{
}

void struct_literal_expr::visit_children(const std::function<void(const base_ast&)>& f) const
{
    for (const auto& i : members)
        f(*i);
}

#include "lang/ast/control/yield_expr_ast.h"
#include "lang/sema/types.h"

auto yield_expr::do_semantic_analysis(sema_ctx& c) const -> semantic_analysis_result
{
    return {c.langtype(primitive_type::UNIT), value->semantic_analysis(c).is_valid};
}

void yield_expr::visit_children(const std::function<void(const base_ast&)>& f) const { f(*value); }

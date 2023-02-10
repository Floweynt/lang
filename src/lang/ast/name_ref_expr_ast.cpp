#include "lang/ast/name_ref_expr_ast.h"
#include "lang/sema/types.h"

semantic_analysis_result name_ref_expr::do_semantic_analysis(sema_ctx& c) const
{
    auto p = c.get_variable(name);

    if (p == c.langtype(primitive_type::META))
    {
        return {p, p != c.langtype(primitive_type::ERROR), true};
    }

    return {p, p != c.langtype(primitive_type::ERROR)};
}

ct_value name_ref_expr::do_consteval(sema_ctx& c) const { return c.get_comptime_value(name); }

name_ref_expr::name_ref_expr(code_location start, code_location end, const std::string& name) : base_ast(start, end, NAME_REF), name(name) {}

void name_ref_expr::visit_children(const std::function<void(const base_ast&)>& f) const {}

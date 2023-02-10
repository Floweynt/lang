#include "lang/ast/lang_name_ref_expr_ast.h"
#include "lang/sema/types.h"

semantic_analysis_result lang_name_ref_expr::do_semantic_analysis(sema_ctx& c) const
{
    auto p = c.query_lang_id_type(name);

    if (p == c.langtype(primitive_type::ERROR))
        c.get_compiler_ctx().report_error(error{range(), "unable to access language feature \'" + name + "\'"});

    return {c.langtype(primitive_type::META), p != c.langtype(primitive_type::ERROR), true};
}

lang_name_ref_expr::lang_name_ref_expr(code_location start, code_location end, const std::string& name)
    : base_ast(start, end, LANG_NAME_REF), name(name)
{
}

void lang_name_ref_expr::visit_children(const std::function<void(const base_ast&)>& f) const {}

ct_value lang_name_ref_expr::do_consteval(sema_ctx& c) const { return {c.langtype(primitive_type::META), c.query_lang_id_type(name)}; }

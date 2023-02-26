#include "lang/ast/control/return_expr_ast.h"
#include "lang/sema/types.h"

auto return_expr::do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result
{
    return {context.langtype(primitive_type::UNIT), value->semantic_analysis(context).is_valid};
}

void return_expr::visit_children(const std::function<void(const base_ast&)>& consumer) const { consumer(*value); }

auto return_expr::do_codegen(codegen_ctx& context) const -> codegen_value
{
    context.builder().CreateRet(value->codegen(context).get_value(context));
    context.set_unreachable();
    return context.get_void_val();
}

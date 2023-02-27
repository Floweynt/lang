#include "lang/ast/control/yield_expr_ast.h"
#include "lang/sema/types.h"

auto yield_expr::do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result
{
    return {context.langtype(primitive_type::UNIT), value->semantic_analysis(context).is_valid};
}

void yield_expr::visit_children(const std::function<void(const base_ast&)>& consumer) const { consumer(*value); }

auto yield_expr::do_codegen(codegen_ctx& context) const -> codegen_value
{
    value->codegen(context);
    return context.get_void_val();
}

auto yield_expr::serialize() const -> std::string { return fmt::format("(yield_expression {})", value->serialize()); }

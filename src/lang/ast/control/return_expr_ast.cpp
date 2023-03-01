#include "lang/ast/control/return_expr_ast.h"
#include "lang/sema/types.h"
#include <llvm/IR/BasicBlock.h>

auto return_expr::do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result
{
    return {context.langtype(primitive_type::UNIT), value->semantic_analysis(context).is_valid};
}

void return_expr::visit_children(const std::function<void(const base_ast&)>& consumer) const { consumer(*value); }

auto return_expr::do_codegen(codegen_ctx& context) const -> codegen_value
{
    auto return_value = value->codegen(context);
    context.builder().CreateRet(context.convert_to(context.get_func_return_ty(), return_value).get_value(context));
    context.insert_to_new_block("post_ret_unreachable");
    return context.get_void_val();
}

auto return_expr::serialize() const -> std::string { return fmt::format("(return_expression {})", value ? value->serialize() : "null"); }

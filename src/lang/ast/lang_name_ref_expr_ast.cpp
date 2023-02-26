#include "lang/ast/lang_name_ref_expr_ast.h"
#include "lang/codegen/codegen_ctx.h"
#include "lang/sema/types.h"
#include <llvm/IR/Value.h>
#include <stdexcept>

auto lang_name_ref_expr::do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result
{
    const auto* type = context.query_lang_id_type(name);

    if (type == context.langtype(primitive_type::ERROR))
    {
        context.get_compiler_ctx().report_error(error{range(), "unable to access language feature \'" + name + "\'"});
    }

    return {context.langtype(primitive_type::META), type != context.langtype(primitive_type::ERROR), true};
}

lang_name_ref_expr::lang_name_ref_expr(code_location start, code_location end, const std::string& name)
    : base_ast(start, end, LANG_NAME_REF), name(name)
{
}

void lang_name_ref_expr::visit_children(const std::function<void(const base_ast&)>& consumer) const {}

auto lang_name_ref_expr::do_consteval(sema_ctx& context) const -> ct_value
{
    return {context.langtype(primitive_type::META), context.query_lang_id_type(name)};
}

auto lang_name_ref_expr::do_codegen(codegen_ctx& /*context*/) const -> codegen_value { throw std::runtime_error("todo: implement"); }

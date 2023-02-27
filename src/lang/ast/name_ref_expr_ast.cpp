#include "lang/ast/name_ref_expr_ast.h"

#include "lang/sema/types.h"
#include <utility>

auto name_ref_expr::do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result
{
    const auto* type = context.get_variable(name);
    if (type == context.langtype(primitive_type::ERROR))
    {
        context.get_compiler_ctx().report_error({
            range(),
            "unknown name '" + name + "'",
        });
    }
    else if (type == context.langtype(primitive_type::META))
    {
        return {type, type != context.langtype(primitive_type::ERROR), true};
    }

    return {type, type != context.langtype(primitive_type::ERROR)};
}

auto name_ref_expr::do_consteval(sema_ctx& context) const -> ct_value { return context.get_comptime_value(name); }

name_ref_expr::name_ref_expr(code_location start, code_location end, std::string name) : base_ast(start, end, NAME_REF), name(std::move(name)) {}

void name_ref_expr::visit_children(const std::function<void(const base_ast&)>& consumer) const {}

auto name_ref_expr::do_codegen(codegen_ctx& context) const -> codegen_value { return context.get_variable(name); }

auto name_ref_expr::serialize() const -> std::string { return fmt::format("(name_reference \"{}\")", name); }

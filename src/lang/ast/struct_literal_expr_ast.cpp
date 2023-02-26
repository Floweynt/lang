#include "lang/ast/struct_literal_expr.h"
#include "lang/sema/types.h"
#include <stdexcept>

auto struct_literal_expr::do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result
{
    bool is_valid = true;
    for (const auto& member : members)
    {
        is_valid &= member->semantic_analysis(context).is_valid;
    }

    return {context.langtype(primitive_type::META), is_valid};
}

struct_literal_expr::struct_literal_expr(code_location start, code_location end, std::vector<ast_ref> members)
    : base_ast(start, end, STRUCT_LITERAL_EXPR), members(std::move(members))
{
}

void struct_literal_expr::visit_children(const std::function<void(const base_ast&)>& consumer) const
{
    for (const auto& member : members)
    {
        consumer(*member);
    }
}

auto struct_literal_expr::do_codegen(codegen_ctx& context) const -> codegen_value { throw std::runtime_error("internal error: do not do codegen"); }

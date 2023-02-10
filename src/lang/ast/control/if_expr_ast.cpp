#include "lang/ast/control/if_expr_ast.h"
#include "lang/lexer/code_location.h"
#include "lang/sema/types.h"
#include <optional>

semantic_analysis_result if_expr::do_semantic_analysis(sema_ctx& c) const
{
    bool works = true;

    type_descriptor return_type = nullptr;

    for (const auto& i : branches)
    {
        auto [predicate_type, is_pred_valid, _] = i.first->semantic_analysis(c);
        if (is_pred_valid &&
            !(c.exists_conversion(predicate_type, c.langtype(primitive_type::BOOL)) || predicate_type == c.langtype(primitive_type::BOOL)))
            c.get_compiler_ctx().report_error(error{
                i.first->range(),
                "unable to convert predicate type to bool; either no conversion was found, or you messed up the type (type is '" +
                    predicate_type->get_name() + "')",
                std::nullopt,
            });

        auto [body_type, is_body_valid, _2] = i.second->semantic_analysis(c);
        works &= is_body_valid & is_body_valid;

        if (!return_type)
            return_type = body_type;
        if (return_type != body_type && return_type != c.langtype(primitive_type::UNIT))
            return_type = c.langtype(primitive_type::UNIT);
    }

    if (else_branch)
    {
        auto [else_type, is_valid, _] = else_branch->semantic_analysis(c);
        works &= is_valid;
        if (else_type != return_type)
            return_type = c.langtype(primitive_type::UNIT);
    }
    else
        return_type = c.langtype(primitive_type::UNIT);

    return {return_type, works};
}

if_expr::if_expr(code_location start, code_location end, std::vector<std::pair<ast_ref, ast_ref>> branches, ast_ref else_branch)
    : base_ast(start, end, IF_EXPR, false), branches(std::move(branches)), else_branch(std::move(else_branch))
{
}

void if_expr::visit_children(const std::function<void(const base_ast&)>& f) const
{
    for (const auto& i : branches)
    {
        f(*i.first);
        f(*i.second);
    }

    if (else_branch)
        f(*else_branch);
}

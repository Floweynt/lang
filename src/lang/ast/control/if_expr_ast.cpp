#include "lang/ast/control/if_expr_ast.h"
#include "lang/lexer/code_location.h"
#include "lang/sema/types.h"
#include <optional>

auto if_expr::do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result
{
    bool works = true;

    type_descriptor return_type = nullptr;

    for (const auto& branch : branches)
    {
        auto [predicate_type, is_pred_valid, _] = branch.first->semantic_analysis(context);
        if (is_pred_valid && !context.exists_conversion(predicate_type, context.langtype(primitive_type::BOOL)) &&
            predicate_type != context.langtype(primitive_type::BOOL))
        {
            context.get_compiler_ctx().report_error(error{
                branch.first->range(),
                "unable to convert predicate type to bool; either no conversion was found, or you messed up the type (type is '" +
                    predicate_type->get_name() + "')",
                std::nullopt,
            });
        }

        auto [body_type, is_body_valid, _2] = branch.second->semantic_analysis(context);
        works = works && is_body_valid && is_pred_valid;

        if (return_type == nullptr)
        {
            return_type = body_type;
        }
        if (return_type != body_type && return_type != context.langtype(primitive_type::UNIT))
        {
            return_type = context.langtype(primitive_type::UNIT);
        }
    }

    if (else_branch)
    {
        auto [else_type, is_valid, _] = else_branch->semantic_analysis(context);
        works &= is_valid;
        if (else_type != return_type)
        {
            return_type = context.langtype(primitive_type::UNIT);
        }
    }
    else
    {
        return_type = context.langtype(primitive_type::UNIT);
    }

    return {return_type, works};
}

if_expr::if_expr(code_location start, code_location end, std::vector<std::pair<ast_ref, ast_ref>> branches, ast_ref else_branch)
    : base_ast(start, end, IF_EXPR, false), branches(std::move(branches)), else_branch(std::move(else_branch))
{
}

void if_expr::visit_children(const std::function<void(const base_ast&)>& consumer) const
{
    for (const auto& branch : branches)
    {
        consumer(*branch.first);
        consumer(*branch.second);
    }

    if (else_branch)
    {
        consumer(*else_branch);
    }
}

auto if_expr::do_codegen(codegen_ctx& context) const -> codegen_value { throw std::runtime_error("todo: implement if_expr codegen"); }

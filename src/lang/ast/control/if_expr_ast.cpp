#include "lang/ast/control/if_expr_ast.h"
#include "lang/codegen/codegen_ctx.h"
#include "lang/lexer/code_location.h"
#include "lang/sema/types.h"
#include <fmt/ranges.h>
#include <llvm/IR/BasicBlock.h>
#include <optional>
#include <ranges>

auto if_expr::do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result
{
    bool works = true;

    type_descriptor return_type = nullptr;

    for (const auto& branch : branches)
    {
        auto [predicate_type, is_pred_valid, _] = branch.first->semantic_analysis(context);
        if (is_pred_valid && !context.exists_conversion(predicate_type, context.langtype(primitive_type::BOOL)))
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

/*
void do_codegen_for_branch(codegen_ctx& context, const ast_ref& condition, const ast_ref& body, auto next)
{
    auto *br_inst_bb = llvm::BasicBlock::Create(context.llvm_ctx(), "", context.builder().GetInsertBlock()->getParent());
    auto *br_then = llvm::BasicBlock::Create(context.llvm_ctx(), "", context.builder().GetInsertBlock()->getParent());
    auto *br_else = llvm::BasicBlock::Create(context.llvm_ctx(), "", context.builder().GetInsertBlock()->getParent());
    auto *exit_point = llvm::BasicBlock::Create(context.llvm_ctx(), "", context.builder().GetInsertBlock()->getParent());

    context.builder().SetInsertPoint(br_inst_bb);
    context.builder().CreateCondBr(condition->codegen(context).get_value(context), br_then, br_else);

    // me must emit the main branch
    context.builder().SetInsertPoint(br_then);
    body->codegen(context);

    if(context.builder().GetInsertBlock()->getTerminator() == nullptr)
    {
        context.builder().CreateBr(exit_point);
    }

    context.builder().SetInsertPoint(br_else);



    if(context.)

    context.builder().SetInsertPoint(exit_point);
}*/

auto if_expr::do_codegen(codegen_ctx& context) const -> codegen_value
{
    auto* if_entry = context.make_new_block("if_entry");

    if (context.get_insert_block()->getTerminator() == nullptr)
    {
        context.builder().CreateBr(if_entry);
    }

    context.set_insert_block(if_entry);
    auto* if_exit = context.make_new_block("if_exit");

    for (size_t i = 0; i < branches.size(); i++)
    {
        auto* predicate = branches[i].first->codegen(context).get_value(context);
        auto* if_body = context.make_new_block("if_body_br_" + std::to_string(i));
        auto* else_body = context.make_new_block("else_body_br_" + std::to_string(i));

        context.builder().CreateCondBr(predicate, if_body, else_body);

        context.set_insert_block(if_body);
        (void)branches[i].second->codegen(context);

        if (context.get_insert_block()->getTerminator() == nullptr)
        {
            context.builder().CreateBr(if_exit);
        }

        // we must start inserting at the else branch
        context.set_insert_block(if_entry = else_body);
    }

    if (else_branch)
    {
        else_branch->codegen(context);
    }

    if (context.get_insert_block()->getTerminator() == nullptr)
    {
        context.builder().CreateBr(if_exit);
    }

    context.set_insert_block(if_exit);

    return context.get_void_val();
}

auto if_expr::serialize() const -> std::string
{
    return fmt::format("(if_expression ({}) {})",
                       fmt::join(branches | std::views::transform([](const std::pair<ast_ref, ast_ref>& ref) {
                                     return fmt::format("({} {})", ref.first->serialize(), ref.second->serialize());
                                 }),
                                 " "),
                       else_branch ? else_branch->serialize() : "null");
}

#include "lang/ast/control/while_expr_ast.h"
#include "lang/ast/block_expr_ast.h"
#include "lang/ast/control/if_expr_ast.h"
#include "lang/lexer/code_location.h"
#include "lang/sema/types.h"
#include <optional>
#include <stdexcept>

auto while_expr::do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result
{
    bool works = true;

    type_descriptor return_type = nullptr;

    auto [_0, body_works, _1] = body->semantic_analysis(context);
    works = works && body_works;

    if (dynamic_cast<block_expr*>(body.get()) != nullptr)
    {
        return_type = dynamic_cast<block_expr*>(body.get())->deduce_break_type(context);
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

while_expr::while_expr(code_location start, code_location end, ast_ref condition, ast_ref body, ast_ref else_branch)
    : base_ast(start, end, WHILE_EXPR, false), condition(std::move(condition)), body(std::move(body)), else_branch(std::move(else_branch))
{
}

void while_expr::visit_children(const std::function<void(const base_ast&)>& consumer) const
{
    consumer(*condition);
    consumer(*body);
    if (else_branch)
    {
        consumer(*else_branch);
    }
}

auto while_expr::do_codegen(codegen_ctx& context) const -> codegen_value { throw std::runtime_error("todo: implement while codegen"); }

auto while_expr::serialize() const -> std::string
{
    return fmt::format("(while_expression {} {} {})", condition->serialize(), body->serialize(), else_branch ? else_branch->serialize() : "null");
}

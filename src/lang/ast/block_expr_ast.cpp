#include "lang/ast/block_expr_ast.h"
#include "lang/ast/base_ast.h"
#include "lang/ast/control/return_expr_ast.h"
#include "lang/ast/control/yield_expr_ast.h"
#include "lang/raii_guard.h"
#include "lang/sema/types.h"
#include "lang/utils/utils.h"
#include "lang/y_comb.h"
#include <fmt/ranges.h>
#include <functional>
#include <ranges>

block_expr::block_expr(code_location start, code_location end, std::vector<ast_ref> statements)
    : base_ast(start, end, BLOCK_EXPR, false), statements(std::move(statements))
{
}

void block_expr::visit_children(const std::function<void(const base_ast&)>& consumer) const
{
    for (const auto& stmt : statements)
    {
        consumer(*stmt);
    }
}

auto block_expr::do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result
{
    context.push_local_stack();
    raii_guard guard([&context]() { context.pop_local_stack(); });

    bool is_fn = context.is_function();

    // we are no longer in the top-level block of a function, so clear this flag
    context.set_function(false);

    bool sema_success = true;
    type_descriptor type = context.langtype(primitive_type::UNIT);

    // we want to do semantic analysis for all subexpressions
    for (const auto& stmt : statements)
    {
        auto [_t, result, _t, _t] = stmt->semantic_analysis(context);
        sema_success &= result;

        if (stmt->get_ast_kind() == YIELD_EXPR)
        {
            if (is_fn)
            {
                context.get_compiler_ctx().report_diagnostic(
                    {{context.get_compiler_ctx().get_current_file(), stmt->range(),
                      "yield expressions are not allowed within the top-level blocks; use 'return' if you want to return a value"},
                     {},
                     {}});
            }

            if (type == context.langtype(primitive_type::UNIT))
            {
                type = (dynamic_cast<yield_expr*>(stmt.get()))->semantic_analysis(context).ty;
            }
            else
            {
                context.get_compiler_ctx().report_diagnostic(
                    {{context.get_compiler_ctx().get_current_file(), stmt->range(),
                      "only one yield expression permitted within the statements of a block (yields in nested blocks are ok)"},
                     {},
                     {}});
                sema_success = false;
            }
        }
    }

    // reset the value supplied
    context.set_function(is_fn);

    return {type, sema_success};
}

auto block_expr::deduce_return_type(sema_ctx& context) -> type_descriptor
{
    std::vector<type_descriptor> return_types_list;

    struct visitor
    {
        std::vector<type_descriptor>& return_types_list;

        void operator()(const base_ast& ast)
        {
            if (ast.get_ast_kind() == RETURN_EXPR)
            {
                return_types_list.push_back(dynamic_cast<const return_expr&>(ast).get_value()->get_sema_result().ty);
            }
            else
            {
                ast.visit_children(*this);
            }
        }
    };

    visit_children(visitor{return_types_list});

    if (return_types_list.empty())
    {
        return context.langtype(primitive_type::UNIT);
    }

    bool flag = true;
    const auto* first_ty = return_types_list.front();
    for (const auto* type : return_types_list)
    {
        if (first_ty != type)
        {
            flag = false;
            break;
        }
    }

    if (!flag)
    {
        context.get_compiler_ctx().report_diagnostic(
            {{context.get_compiler_ctx().get_current_file(), range(),
              "failed to deduce return type; return type deduction requires that all return statements return a value of identical types"},
             {},
             {}});
        return context.langtype(primitive_type::ERROR);
    }

    return first_ty;
}

auto block_expr::deduce_break_type(sema_ctx& context) -> type_descriptor
{
    // okay, we have to recursively visit all child nodes, and check if they are a return expressions

    // TODO: impl
    return context.langtype(primitive_type::UNIT);
}

auto block_expr::do_codegen(codegen_ctx& context) const -> codegen_value
{
    codegen_value return_val = context.get_void_val();
    for (const auto& stmt : statements)
    {
        stmt->codegen(context);
        if (stmt->get_ast_kind() == YIELD_EXPR)
        {
            return_val = dynamic_cast<yield_expr*>(stmt.get())->get_value()->get_codegen_result();
        }
    }

    return return_val;
}

auto block_expr::serialize() const -> std::string
{
    return fmt::format("(block_expression ({}))",
                       fmt::join(statements | std::views::transform([](const ast_ref& ref) { return ref->serialize(); }), " "));
}

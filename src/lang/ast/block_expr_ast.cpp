

#include "lang/ast/block_expr_ast.h"
#include "lang/ast/base_ast.h"
#include "lang/ast/control/yield_expr_ast.h"
#include "lang/raii_guard.h"
#include "lang/sema/types.h"
#include <functional>

block_expr::block_expr(code_location start, code_location end, std::vector<ast_ref> statements)
    : base_ast(start, end, BLOCK_EXPR, false), statements(std::move(statements))
{
}

void block_expr::visit_children(const std::function<void(const base_ast&)>& f) const
{
    for (const auto& i : statements)
        f(*i);
}

semantic_analysis_result block_expr::do_semantic_analysis(sema_ctx& c) const
{
    c.push_local_stack();
    raii_guard g([&c]() { c.pop_local_stack(); });

    bool is_fn = c.is_function;

    // we are no longer in the top-level block of a function, so clear this flag
    c.is_function = false;

    bool sema_success = true;
    type_descriptor type = c.langtype(primitive_type::UNIT);

    // we want to do semantic analysis for all subexpressions
    for (const auto& i : statements)
    {
        auto [_0, result, _1] = i->semantic_analysis(c);
        sema_success &= result;

        if (i->get_ast_kind() == YIELD_EXPR)
        {
            if (is_fn)
            {
                c.get_compiler_ctx().report_error(error{
                    i->range(), "yield expressions are not allowed within the top-level blocks; use 'return' if you want to return a value", {}});
            }

            if (type == c.langtype(primitive_type::UNIT))
            {
                type = (dynamic_cast<yield_expr*>(i.get()))->semantic_analysis(c).ty;
            }
            else
            {
                c.get_compiler_ctx().report_error(
                    error{i->range(), "only one yield expression permitted within the statements of a block (yields in nested blocks are ok)"});
                sema_success = false;
            }
        }
    }

    // reset the value supplied
    c.is_function = is_fn;

    return {type, sema_success};
}

type_descriptor block_expr::deduce_return_type(sema_ctx& c)
{
    // okay, we have to recursively visit all child nodes, and check if they are a return expressions

    // TODO: impl
    return c.langtype(primitive_type::UNIT);
}

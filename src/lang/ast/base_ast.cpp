#include "lang/ast/base_ast.h"
#include "lang/sema/sema_ctx.h"
#include <stdexcept>

auto base_ast::do_consteval(sema_ctx& /* */) const -> ct_value { throw std::runtime_error("cannot do consteval"); }

auto base_ast::semantic_analysis(sema_ctx& context) const -> const semantic_analysis_result&
{
    const auto* parent = context.get_ast_stack().top();
    context.push_ast(this);
    if (!sema_result)
    {
        sema_result = do_semantic_analysis(context);
    }
    context.pop_ast();

    if (sema_result->ty->is_builtin_function() && parent->get_ast_kind() != FUNCTION_CALL_EXPR)
    {
        context.get_compiler_ctx().report_diagnostic(
            {{context.get_compiler_ctx().get_current_file(), range(), "builtin function must be immediately called"}});
    }

    return *sema_result;
}

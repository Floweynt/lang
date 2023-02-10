#include "lang/ast/using_expr_ast.h"
#include "lang/sema/types.h"
#include <stdexcept>

semantic_analysis_result using_expr::do_semantic_analysis(sema_ctx& c) const
{
    auto [ty, is_valid, is_consteval] = type->semantic_analysis(c);
    if (ty != c.langtype(primitive_type::META))
    {
        c.get_compiler_ctx().report_error(error{
            type->range(),
            "type specifier must refer to a type (the expressions should have type 'metatype', but got \'" + ty->get_name() + "\')",
            std::nullopt,
        });
        return {c.langtype(primitive_type::UNIT), false};
    }

    if(!is_consteval)
        throw std::runtime_error("internal error: metatype should be consteval");

    c.add_comptime_value(name, type->do_consteval(c));
    return {c.langtype(primitive_type::UNIT), is_valid};
}

using_expr::using_expr(code_location start, code_location end, std::string name, ast_ref initializer, std::vector<ast_ref> args)
    : base_ast(start, end, USING_STMT), name(name), type(std::move(initializer)), args(std::move(args))
{
}

void using_expr::visit_children(const std::function<void(const base_ast&)>& f) const
{
    f(*type);
    for (const auto& i : args)
        f(*i);
}

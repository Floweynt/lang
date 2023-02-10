#include "lang/ast/variable_decl_expr_ast.h"
#include "lang/ast/base_ast.h"
#include "lang/sema/types.h"
#include <stdexcept>

semantic_analysis_result variable_decl_expr::do_semantic_analysis(sema_ctx& c) const
{
    type_descriptor type;

    if (ty->get_ast_kind() == AUTO_KW)
    {
        if (!initializer)
        {
            c.get_compiler_ctx().report_error(error{
                range(),
                "unable to use auto keyword without initializer: cannot deduce type",
            });
            return {c.langtype(primitive_type::ERROR), false};
        }

        auto [init_type, is_init_valid, _] = initializer->semantic_analysis(c);
        if (!is_init_valid)
            return {init_type, false};

        type = init_type;
    }
    else
    {
        auto [start, end, can_consteval] = ty->semantic_analysis(c);
        if (start != c.langtype(primitive_type::META))
        {
            c.get_compiler_ctx().report_error(error{
                ty->range(),
                "type specifier should be of type metatype; either insert decltype(...), or fix the type signature",
            });

            return {c.langtype(primitive_type::ERROR), false};
        }

        if (!can_consteval)
            throw std::runtime_error("internal error: metatype related function should be comptime");

        auto value = ty->do_consteval(c);
        type = value.get_value<type_descriptor>();
    }

    if (!c.add_variable(name, type))
    {
        c.get_compiler_ctx().report_error(error{
            range(),
            "duplicate variable name declared; the variable has been previously declared",
        });
        return {type, false};
    }

    return {type, true};
}

variable_decl_expr::variable_decl_expr(code_location start, code_location end, std::string name, std::vector<ast_ref> modifiers, ast_ref ty,
                                       ast_ref initializer, bool is_packed)
    : base_ast(start, end, VARIABLE_DECL_STMT), name(name), modifiers(std::move(modifiers)), ty(std::move(ty)), is_packed(is_packed),
      initializer(std::move(initializer))
{
}

void variable_decl_expr::visit_children(const std::function<void(const base_ast&)>& f) const
{
    for (const auto& i : modifiers)
        f(*i);
    f(*ty);
    if (initializer)
        f(*initializer);
}

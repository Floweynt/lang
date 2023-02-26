#include "lang/ast/variable_decl_expr_ast.h"
#include "lang/ast/base_ast.h"
#include "lang/codegen/codegen_value.h"
#include "lang/sema/types.h"
#include <stdexcept>
#include <utility>

auto variable_decl_expr::do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result
{
    type_descriptor type = nullptr;

    if (ty->get_ast_kind() == AUTO_KW)
    {
        if (!initializer)
        {
            context.get_compiler_ctx().report_error(error{
                range(),
                "unable to use auto keyword without initializer: cannot deduce type",
            });
            return {context.langtype(primitive_type::ERROR), false};
        }

        auto [init_type, is_init_valid, _] = initializer->semantic_analysis(context);
        if (!is_init_valid)
        {
            return {init_type, false};
        }

        type = init_type;
    }
    else
    {
        auto [start, end, can_consteval] = ty->semantic_analysis(context);
        if (start != context.langtype(primitive_type::META))
        {
            context.get_compiler_ctx().report_error(error{
                ty->range(),
                "type specifier should be of type metatype; either insert decltype(...), or fix the type signature",
            });

            return {context.langtype(primitive_type::ERROR), false};
        }

        if (!can_consteval)
        {
            throw std::runtime_error("internal error: metatype related function should be comptime");
        }

        auto value = ty->compiler_eval(context);
        type = value.get_value<type_descriptor>();
    }

    if (!context.add_variable(name, type))
    {
        context.get_compiler_ctx().report_error(error{
            range(),
            "duplicate variable name declared; the variable has been previously declared",
        });
        return {type, false};
    }

    return {type, true};
}

variable_decl_expr::variable_decl_expr(code_location start, code_location end, std::string name, std::vector<ast_ref> modifiers, ast_ref ty,
                                       ast_ref initializer, bool is_packed)
    : base_ast(start, end, VARIABLE_DECL_STMT), name(std::move(name)), modifiers(std::move(modifiers)), ty(std::move(ty)), is_packed(is_packed),
      initializer(std::move(initializer))
{
}

void variable_decl_expr::visit_children(const std::function<void(const base_ast&)>& consumer) const
{
    for (const auto& modifier : modifiers)
    {
        consumer(*modifier);
    }
    consumer(*ty);
    if (initializer)
    {
        consumer(*initializer);
    }
}

auto variable_decl_expr::do_codegen(codegen_ctx& context) const -> codegen_value
{
    auto var = codegen_value::make_local(context, get_sema_result().ty, initializer ? initializer->codegen(context) : std::optional<codegen_value>(),
                                         "local_" + name);
    context.add_variable(name, var);
    return var;
}

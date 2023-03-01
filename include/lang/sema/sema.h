#pragma once

#include "lang/ast/base_ast.h"
#include "lang/ast/block_expr_ast.h"
#include "lang/ast/control/return_expr_ast.h"
#include "lang/sema/sema_ctx.h"
#include "lang/sema/types.h"

inline auto do_sema_func(sema_ctx& context, const std::vector<ast_ref>& args, const ast_ref& body, const ast_ref& return_type,
                         const std::string& name) -> semantic_analysis_result
{
    std::vector<type_descriptor> arg_types;
    bool is_valid = false;
    bool should_fail = false;

    context.push_local_stack();
    for (const auto& arg : args)
    {
        auto [arg_type, valid, _] = arg->semantic_analysis(context);
        arg_types.push_back(arg_type);

        if (arg_type == context.langtype(primitive_type::ERROR))
        {
            should_fail = true;
        }
        is_valid &= valid;
    }

    type_descriptor return_ty = nullptr; // this should be deduced

    auto [_1, body_valid, _2] = body->semantic_analysis(context);
    context.pop_local_stack();

    if (return_type)
    {
        auto [return_type_specifier_ty, return_type_valid, can_consteval] = return_type->semantic_analysis(context);

        if (return_type_specifier_ty != context.langtype(primitive_type::META))
        {
            context.get_compiler_ctx().report_error(error{
                return_type->range(),
                "type specifier must refer to a type (the expressions should have type 'metatype', but got \'" +
                    return_type_specifier_ty->get_name() + "\')",
                std::nullopt,
            });

            return {context.make_simple_lambda_function(context.langtype(primitive_type::ERROR), arg_types), false};
        }

        if (!can_consteval)
        {
            throw std::runtime_error("internal error: meta type must be consteval");
        }

        return_ty = return_type->compiler_eval(context).get_value<type_descriptor>();

        struct visitor
        {
            sema_ctx& context;
            type_descriptor return_ty;
            bool valid;

            void operator()(const base_ast& ast)
            {
                if (ast.get_ast_kind() == RETURN_EXPR)
                {
                    const auto* returned_ty = dynamic_cast<const return_expr&>(ast).get_value()->get_sema_result().ty;
                    if (!context.exists_conversion(returned_ty, return_ty))
                    {
                        valid = false;
                        context.get_compiler_ctx().report_error({
                            ast.range(),
                            "type returned '" + returned_ty->get_name() + "' cannot be converted to specified return type of '" +
                                return_ty->get_name() + "'",
                        });
                    }
                }
                else
                {
                    ast.visit_children(*this);
                }
            }
        };

        visitor my_visitor{context, return_ty, true};
        my_visitor(*body);

        if (!my_visitor.valid)
        {
            body_valid = false;
        }
    }
    else
    {
        return_ty = dynamic_cast<block_expr*>(body.get())->deduce_return_type(context);
        if (return_ty == context.langtype(primitive_type::ERROR))
        {
            return {context.make_simple_lambda_function(return_ty, arg_types), false};
        }
    }

    if (!body_valid)
    {
        return {context.make_simple_lambda_function(return_ty, arg_types), false};
    }

    if (!name.empty())
    {
        context.add_variable(name, context.make_simple_lambda_function(return_ty, arg_types));
    }

    return {should_fail ? context.langtype(primitive_type::ERROR) : context.make_simple_lambda_function(return_ty, arg_types), is_valid};
}

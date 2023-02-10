#include "lang/ast/function_decl_stmt_ast.h"
#include "lang/ast/block_expr_ast.h"
#include "lang/sema/types.h"
#include <memory>
#include <optional>
#include <vector>

function_decl_stmt::function_decl_stmt(code_location start, code_location end, std::vector<ast_ref> args, ast_ref return_type, ast_ref body,
                                       std::string name)
    : base_ast(start, end, FUN_DECL_STMT), args(std::move(args)), return_type(std::move(return_type)), body(std::move(body)), name(std::move(name))
{
}

void function_decl_stmt::visit_children(const std::function<void(const base_ast&)>& f) const
{
    for (const auto& i : args)
        f(*i);
    if (return_type)
        f(*return_type);
    f(*body);
}

semantic_analysis_result function_decl_stmt::do_semantic_analysis(sema_ctx& c) const
{
    std::vector<type_descriptor> arg_types;
    bool is_valid = false;
    bool should_fail = false;
    for (const auto& i : args)
    {
        auto [arg, valid, _] = i->semantic_analysis(c);
        arg_types.push_back(arg);

        if (arg == c.langtype(primitive_type::ERROR))
            should_fail = true;
        is_valid &= valid;
    }

    type_descriptor return_ty = nullptr; // this should be deduced

    if (return_type)
    {
        auto [return_type_specifier_ty, return_type_valid, _] = return_type->semantic_analysis(c);

        if (return_type_specifier_ty != c.langtype(primitive_type::ERROR))
        {
            c.get_compiler_ctx().report_error(error{
                return_type->range(),
                "type specifier must refer to a type (the expressions should have type 'metatype', but got \'" +
                    return_type_specifier_ty->get_name() + "\')",
                std::nullopt,
            });

            return {c.make_simple_lambda_function(c.langtype(primitive_type::ERROR), arg_types), false};
        }

        // TODO: evaluate
        // also, we must verify that the return type from block is converible to the specified return type
    }
    else
    {
        return_ty = dynamic_cast<block_expr&>(*body).deduce_return_type(c);
        if (return_ty == c.langtype(primitive_type::ERROR))
            return {c.make_simple_lambda_function(return_ty, arg_types), false};
    }

    auto [_1, body_valid, _2] = body->semantic_analysis(c);
    if (!body_valid)
        return {c.make_simple_lambda_function(return_ty, arg_types), false};

    return {should_fail ? c.make_simple_lambda_function(return_ty, arg_types) : c.langtype(primitive_type::ERROR), is_valid};
}

#include "lang/ast/functional_call_expr_ast.h"
#include "lang/sema/types.h"
#include <optional>

function_call_expr::function_call_expr(code_location start, code_location end, ast_ref callee, std::vector<ast_ref> args)
    : base_ast(start, end, FUNCTION_CALL_EXPR), callee(std::move(callee)), args(std::move(args))
{
}

void function_call_expr::visit_children(const std::function<void(const base_ast&)>& f) const
{
    for (const auto& i : args)
        f(*i);
}

semantic_analysis_result function_call_expr::do_semantic_analysis(sema_ctx& c) const
{
    // perform semantic analysis
    std::vector<type_descriptor> types;

    bool call_types_valid = true;
    for (const auto& i : args)
    {
        auto [ty, valid, _] = i->semantic_analysis(c);
        if (!valid)
            call_types_valid = false;
        types.push_back(ty);
    }
    auto [invokee_ty, valid, _] = callee->semantic_analysis(c);

    // there has been an error trying to invoke stuff
    if (invokee_ty == c.langtype(primitive_type::ERROR))
        return {c.langtype(primitive_type::ERROR), false};

    auto invoke_result = invokee_ty->invoke_result(c, types);
    // the call types are not valid
    if (!call_types_valid)
        return {invoke_result, false}; // if it magically still works, we can just use that type

    if (invoke_result == c.langtype(primitive_type::ERROR))
    {
        std::vector<std::pair<code_range, std::string>> notes;

        notes.push_back({callee->range(), "invokee type is " + invokee_ty->get_name()});

        for (size_t i = 0; i < args.size(); i++)
            notes.push_back({args[i]->range(), "argument " + std::to_string(i) + " has type " + types[i]->get_name()});

        c.get_compiler_ctx().report_error(error{
            range(),
            "unable to invoke function with specified argument types; either the invokee cannot be called as a function, or you messed up arguments",
            std::nullopt, notes});
        return {c.langtype(primitive_type::ERROR), false};
    }

    return {invoke_result, true};
}

#include "lang/attribute_ast.h"
#include "lang/ast/base_ast.h"
#include "lang/compiler_context.h"
#include "lang/lexer/code_location.h"
#include "lang/sema/types.h"
#include "lang/utils/utils.h"
#include <fmt/ranges.h>
#include <ranges>
#include <stdexcept>

attribute_entry_stmt::attribute_entry_stmt(code_location start, code_location end, std::string name, std::vector<ast_ref> args)
    : base_ast(start, end, ATTRIBUTE_ENTRY_AST), name(std::move(name)), args(std::move(args))
{
}

auto attribute_entry_stmt::do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result
{
    bool is_valid = true;
    std::vector<type_descriptor> arg_types;

    for (const auto& arg : args)
    {
        auto [type, is_arg_valid, is_arg_constexpr, _t] = arg->semantic_analysis(context);
        is_valid &= is_arg_valid;
        arg_types.push_back(type);

        if (!is_arg_constexpr)
        {
            context.get_compiler_ctx().report_diagnostic({{arg->range(), "attribute argument must be constexpr"}});
            is_valid = false;
        }
    }

    if (!is_valid)
    {
        return {nullptr, false, false};
    }

    if (!context.resolve_attribtue(name, arg_types))
    {
        std::vector<diagnostic::diagnostic_entry> notes;
        size_t index = 0;
        notes.reserve(arg_types.size());

        for (const auto& arg_type : arg_types)
        {
            notes.emplace_back(args[index++]->range(), "argument type " + arg_type->get_name());
        }

        context.get_compiler_ctx().report_diagnostic({{range(), "unable to resolve attribtue " + name}, {}, notes});

        return {nullptr, false, false};
    }

    return {nullptr, true, false};
}

void attribute_entry_stmt::visit_children(const std::function<void(const base_ast&)>& consumer) const
{
    for (const auto& arg : args)
    {
        consumer(*arg);
    }
}

auto attribute_entry_stmt::do_codegen(codegen_ctx& /*context*/) const -> codegen_value
{
    throw std::runtime_error("internal error: cannot do codegen for attribute");
}

auto attribute_entry_stmt::serialize() const -> std::string
{
    return fmt::format("(attribute_entry \"{}\" ({}))", name,
                       fmt::join(args | std::ranges::views::transform([](const ast_ref& entry) { return entry->serialize(); }), " "));
}

attribute_list_stmt::attribute_list_stmt(code_location start, code_location end, std::vector<ast_ref> attributes)
    : base_ast(start, end, ATTRIBUTE_AST), attributes(std::move(attributes))
{
}

void attribute_list_stmt::visit_children(const std::function<void(const base_ast&)>& consumer) const
{
    for (const auto& attribute : attributes)
    {
        consumer(*attribute);
    }
}

auto attribute_list_stmt::do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result
{
    bool flag = true;
    for (const auto& attribute : attributes)
    {
        flag &= attribute->semantic_analysis(context).is_valid;
    }

    return {nullptr, flag, false};
}

auto attribute_list_stmt::do_codegen(codegen_ctx& /*context*/) const -> codegen_value
{
    throw std::runtime_error("internal error: cannot do codegen for attribute");
}

auto attribute_list_stmt::serialize() const -> std::string
{
    return fmt::format("(attribute ({}))",
                       fmt::join(attributes | std::ranges::views::transform([](const ast_ref& entry) { return entry->serialize(); }), " "));
}

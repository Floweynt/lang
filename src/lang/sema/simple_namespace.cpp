#include "lang/sema/simple_namespace.h"
#include "lang/sema/ct_value.h"
#include "lang/sema/sema_ctx.h"
#include "lang/sema/types.h"
#include <memory>
#include <stdexcept>
#include <variant>

simple_namespace::simple_namespace(const std::string& name, std::unordered_map<std::string, std::variant<ct_value, type_descriptor>> members)
    : type(name, 0), members(std::move(members))
{
}

auto simple_namespace::get_llvm_type(codegen_ctx& /*context*/) const -> llvm::Type*
{
    throw std::runtime_error("internal error: namespace should not be codegen");
}

auto simple_namespace::invoke_result(sema_ctx& ctx, const std::vector<type_descriptor>& /*desc*/) const -> type_descriptor
{
    return ctx.langtype(primitive_type::ERROR);
}

auto simple_namespace::resolve_name(sema_ctx& ctx, const std::string& name) const -> type_descriptor
{
    struct visitor
    {
        auto operator()(const ct_value& val) { return val.get_type(); }
        auto operator()(type_descriptor desc) { return desc; }
        auto operator()(std::monostate /*unused*/) -> type_descriptor { throw std::runtime_error("internal error: bad value"); }
    };

    if (!members.contains(name))
    {
        return ctx.langtype(primitive_type::ERROR);
    }

    return std::visit(visitor(), members.at(name));
}

auto simple_namespace::constexpr_eval_resolve_name(sema_ctx& ctx, const std::string& name) const -> ct_value
{
    if (!members.contains(name))
    {
        return ct_value(ctx.langtype(primitive_type::ERROR), nullptr);
    }

    return std::get<ct_value>(members.at(name));
}

auto simple_namespace::get_or_create_subnamespace(sema_ctx& ctx, const std::string& name) -> simple_namespace*
{
    if (!members.contains(name))
    {
        const auto* ns_type = ctx.add_type(std::make_unique<simple_namespace>(name));
        members.insert({name, ct_value(ctx.langtype(primitive_type::META), ns_type)});
        return const_cast<simple_namespace*>(dynamic_cast<const simple_namespace*>(ns_type));
    }

    if (!std::holds_alternative<ct_value>(members.at(name)))
    {
        throw std::runtime_error("internal error: name already exists");
    }

    auto value = std::get<ct_value>(members.at(name));

    if (value.get_type() != ctx.langtype(primitive_type::META))
    {
        throw std::runtime_error("internal error: type is not of meta");
    }

    if (dynamic_cast<const simple_namespace*>(value.get_value<type_descriptor>()) == nullptr)
    {
        throw std::runtime_error("internal error: type is not namespace");
    }

    return const_cast<simple_namespace*>(dynamic_cast<const simple_namespace*>(value.get_value<type_descriptor>()));
}

simple_namespace_builder::simple_namespace_builder(const sema_ctx& ctx) : ctx(ctx) {}

auto simple_namespace_builder::add_type(const std::string& name, type_descriptor type) -> simple_namespace_builder&
{
    return add_comptime_value(name, ct_value(ctx.langtype(primitive_type::META), type));
}

auto simple_namespace_builder::add_comptime_value(const std::string& name, ct_value value) -> simple_namespace_builder&
{
    members.insert({name, value});
    return *this;
}

auto simple_namespace_builder::add_value(const std::string& name, type_descriptor type) -> simple_namespace_builder&
{
    members.insert({name, type});
    return *this;
}

auto simple_namespace_builder::build(const std::string& name) -> std::unique_ptr<type> { return std::make_unique<simple_namespace>(name, members); }

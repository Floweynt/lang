#include "lang/sema/simple_namespace.h"
#include "lang/sema/ct_value.h"
#include "lang/sema/sema_ctx.h"
#include "lang/sema/types.h"
#include <memory>

auto simple_namespace::invoke_result(sema_ctx& ctx, const std::vector<type_descriptor>& /*desc*/) const -> type_descriptor
{
    return ctx.langtype(primitive_type::ERROR);
}

auto simple_namespace::resolve_name(sema_ctx& ctx, const std::string& name) const -> type_descriptor
{
    return members.contains(name) ? ctx.langtype(primitive_type::META) : ctx.langtype(primitive_type::ERROR);
}

auto simple_namespace::constexpr_eval_resolve_name(sema_ctx& ctx, const std::string& name) const -> ct_value
{
    return members.contains(name) ? ct_value(ctx.langtype(primitive_type::META), members.at(name))
                                  : ct_value(ctx.langtype(primitive_type::ERROR), nullptr);
}

auto simple_namespace::get_or_create_subnamespace(sema_ctx& ctx, const std::string& name) -> simple_namespace*
{
    if (members.contains(name))
    {
        if (dynamic_cast<const simple_namespace*>(members.at(name)) == nullptr)
        {
            return (simple_namespace*)ctx.langtype(primitive_type::ERROR);
        }
        return (simple_namespace*)members.at(name);
    }

    return (simple_namespace*)(members[name] =
                                   ctx.add_type(std::make_unique<simple_namespace>(name, std::unordered_map<std::string, type_descriptor>())));
}

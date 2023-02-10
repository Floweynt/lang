#include "lang/sema/simple_namespace.h"
#include "lang/sema/ct_value.h"
#include "lang/sema/sema_ctx.h"
#include "lang/sema/types.h"
#include <memory>

type_descriptor simple_namespace::invoke_result(sema_ctx& ctx, const std::vector<type_descriptor>& desc) const
{
    return ctx.langtype(primitive_type::ERROR);
}

type_descriptor simple_namespace::resolve_name(sema_ctx& ctx, const std::string& name) const
{
    return members.contains(name) ? ctx.langtype(primitive_type::META) : ctx.langtype(primitive_type::ERROR);
}

ct_value simple_namespace::constexpr_eval_resolve_name(sema_ctx& ctx, const std::string& name) const
{
    return members.contains(name) ? ct_value(ctx.langtype(primitive_type::META), members.at(name))
                                  : ct_value(ctx.langtype(primitive_type::ERROR), nullptr);
}

simple_namespace* simple_namespace::get_or_create_subnamespace(sema_ctx& ctx, const std::string& name)
{
    if (members.contains(name))
    {
        if (!dynamic_cast<const simple_namespace*>(members.at(name)))
            return (simple_namespace*)ctx.langtype(primitive_type::ERROR);
        return (simple_namespace*)members.at(name);
    }

    return (simple_namespace*)(members[name] =
                                   ctx.add_type(std::make_unique<simple_namespace>(name, std::unordered_map<std::string, type_descriptor>())));
}

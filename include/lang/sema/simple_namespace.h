#pragma once
#include "lang/sema/types.h"
#include <unordered_map>

class sema_ctx;

class simple_namespace : public type
{
    std::unordered_map<std::string, type_descriptor> members;

public:
    inline simple_namespace(const std::string& name, const std::unordered_map<std::string, type_descriptor>& members)
        : type(name, false), members(members)
    {
    }

    virtual type_descriptor invoke_result(sema_ctx& ctx, const std::vector<type_descriptor>& desc) const override;
    virtual type_descriptor resolve_name(sema_ctx& ctx, const std::string& name) const override;
    virtual ct_value constexpr_eval_resolve_name(sema_ctx& ctx, const std::string& name) const override;

    simple_namespace* get_or_create_subnamespace(sema_ctx& ctx, const std::string& name);
};

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

    auto invoke_result(sema_ctx& ctx, const std::vector<type_descriptor>& desc) const -> type_descriptor override;
    auto resolve_name(sema_ctx& ctx, const std::string& name) const -> type_descriptor override;
    auto constexpr_eval_resolve_name(sema_ctx& ctx, const std::string& name) const -> ct_value override;

    inline auto get_llvm_type(codegen_ctx& /*context*/) const -> llvm::Type* override
    {
        throw std::runtime_error("internal error: namespace should not be codegen");
    }
    auto get_or_create_subnamespace(sema_ctx& ctx, const std::string& name) -> simple_namespace*;
};

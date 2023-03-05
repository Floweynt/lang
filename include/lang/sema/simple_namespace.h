#pragma once
#include "lang/sema/ct_value.h"
#include "lang/sema/types.h"
#include <unordered_map>
#include <utility>
#include <variant>

class sema_ctx;

class simple_namespace : public type
{
    std::unordered_map<std::string, std::variant<ct_value, type_descriptor>> members;

public:
    simple_namespace(const std::string& name, std::unordered_map<std::string, std::variant<ct_value, type_descriptor>> members = {});
    auto invoke_result(sema_ctx& ctx, const std::vector<type_descriptor>& desc) const -> type_descriptor override;
    auto resolve_name(sema_ctx& ctx, const std::string& name) const -> type_descriptor override;
    auto constexpr_eval_resolve_name(sema_ctx& ctx, const std::string& name) const -> ct_value override;

    auto get_llvm_type(codegen_ctx& /*context*/) const -> llvm::Type* override;
    auto get_or_create_subnamespace(sema_ctx& ctx, const std::string& name) -> simple_namespace*;
};

class simple_namespace_builder
{
    std::unordered_map<std::string, std::variant<ct_value, type_descriptor>> members;
    const sema_ctx& ctx;

public:
    simple_namespace_builder(const sema_ctx& ctx);

    auto add_type(const std::string& name, type_descriptor type) -> simple_namespace_builder&;
    auto add_comptime_value(const std::string& name, ct_value value) -> simple_namespace_builder&;
    auto add_value(const std::string& name, type_descriptor type) -> simple_namespace_builder&;

    auto build(const std::string& name) -> std::unique_ptr<type>;
};

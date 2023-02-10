#pragma once

#include "lang/sema/ct_value.h"
#include <string>
#include <vector>
class type;

using type_descriptor = const type*;

class sema_ctx;

class type
{
    const std::string name;
    const bool is_real_type;

public:
    constexpr type(const std::string& str, bool is_real_type) : name(str), is_real_type(is_real_type) {}
    constexpr const std::string& get_name() const { return name; }

    virtual type_descriptor invoke_result(sema_ctx& ctx, const std::vector<type_descriptor>& desc) const = 0;

    virtual type_descriptor resolve_name(sema_ctx& ctx, const std::string& name) const;
    virtual ct_value constexpr_eval_resolve_name(sema_ctx& ctx, const std::string& name) const;

    constexpr bool can_be_used_as_type(sema_ctx& ctx) const { return is_real_type; }

    virtual ~type() = default;
};

class primitive_type : public type
{
    std::vector<type_descriptor> args;
    type_descriptor return_ty;

public:
    enum kind
    {
        INTEGRAL_SIGNED_B8 = 0,
        INTEGRAL_SIGNED_B16,
        INTEGRAL_SIGNED_B32,
        INTEGRAL_SIGNED_B64,
        INTEGRAL_MAX,
        INTEGRAL_UNSIGNED_B8,
        INTEGRAL_UNSIGNED_B16,
        INTEGRAL_UNSIGNED_B32,
        INTEGRAL_UNSIGNED_B64,
        FLOATING_B32,
        FLOATING_B64,
        CHAR_B8,
        CHAR_B16,
        CHAR_B32,
        CHAR_WIDE,
        META,
        UNIT,
        BOOL,
        ERROR,
    };

    primitive_type(const std::string& name);
    virtual type_descriptor invoke_result(sema_ctx& ctx, const std::vector<type_descriptor>& desc) const override;
};

class trivial_function_type : public type
{
    std::vector<type_descriptor> args;
    type_descriptor return_ty;

public:
    trivial_function_type(const std::string& name, type_descriptor ret, const std::vector<type_descriptor>& args);
    virtual type_descriptor invoke_result(sema_ctx& ctx, const std::vector<type_descriptor>& desc) const override;
};

// since each instance of the type represents a single type, we can uniquely identify types with a pointer

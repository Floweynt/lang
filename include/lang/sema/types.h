#pragma once

#include "lang/sema/ct_value.h"
#include <cstdint>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Type.h>
#include <string>
#include <utility>
#include <vector>
class type;

using type_descriptor = const type*;

class sema_ctx;
class codegen_ctx;
class codegen_value;

class type
{
    const std::string name;
    const uint64_t flags;

public:
    inline static constexpr uint64_t IS_INSTANTIABLE_TYPE = 1 << 0;
    inline static constexpr uint64_t IS_PRIMITIVE_TYPE = 1 << 1;
    inline static constexpr uint64_t IS_INTEGRAL_TYPE = 1 << 2;
    inline static constexpr uint64_t IS_SIGNED_INTEGRAL_TYPE = 1 << 3;
    inline static constexpr uint64_t IS_FLOATING_TYPE = 1 << 4;
    inline static constexpr uint64_t IS_CHAR_TYPE = 1 << 5;
    inline static constexpr uint64_t IS_META_TYPE = 1 << 6;
    inline static constexpr uint64_t IS_UNIT_TYPE = 1 << 7;
    inline static constexpr uint64_t IS_BOOL_TYPE = 1 << 8;
    inline static constexpr uint64_t IS_ERROR_TYPE = 1 << 9;

    constexpr type(std::string str, uint64_t flags) : name(std::move(str)), flags(flags) {}
    [[nodiscard]] constexpr auto get_name() const -> const std::string& { return name; }

    virtual auto invoke_result(sema_ctx& ctx, const std::vector<type_descriptor>& desc) const -> type_descriptor = 0;
    virtual auto invoke_codegen(codegen_ctx& ctx, const codegen_value& callee, const std::vector<codegen_value>& desc) const -> codegen_value;

    virtual auto resolve_name(sema_ctx& ctx, const std::string& name) const -> type_descriptor;
    virtual auto constexpr_eval_resolve_name(sema_ctx& ctx, const std::string& name) const -> ct_value;

    [[nodiscard]] constexpr auto can_be_used_as_type() const -> bool { return (flags & IS_INSTANTIABLE_TYPE) != 0U; }
    [[nodiscard]] constexpr auto is_primitive() const -> bool { return (flags & IS_PRIMITIVE_TYPE) != 0U; }
    [[nodiscard]] constexpr auto is_integral() const -> bool { return (flags & IS_INTEGRAL_TYPE) != 0U; }
    [[nodiscard]] constexpr auto is_signed_integral() const -> bool { return (flags & IS_SIGNED_INTEGRAL_TYPE) != 0U; }
    [[nodiscard]] constexpr auto is_unsigned_integral() const -> bool { return (flags & IS_SIGNED_INTEGRAL_TYPE) == 0U; }
    [[nodiscard]] constexpr auto is_floating() const -> bool { return (flags & IS_FLOATING_TYPE) != 0U; }
    [[nodiscard]] constexpr auto is_char() const -> bool { return (flags & IS_CHAR_TYPE) != 0U; }
    [[nodiscard]] constexpr auto is_meta() const -> bool { return (flags & IS_META_TYPE) != 0U; }
    [[nodiscard]] constexpr auto is_unit() const -> bool { return (flags & IS_UNIT_TYPE) != 0U; }
    [[nodiscard]] constexpr auto is_bool() const -> bool { return (flags & IS_BOOL_TYPE) != 0U; }
    [[nodiscard]] constexpr auto is_error() const -> bool { return (flags & IS_ERROR_TYPE) != 0U; }

    virtual auto get_llvm_type(codegen_ctx& context) const -> llvm::Type* = 0;

    virtual ~type() = default;
};

class primitive_type : public type
{
    std::vector<type_descriptor> args;
    type_descriptor return_ty;
    llvm::Type* (*llvm_type_producer)(llvm::LLVMContext& ctx);

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

    primitive_type(const std::string& name, uint64_t flags, llvm::Type* (*llvm_type_producer)(llvm::LLVMContext& ctx));
    auto invoke_result(sema_ctx& ctx, const std::vector<type_descriptor>& desc) const -> type_descriptor override;
    auto get_llvm_type(codegen_ctx& context) const -> llvm::Type* override;
};

class trivial_function_type : public type
{
    std::vector<type_descriptor> args;
    type_descriptor return_ty;

public:
    trivial_function_type(const std::string& name, type_descriptor ret, const std::vector<type_descriptor>& args);
    auto invoke_result(sema_ctx& ctx, const std::vector<type_descriptor>& desc) const -> type_descriptor override;
    auto invoke_codegen(codegen_ctx& ctx, const codegen_value& callee, const std::vector<codegen_value>& desc) const -> codegen_value override;
    auto get_llvm_type(codegen_ctx& context) const -> llvm::Type* override;

    [[nodiscard]] constexpr auto get_return_ty() const { return return_ty; }
    [[nodiscard]] constexpr auto get_args() const -> const auto& { return args; }
};

// since each instance of the type represents a single type, we can uniquely identify types with a pointer

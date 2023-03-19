#pragma once

#include "lang/codegen/codegen_ctx.h"
#include "lang/sema/types.h"
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Value.h>
#include <stdexcept>

class codegen_value
{
    type_descriptor type;
    llvm::Value* value;
    uint64_t flags;

public:
    // if set, it is local, otherwise is a compile-time constant
    inline static constexpr auto IS_LOCAL = 1 << 0;

    [[nodiscard]] constexpr auto is_local() const { return (flags & IS_LOCAL) != 0; }

    constexpr codegen_value(type_descriptor desc, llvm::Value* value, bool is_local) : type(desc), value(value), flags((is_local ? IS_LOCAL : 0)) {}
    constexpr codegen_value() = default;
    constexpr codegen_value(const codegen_value&) = default;
    constexpr codegen_value(codegen_value&&) = default;

    constexpr auto operator=(const codegen_value&) -> codegen_value& = default;
    constexpr auto operator=(codegen_value&&) -> codegen_value& = default;

    static auto make_constant(type_descriptor desc, llvm::Value* val) -> codegen_value;
    static auto make_local(codegen_ctx& context, type_descriptor desc, const std::optional<codegen_value>& init, const std::string& name = "")
        -> codegen_value;
    constexpr static auto make_null() -> codegen_value { return {}; }

    // obtains the actual value associated with this type; if it is a local, we must first deref the pointer
    inline auto get_value(codegen_ctx& context) const -> llvm::Value*
    {
        if (is_local())
        {
            return context.builder().CreateLoad(type->get_llvm_type(context), value, "localvalue_" + value->getName());
        }
        return value;
    }

    inline auto store_value(codegen_ctx& context, const codegen_value& val) const
    {
        if (!is_local())
        {
            throw std::runtime_error("internal error: cannot write to non-local value");
        }

        context.builder().CreateStore(val.get_value(context), value);
    }

    [[nodiscard]] constexpr auto get_type() const { return type; }
};

#include "lang/codegen/codegen_ctx.h"
#include "lang/codegen/codegen_value.h"
#include "lang/sema/types.h"
#include <bit>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Instruction.h>
#include <ranges>
#include <stdexcept>

codegen_ctx::codegen_ctx(sema_ctx& ctx)
    : ir_builder(my_llvm_ctx), curr_module(std::make_unique<llvm::Module>("", my_llvm_ctx)), unit_ty(llvm::StructType::get(my_llvm_ctx)), ctx(ctx)
{
    scoped_vars.push_back({{}, true});
    register_binary_operator_codegen(*this);
}

auto codegen_ctx::get_void_val() -> codegen_value
{
    return codegen_value::make_constant(ctx.langtype(primitive_type::UNIT), llvm::ConstantStruct::get(unit_ty, std::vector<llvm::Constant*>{}));
}

void codegen_ctx::push_local_stack() { scoped_vars.push_back({{}, true}); }
void codegen_ctx::pop_local_stack() { scoped_vars.pop_back(); }

void codegen_ctx::push_namespace_stack(const std::vector<std::string>& str) { curr_namespace.insert(curr_namespace.end(), str.begin(), str.end()); }

void codegen_ctx::pop_namespace_stack(size_t n) { curr_namespace.erase(curr_namespace.end() - n, curr_namespace.end()); }

auto codegen_ctx::get_variable(const std::string& str) -> codegen_value
{
    for (auto& scoped_var : std::ranges::reverse_view(scoped_vars))
    {

        if (scoped_var.first.contains(str))
        {
            return scoped_var.first.at(str);
        }
    }

    throw std::runtime_error("internal error: unknown variable, this should be caught at semantic analysis time, this means I messed up");
}

void codegen_ctx::add_variable(const std::string& str, const codegen_value& desc) { scoped_vars.back().first[str] = desc; }

auto codegen_ctx::convert_to(type_descriptor target, const codegen_value& from) -> codegen_value
{
    if (target == from.get_type())
    {
        return from;
    }

    if (target->is_bool() && from.get_type()->is_integral())
    {
        return codegen_value::make_constant(
            target, builder().CreateICmpNE(from.get_value(*this), llvm::ConstantInt::get(from.get_value(*this)->getType(), 0)));
    }

    throw std::runtime_error("unimplemented");
}

auto codegen_ctx::make_literal_string(const std::string& name, const std::string& value) -> codegen_value
{
    throw std::runtime_error("unimplemented");
}

auto codegen_ctx::make_literal_integer(const std::string& name, intmax_t value) -> codegen_value
{
    const auto* type = get_sema_ctx().resolve_literal_integer(name);
    if (name.empty() || name == "i" || name == "u" || name == "i8" || name == "u8" || name == "i8" || name == "u8" || name == "i16" ||
        name == "u16" || name == "i32" || name == "u32" || name == "i64" || name == "u64")
    {
        return codegen_value::make_constant(type, llvm::ConstantInt::get(type->get_llvm_type(*this), std::bit_cast<uint64_t>(value)));
    }

    throw std::runtime_error("unimplemented");
}

auto codegen_ctx::make_literal_floating(const std::string& name, long double value) -> codegen_value { throw std::runtime_error("unimplemented"); }

#include "lang/codegen/codegen_ctx.h"
#include "lang/codegen/codegen_value.h"
#include "lang/sema/types.h"
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Instruction.h>
#include <ranges>
#include <stdexcept>

codegen_ctx::codegen_ctx(sema_ctx& ctx)
    : ir_builder(my_llvm_ctx), curr_module(std::make_unique<llvm::Module>("", my_llvm_ctx)), unit_ty(llvm::StructType::get(my_llvm_ctx)), ctx(ctx)
{
    scoped_vars.push_back({{}, true});
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

    // TODO: checks
    return codegen_value::make_constant(target,
                                        builder().CreateCast(llvm::Instruction::CastOps::SExt, from.get_value(*this), target->get_llvm_type(*this)));
}

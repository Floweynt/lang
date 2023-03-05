#include "lang/sema/types.h"
#include "lang/codegen/codegen_ctx.h"
#include "lang/codegen/codegen_value.h"
#include "lang/sema/sema_ctx.h"
#include <cstdint>
#include <llvm/IR/DerivedTypes.h>
#include <ranges>
#include <stdexcept>

auto type::resolve_name(sema_ctx& ctx, const std::string& /*name*/) const -> type_descriptor { return ctx.langtype(primitive_type::ERROR); }
auto type::constexpr_eval_resolve_name(sema_ctx& ctx, const std::string& /*name*/) const -> ct_value
{
    return {ctx.langtype(primitive_type::ERROR), nullptr};
}

auto type::invoke_codegen(codegen_ctx& /*ctx*/, const codegen_value& /*callee*/, const std::vector<codegen_value>& /*desc*/) const -> codegen_value
{
    throw std::runtime_error("internal error: type not invocable");
}

primitive_type::primitive_type(const std::string& name, uint64_t flags, llvm::Type* (*llvm_type_producer)(llvm::LLVMContext& ctx))
    : type(name, flags | type::IS_PRIMITIVE_TYPE), return_ty(), llvm_type_producer(llvm_type_producer)
{
}

auto primitive_type::invoke_result(sema_ctx& ctx, const std::vector<type_descriptor>& /*desc*/) const -> type_descriptor
{
    return ctx.langtype(ERROR);
}

auto primitive_type::get_llvm_type(codegen_ctx& context) const -> llvm::Type*
{
    if (llvm_type_producer == nullptr)
    {
        throw std::runtime_error("internal error: this type should not participate in codegen");
    }

    return llvm_type_producer(context.llvm_ctx());
}

trivial_function_type::trivial_function_type(const std::string& name, type_descriptor ret, const std::vector<type_descriptor>& args)
    : type(name, 0), args(args), return_ty(ret)
{
}

auto trivial_function_type::invoke_result(sema_ctx& ctx, const std::vector<type_descriptor>& desc) const -> type_descriptor
{
    return desc == args ? return_ty : ctx.langtype(primitive_type::ERROR);
}

auto trivial_function_type::invoke_codegen(codegen_ctx& ctx, const codegen_value& callee, const std::vector<codegen_value>& desc) const
    -> codegen_value
{
    std::vector<llvm::Value*> values;
    values.resize(desc.size());
    std::transform(desc.begin(), desc.end(), values.begin(), [&ctx](const codegen_value& val) { return val.get_value(ctx); });

    return codegen_value::make_constant(
        return_ty,
        ctx.builder().CreateCall((llvm::FunctionType*)get_llvm_type(ctx), ((llvm::Function*)callee.get_value(ctx)), values, "simple_invoke_result"));
}

auto trivial_function_type::get_llvm_type(codegen_ctx& context) const -> llvm::Type*
{
    std::vector<llvm::Type*> llvm_args(args.size());
    std::transform(args.begin(), args.end(), llvm_args.begin(), [&context](type_descriptor type) { return type->get_llvm_type(context); });

    return llvm::FunctionType::get(return_ty->get_llvm_type(context), llvm_args, false);
}

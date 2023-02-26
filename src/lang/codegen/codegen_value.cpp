#include "lang/codegen/codegen_value.h"

auto codegen_value::make_constant(type_descriptor desc, llvm::Value* val) -> codegen_value { return {desc, val, false}; }

auto codegen_value::make_local(codegen_ctx& context, type_descriptor desc, const std::optional<codegen_value>& init, const std::string& name)
    -> codegen_value
{
    auto* ptr = context.builder().CreateAlloca(desc->get_llvm_type(context), nullptr, name);
    if (init)
    {
        context.builder().CreateStore(init->get_value(context), ptr);
    }
    return {desc, ptr, true};
}

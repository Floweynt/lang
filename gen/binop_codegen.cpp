#include "lang/codegen/codegen_ctx.h"
#include "lang/codegen/codegen_value.h"
    static llvm::Value* add_i16_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* add_i16_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* add_i16_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* add_i16_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* add_i16_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* add_i32_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* add_i32_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* add_i32_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* add_i32_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* add_i32_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* add_i64_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* add_i64_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* add_i64_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* add_i64_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* add_i64_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* add_i8_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* add_i8_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* add_i8_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* add_i8_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* add_i8_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* add_intmax_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* add_intmax_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* add_intmax_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* add_intmax_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* add_intmax_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* add_u16_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* add_u16_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* add_u16_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* add_u16_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* add_u16_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* add_u32_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* add_u32_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* add_u32_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* add_u32_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* add_u32_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* add_u64_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* add_u64_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* add_u64_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* add_u64_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* add_u64_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* add_u8_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* add_u8_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* add_u8_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* add_u8_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* add_u8_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* add_uintmax_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* add_uintmax_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* add_uintmax_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* add_uintmax_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* add_uintmax_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAdd(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* and_i16_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* and_i16_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* and_i16_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* and_i16_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* and_i16_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* and_i32_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* and_i32_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* and_i32_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* and_i32_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* and_i32_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* and_i64_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* and_i64_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* and_i64_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* and_i64_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* and_i64_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* and_i8_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* and_i8_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* and_i8_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* and_i8_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* and_i8_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* and_intmax_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* and_intmax_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* and_intmax_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* and_intmax_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* and_intmax_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* and_u16_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* and_u16_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* and_u16_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* and_u16_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* and_u16_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* and_u32_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* and_u32_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* and_u32_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* and_u32_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* and_u32_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* and_u64_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* and_u64_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* and_u64_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* and_u64_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* and_u64_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* and_u8_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* and_u8_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* and_u8_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* and_u8_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* and_u8_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* and_uintmax_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* and_uintmax_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* and_uintmax_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* and_uintmax_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* and_uintmax_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* div_i16_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSDiv(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* div_i16_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSDiv(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* div_i16_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSDiv(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* div_i16_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* div_i16_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSDiv(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* div_i32_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* div_i32_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSDiv(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* div_i32_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSDiv(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* div_i32_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* div_i32_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSDiv(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* div_i64_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* div_i64_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* div_i64_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSDiv(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* div_i64_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* div_i64_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSDiv(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* div_i8_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSDiv(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* div_i8_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSDiv(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* div_i8_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSDiv(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* div_i8_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSDiv(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* div_i8_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSDiv(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* div_intmax_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* div_intmax_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* div_intmax_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSDiv(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* div_intmax_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* div_intmax_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSDiv(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* div_u16_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateUDiv(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* div_u16_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateUDiv(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* div_u16_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateUDiv(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* div_u16_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateUDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* div_u16_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateUDiv(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* div_u32_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateUDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* div_u32_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateUDiv(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* div_u32_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateUDiv(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* div_u32_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateUDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* div_u32_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateUDiv(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* div_u64_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateUDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* div_u64_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateUDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* div_u64_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateUDiv(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* div_u64_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateUDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* div_u64_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateUDiv(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* div_u8_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateUDiv(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* div_u8_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateUDiv(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* div_u8_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateUDiv(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* div_u8_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateUDiv(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* div_u8_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateUDiv(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* div_uintmax_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateUDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* div_uintmax_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateUDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* div_uintmax_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateUDiv(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* div_uintmax_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateUDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* div_uintmax_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateUDiv(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* mod_i16_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSRem(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* mod_i16_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSRem(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mod_i16_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSRem(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mod_i16_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSRem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mod_i16_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSRem(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mod_i32_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSRem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mod_i32_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSRem(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* mod_i32_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSRem(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mod_i32_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSRem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mod_i32_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSRem(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mod_i64_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSRem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mod_i64_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSRem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mod_i64_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSRem(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* mod_i64_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSRem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mod_i64_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSRem(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* mod_i8_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSRem(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mod_i8_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSRem(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mod_i8_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSRem(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mod_i8_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSRem(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* mod_i8_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSRem(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mod_intmax_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSRem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mod_intmax_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSRem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mod_intmax_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSRem(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* mod_intmax_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSRem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mod_intmax_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSRem(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* mod_u16_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateURem(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* mod_u16_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateURem(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mod_u16_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateURem(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mod_u16_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateURem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mod_u16_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateURem(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mod_u32_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateURem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mod_u32_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateURem(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* mod_u32_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateURem(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mod_u32_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateURem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mod_u32_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateURem(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mod_u64_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateURem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mod_u64_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateURem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mod_u64_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateURem(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* mod_u64_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateURem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mod_u64_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateURem(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* mod_u8_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateURem(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mod_u8_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateURem(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mod_u8_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateURem(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mod_u8_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateURem(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* mod_u8_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateURem(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mod_uintmax_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateURem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mod_uintmax_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateURem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mod_uintmax_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateURem(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* mod_uintmax_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateURem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mod_uintmax_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateURem(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* mul_i16_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* mul_i16_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mul_i16_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mul_i16_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mul_i16_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mul_i32_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mul_i32_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* mul_i32_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mul_i32_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mul_i32_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mul_i64_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mul_i64_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mul_i64_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* mul_i64_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mul_i64_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* mul_i8_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mul_i8_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mul_i8_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mul_i8_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* mul_i8_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mul_intmax_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mul_intmax_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mul_intmax_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* mul_intmax_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mul_intmax_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* mul_u16_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* mul_u16_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mul_u16_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mul_u16_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mul_u16_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mul_u32_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mul_u32_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* mul_u32_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mul_u32_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mul_u32_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mul_u64_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mul_u64_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mul_u64_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* mul_u64_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mul_u64_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* mul_u8_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mul_u8_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mul_u8_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mul_u8_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* mul_u8_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* mul_uintmax_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mul_uintmax_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mul_uintmax_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* mul_uintmax_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* mul_uintmax_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateMul(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* or_i16_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* or_i16_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* or_i16_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* or_i16_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* or_i16_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* or_i32_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* or_i32_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* or_i32_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* or_i32_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* or_i32_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* or_i64_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* or_i64_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* or_i64_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* or_i64_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* or_i64_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* or_i8_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* or_i8_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* or_i8_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* or_i8_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* or_i8_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* or_intmax_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* or_intmax_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* or_intmax_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* or_intmax_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* or_intmax_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* or_u16_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* or_u16_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* or_u16_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* or_u16_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* or_u16_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* or_u32_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* or_u32_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* or_u32_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* or_u32_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* or_u32_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* or_u64_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* or_u64_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* or_u64_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* or_u64_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* or_u64_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* or_u8_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* or_u8_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* or_u8_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* or_u8_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* or_u8_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* or_uintmax_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* or_uintmax_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* or_uintmax_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* or_uintmax_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* or_uintmax_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* sub_i16_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* sub_i16_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* sub_i16_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* sub_i16_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* sub_i16_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* sub_i32_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* sub_i32_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* sub_i32_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* sub_i32_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* sub_i32_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* sub_i64_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* sub_i64_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* sub_i64_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* sub_i64_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* sub_i64_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* sub_i8_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* sub_i8_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* sub_i8_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* sub_i8_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* sub_i8_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* sub_intmax_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* sub_intmax_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* sub_intmax_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* sub_intmax_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* sub_intmax_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* sub_u16_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* sub_u16_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* sub_u16_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* sub_u16_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* sub_u16_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* sub_u32_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* sub_u32_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* sub_u32_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* sub_u32_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* sub_u32_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* sub_u64_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* sub_u64_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* sub_u64_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* sub_u64_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* sub_u64_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* sub_u8_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* sub_u8_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* sub_u8_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* sub_u8_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* sub_u8_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* sub_uintmax_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* sub_uintmax_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* sub_uintmax_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* sub_uintmax_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* sub_uintmax_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateSub(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* xor_i16_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* xor_i16_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* xor_i16_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* xor_i16_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* xor_i16_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* xor_i32_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* xor_i32_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* xor_i32_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* xor_i32_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* xor_i32_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* xor_i64_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* xor_i64_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* xor_i64_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* xor_i64_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* xor_i64_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* xor_i8_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* xor_i8_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* xor_i8_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* xor_i8_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* xor_i8_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* xor_intmax_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* xor_intmax_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* xor_intmax_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* xor_intmax_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* xor_intmax_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* xor_u16_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* xor_u16_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* xor_u16_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* xor_u16_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* xor_u16_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* xor_u32_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* xor_u32_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* xor_u32_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* xor_u32_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* xor_u32_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* xor_u64_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* xor_u64_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* xor_u64_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* xor_u64_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* xor_u64_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* xor_u8_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* xor_u8_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* xor_u8_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* xor_u8_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* xor_u8_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(ctx.builder().CreateCast(llvm::Instruction::ZExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* xor_uintmax_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* xor_uintmax_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* xor_uintmax_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* xor_uintmax_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* xor_uintmax_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateXor(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* eq_i16_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* eq_i16_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* eq_i16_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* eq_i16_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* eq_i16_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* eq_i32_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* eq_i32_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* eq_i32_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* eq_i32_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* eq_i32_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* eq_i64_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* eq_i64_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* eq_i64_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* eq_i64_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* eq_i64_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* eq_i8_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* eq_i8_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* eq_i8_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* eq_i8_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* eq_i8_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* eq_intmax_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* eq_intmax_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* eq_intmax_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* eq_intmax_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* eq_intmax_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* eq_u16_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* eq_u16_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* eq_u16_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* eq_u16_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* eq_u16_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* eq_u32_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* eq_u32_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* eq_u32_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* eq_u32_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* eq_u32_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* eq_u64_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* eq_u64_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* eq_u64_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* eq_u64_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* eq_u64_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* eq_u8_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* eq_u8_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* eq_u8_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* eq_u8_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* eq_u8_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* eq_uintmax_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* eq_uintmax_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* eq_uintmax_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* eq_uintmax_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* eq_uintmax_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpEQ(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* geq_i16_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* geq_i16_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* geq_i16_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* geq_i16_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* geq_i16_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* geq_i32_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* geq_i32_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* geq_i32_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* geq_i32_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* geq_i32_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* geq_i64_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* geq_i64_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* geq_i64_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* geq_i64_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* geq_i64_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* geq_i8_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* geq_i8_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* geq_i8_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* geq_i8_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* geq_i8_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* geq_intmax_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* geq_intmax_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* geq_intmax_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* geq_intmax_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* geq_intmax_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* geq_u16_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* geq_u16_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* geq_u16_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* geq_u16_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* geq_u16_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* geq_u32_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* geq_u32_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* geq_u32_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* geq_u32_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* geq_u32_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* geq_u64_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* geq_u64_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* geq_u64_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* geq_u64_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* geq_u64_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* geq_u8_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* geq_u8_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* geq_u8_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* geq_u8_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* geq_u8_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* geq_uintmax_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* geq_uintmax_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* geq_uintmax_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* geq_uintmax_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* geq_uintmax_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* gt_i16_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGT(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* gt_i16_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* gt_i16_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* gt_i16_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* gt_i16_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* gt_i32_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* gt_i32_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGT(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* gt_i32_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* gt_i32_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* gt_i32_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* gt_i64_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* gt_i64_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* gt_i64_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGT(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* gt_i64_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* gt_i64_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGT(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* gt_i8_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* gt_i8_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* gt_i8_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* gt_i8_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGT(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* gt_i8_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* gt_intmax_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* gt_intmax_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* gt_intmax_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGT(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* gt_intmax_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* gt_intmax_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSGT(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* gt_u16_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGT(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* gt_u16_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* gt_u16_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* gt_u16_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* gt_u16_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* gt_u32_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* gt_u32_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGT(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* gt_u32_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* gt_u32_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* gt_u32_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* gt_u64_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* gt_u64_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* gt_u64_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGT(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* gt_u64_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* gt_u64_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGT(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* gt_u8_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* gt_u8_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* gt_u8_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* gt_u8_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGT(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* gt_u8_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* gt_uintmax_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* gt_uintmax_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* gt_uintmax_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGT(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* gt_uintmax_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* gt_uintmax_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpUGT(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* land_bool_bool(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAnd(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* leq_i16_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* leq_i16_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* leq_i16_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* leq_i16_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* leq_i16_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* leq_i32_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* leq_i32_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* leq_i32_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* leq_i32_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* leq_i32_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* leq_i64_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* leq_i64_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* leq_i64_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* leq_i64_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* leq_i64_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* leq_i8_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* leq_i8_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* leq_i8_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* leq_i8_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* leq_i8_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* leq_intmax_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* leq_intmax_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* leq_intmax_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* leq_intmax_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* leq_intmax_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* leq_u16_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* leq_u16_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* leq_u16_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* leq_u16_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* leq_u16_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* leq_u32_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* leq_u32_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* leq_u32_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* leq_u32_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* leq_u32_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* leq_u64_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* leq_u64_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* leq_u64_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* leq_u64_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* leq_u64_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* leq_u8_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* leq_u8_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* leq_u8_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* leq_u8_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* leq_u8_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* leq_uintmax_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* leq_uintmax_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* leq_uintmax_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* leq_uintmax_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* leq_uintmax_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* lor_bool_bool(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateOr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* lt_i16_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLT(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* lt_i16_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* lt_i16_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* lt_i16_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* lt_i16_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* lt_i32_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* lt_i32_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLT(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* lt_i32_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* lt_i32_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* lt_i32_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* lt_i64_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* lt_i64_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* lt_i64_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLT(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* lt_i64_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* lt_i64_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLT(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* lt_i8_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* lt_i8_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* lt_i8_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* lt_i8_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLT(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* lt_i8_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* lt_intmax_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* lt_intmax_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* lt_intmax_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLT(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* lt_intmax_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* lt_intmax_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpSLT(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* lt_u16_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULT(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* lt_u16_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* lt_u16_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* lt_u16_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* lt_u16_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* lt_u32_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* lt_u32_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULT(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* lt_u32_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* lt_u32_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* lt_u32_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* lt_u64_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* lt_u64_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* lt_u64_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULT(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* lt_u64_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* lt_u64_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULT(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* lt_u8_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* lt_u8_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* lt_u8_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* lt_u8_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULT(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* lt_u8_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULT(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* lt_uintmax_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* lt_uintmax_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* lt_uintmax_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULT(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* lt_uintmax_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULT(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* lt_uintmax_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpULT(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* neq_i16_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* neq_i16_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* neq_i16_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* neq_i16_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* neq_i16_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* neq_i32_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* neq_i32_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* neq_i32_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* neq_i32_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* neq_i32_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* neq_i64_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* neq_i64_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* neq_i64_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* neq_i64_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* neq_i64_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* neq_i8_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* neq_i8_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* neq_i8_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* neq_i8_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* neq_i8_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* neq_intmax_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* neq_intmax_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* neq_intmax_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* neq_intmax_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* neq_intmax_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* neq_u16_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* neq_u16_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* neq_u16_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* neq_u16_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* neq_u16_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* neq_u32_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* neq_u32_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* neq_u32_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* neq_u32_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* neq_u32_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* neq_u64_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* neq_u64_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* neq_u64_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* neq_u64_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* neq_u64_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* neq_u8_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* neq_u8_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* neq_u8_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* neq_u8_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* neq_u8_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(ctx.builder().CreateCast(llvm::Instruction::SExt, lhs.get_value(ctx), rhs.get_value(ctx)->getType()), rhs.get_value(ctx));
}
static llvm::Value* neq_uintmax_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* neq_uintmax_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* neq_uintmax_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* neq_uintmax_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()));
}
static llvm::Value* neq_uintmax_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateICmpNE(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* assign_bool(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    lhs.store_value(ctx, codegen_value::make_constant(return_ty, rhs.get_value(ctx))); return rhs.get_value(ctx);
}
static llvm::Value* assign_i16_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    lhs.store_value(ctx, codegen_value::make_constant(return_ty, rhs.get_value(ctx))); return rhs.get_value(ctx);
}
static llvm::Value* assign_i32_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    lhs.store_value(ctx, codegen_value::make_constant(return_ty, rhs.get_value(ctx))); return rhs.get_value(ctx);
}
static llvm::Value* assign_i64_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    lhs.store_value(ctx, codegen_value::make_constant(return_ty, rhs.get_value(ctx))); return rhs.get_value(ctx);
}
static llvm::Value* assign_i8_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    lhs.store_value(ctx, codegen_value::make_constant(return_ty, rhs.get_value(ctx))); return rhs.get_value(ctx);
}
static llvm::Value* assign_intmax_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    lhs.store_value(ctx, codegen_value::make_constant(return_ty, rhs.get_value(ctx))); return rhs.get_value(ctx);
}
static llvm::Value* assign_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    lhs.store_value(ctx, codegen_value::make_constant(return_ty, rhs.get_value(ctx))); return rhs.get_value(ctx);
}
static llvm::Value* assign_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    lhs.store_value(ctx, codegen_value::make_constant(return_ty, rhs.get_value(ctx))); return rhs.get_value(ctx);
}
static llvm::Value* assign_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    lhs.store_value(ctx, codegen_value::make_constant(return_ty, rhs.get_value(ctx))); return rhs.get_value(ctx);
}
static llvm::Value* assign_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    lhs.store_value(ctx, codegen_value::make_constant(return_ty, rhs.get_value(ctx))); return rhs.get_value(ctx);
}
static llvm::Value* assign_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    lhs.store_value(ctx, codegen_value::make_constant(return_ty, rhs.get_value(ctx))); return rhs.get_value(ctx);
}
static llvm::Value* add_assign_i16_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAdd(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* add_assign_i16_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* add_assign_i32_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* add_assign_i32_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAdd(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* add_assign_i32_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* add_assign_i64_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* add_assign_i64_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* add_assign_i64_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAdd(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* add_assign_i64_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* add_assign_i64_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAdd(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* add_assign_i8_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAdd(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* add_assign_intmax_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* add_assign_intmax_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* add_assign_intmax_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAdd(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* add_assign_intmax_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* add_assign_intmax_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAdd(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* add_assign_u16_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAdd(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* add_assign_u16_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* add_assign_u32_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* add_assign_u32_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAdd(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* add_assign_u32_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* add_assign_u64_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* add_assign_u64_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* add_assign_u64_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAdd(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* add_assign_u64_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* add_assign_u64_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAdd(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* add_assign_u8_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAdd(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* add_assign_uintmax_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* add_assign_uintmax_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* add_assign_uintmax_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAdd(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* add_assign_uintmax_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAdd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* add_assign_uintmax_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAdd(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* and_assign_i16_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAnd(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* and_assign_i16_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* and_assign_i32_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* and_assign_i32_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAnd(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* and_assign_i32_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* and_assign_i64_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* and_assign_i64_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* and_assign_i64_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAnd(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* and_assign_i64_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* and_assign_i64_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAnd(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* and_assign_i8_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAnd(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* and_assign_intmax_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* and_assign_intmax_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* and_assign_intmax_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAnd(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* and_assign_intmax_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* and_assign_intmax_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAnd(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* and_assign_u16_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAnd(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* and_assign_u16_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* and_assign_u32_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* and_assign_u32_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAnd(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* and_assign_u32_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* and_assign_u64_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* and_assign_u64_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* and_assign_u64_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAnd(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* and_assign_u64_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* and_assign_u64_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAnd(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* and_assign_u8_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAnd(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* and_assign_uintmax_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* and_assign_uintmax_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* and_assign_uintmax_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAnd(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* and_assign_uintmax_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAnd(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* and_assign_uintmax_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateAnd(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* div_assign_i16_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSDiv(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* div_assign_i16_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* div_assign_i32_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* div_assign_i32_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSDiv(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* div_assign_i32_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* div_assign_i64_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* div_assign_i64_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* div_assign_i64_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSDiv(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* div_assign_i64_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* div_assign_i64_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSDiv(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* div_assign_i8_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSDiv(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* div_assign_intmax_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* div_assign_intmax_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* div_assign_intmax_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSDiv(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* div_assign_intmax_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* div_assign_intmax_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSDiv(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* div_assign_u16_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateUDiv(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* div_assign_u16_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateUDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* div_assign_u32_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateUDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* div_assign_u32_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateUDiv(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* div_assign_u32_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateUDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* div_assign_u64_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateUDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* div_assign_u64_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateUDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* div_assign_u64_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateUDiv(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* div_assign_u64_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateUDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* div_assign_u64_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateUDiv(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* div_assign_u8_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateUDiv(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* div_assign_uintmax_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateUDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* div_assign_uintmax_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateUDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* div_assign_uintmax_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateUDiv(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* div_assign_uintmax_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateUDiv(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* div_assign_uintmax_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateUDiv(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mod_assign_i16_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSRem(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mod_assign_i16_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSRem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mod_assign_i32_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSRem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mod_assign_i32_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSRem(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mod_assign_i32_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSRem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mod_assign_i64_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSRem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mod_assign_i64_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSRem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mod_assign_i64_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSRem(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mod_assign_i64_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSRem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mod_assign_i64_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSRem(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mod_assign_i8_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSRem(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mod_assign_intmax_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSRem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mod_assign_intmax_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSRem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mod_assign_intmax_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSRem(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mod_assign_intmax_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSRem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mod_assign_intmax_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSRem(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mod_assign_u16_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateURem(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mod_assign_u16_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateURem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mod_assign_u32_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateURem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mod_assign_u32_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateURem(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mod_assign_u32_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateURem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mod_assign_u64_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateURem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mod_assign_u64_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateURem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mod_assign_u64_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateURem(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mod_assign_u64_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateURem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mod_assign_u64_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateURem(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mod_assign_u8_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateURem(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mod_assign_uintmax_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateURem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mod_assign_uintmax_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateURem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mod_assign_uintmax_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateURem(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mod_assign_uintmax_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateURem(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mod_assign_uintmax_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateURem(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mul_assign_i16_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateMul(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mul_assign_i16_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mul_assign_i32_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mul_assign_i32_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateMul(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mul_assign_i32_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mul_assign_i64_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mul_assign_i64_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mul_assign_i64_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateMul(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mul_assign_i64_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mul_assign_i64_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateMul(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mul_assign_i8_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateMul(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mul_assign_intmax_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mul_assign_intmax_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mul_assign_intmax_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateMul(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mul_assign_intmax_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mul_assign_intmax_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateMul(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mul_assign_u16_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateMul(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mul_assign_u16_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mul_assign_u32_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mul_assign_u32_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateMul(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mul_assign_u32_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mul_assign_u64_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mul_assign_u64_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mul_assign_u64_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateMul(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mul_assign_u64_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mul_assign_u64_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateMul(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mul_assign_u8_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateMul(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mul_assign_uintmax_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mul_assign_uintmax_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mul_assign_uintmax_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateMul(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mul_assign_uintmax_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateMul(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* mul_assign_uintmax_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateMul(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* or_assign_i16_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateOr(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* or_assign_i16_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* or_assign_i32_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* or_assign_i32_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateOr(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* or_assign_i32_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* or_assign_i64_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* or_assign_i64_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* or_assign_i64_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateOr(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* or_assign_i64_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* or_assign_i64_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateOr(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* or_assign_i8_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateOr(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* or_assign_intmax_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* or_assign_intmax_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* or_assign_intmax_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateOr(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* or_assign_intmax_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* or_assign_intmax_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateOr(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* or_assign_u16_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateOr(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* or_assign_u16_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* or_assign_u32_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* or_assign_u32_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateOr(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* or_assign_u32_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* or_assign_u64_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* or_assign_u64_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* or_assign_u64_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateOr(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* or_assign_u64_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* or_assign_u64_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateOr(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* or_assign_u8_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateOr(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* or_assign_uintmax_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* or_assign_uintmax_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* or_assign_uintmax_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateOr(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* or_assign_uintmax_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateOr(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* or_assign_uintmax_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateOr(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* sub_assign_i16_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSub(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* sub_assign_i16_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* sub_assign_i32_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* sub_assign_i32_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSub(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* sub_assign_i32_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* sub_assign_i64_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* sub_assign_i64_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* sub_assign_i64_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSub(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* sub_assign_i64_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* sub_assign_i64_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSub(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* sub_assign_i8_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSub(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* sub_assign_intmax_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* sub_assign_intmax_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* sub_assign_intmax_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSub(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* sub_assign_intmax_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* sub_assign_intmax_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSub(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* sub_assign_u16_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSub(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* sub_assign_u16_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* sub_assign_u32_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* sub_assign_u32_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSub(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* sub_assign_u32_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* sub_assign_u64_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* sub_assign_u64_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* sub_assign_u64_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSub(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* sub_assign_u64_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* sub_assign_u64_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSub(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* sub_assign_u8_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSub(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* sub_assign_uintmax_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* sub_assign_uintmax_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* sub_assign_uintmax_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSub(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* sub_assign_uintmax_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSub(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* sub_assign_uintmax_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateSub(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* xor_assign_i16_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateXor(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* xor_assign_i16_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* xor_assign_i32_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* xor_assign_i32_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateXor(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* xor_assign_i32_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* xor_assign_i64_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* xor_assign_i64_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* xor_assign_i64_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateXor(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* xor_assign_i64_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* xor_assign_i64_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateXor(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* xor_assign_i8_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateXor(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* xor_assign_intmax_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* xor_assign_intmax_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* xor_assign_intmax_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateXor(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* xor_assign_intmax_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::SExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* xor_assign_intmax_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateXor(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* xor_assign_u16_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateXor(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* xor_assign_u16_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* xor_assign_u32_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* xor_assign_u32_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateXor(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* xor_assign_u32_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* xor_assign_u64_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* xor_assign_u64_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* xor_assign_u64_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateXor(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* xor_assign_u64_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* xor_assign_u64_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateXor(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* xor_assign_u8_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateXor(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* xor_assign_uintmax_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* xor_assign_uintmax_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* xor_assign_uintmax_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateXor(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* xor_assign_uintmax_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateXor(lhs.get_value(ctx), ctx.builder().CreateCast(llvm::Instruction::ZExt, rhs.get_value(ctx), lhs.get_value(ctx)->getType()))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* xor_assign_uintmax_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    auto value = codegen_value::make_constant(return_ty, ctx.builder().CreateXor(lhs.get_value(ctx), rhs.get_value(ctx))); lhs.store_value(ctx, value); return value.get_value(ctx);
}
static llvm::Value* shl_u16_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateShl(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shl_u16_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateShl(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shl_u16_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateShl(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shl_u16_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateShl(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shl_u16_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateShl(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shl_u32_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateShl(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shl_u32_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateShl(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shl_u32_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateShl(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shl_u32_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateShl(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shl_u32_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateShl(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shl_u64_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateShl(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shl_u64_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateShl(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shl_u64_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateShl(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shl_u64_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateShl(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shl_u64_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateShl(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shl_u8_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateShl(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shl_u8_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateShl(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shl_u8_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateShl(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shl_u8_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateShl(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shl_u8_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateShl(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shl_uintmax_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateShl(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shl_uintmax_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateShl(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shl_uintmax_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateShl(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shl_uintmax_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateShl(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shl_uintmax_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateShl(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u16_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u16_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u16_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u16_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u16_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u16_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateLShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u16_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateLShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u16_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateLShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u16_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateLShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u16_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateLShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u32_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u32_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u32_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u32_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u32_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u32_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateLShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u32_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateLShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u32_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateLShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u32_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateLShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u32_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateLShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u64_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u64_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u64_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u64_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u64_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u64_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateLShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u64_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateLShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u64_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateLShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u64_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateLShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u64_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateLShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u8_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u8_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u8_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u8_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u8_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u8_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateLShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u8_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateLShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u8_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateLShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u8_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateLShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_u8_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateLShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_uintmax_i16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_uintmax_i32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_uintmax_i64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_uintmax_i8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_uintmax_intmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateAShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_uintmax_u16(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateLShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_uintmax_u32(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateLShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_uintmax_u64(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateLShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_uintmax_u8(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateLShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
static llvm::Value* shr_uintmax_uintmax(codegen_ctx& ctx, codegen_value lhs, codegen_value rhs, type_descriptor return_ty)
{
    return ctx.builder().CreateLShr(lhs.get_value(ctx), rhs.get_value(ctx));
}
#include "lang/sema/sema_ctx.h"
void register_binary_operator_codegen(codegen_ctx& ctx)
{
ctx.register_binary_op_handler({OP_ADD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, add_assign_i16_i16);
ctx.register_binary_op_handler({OP_ADD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, add_assign_i16_i8);
ctx.register_binary_op_handler({OP_ADD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, add_assign_i32_i16);
ctx.register_binary_op_handler({OP_ADD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, add_assign_i32_i32);
ctx.register_binary_op_handler({OP_ADD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, add_assign_i32_i8);
ctx.register_binary_op_handler({OP_ADD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, add_assign_i64_i16);
ctx.register_binary_op_handler({OP_ADD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, add_assign_i64_i32);
ctx.register_binary_op_handler({OP_ADD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, add_assign_i64_i64);
ctx.register_binary_op_handler({OP_ADD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, add_assign_i64_i8);
ctx.register_binary_op_handler({OP_ADD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, add_assign_i64_intmax);
ctx.register_binary_op_handler({OP_ADD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, add_assign_i8_i8);
ctx.register_binary_op_handler({OP_ADD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, add_assign_intmax_i16);
ctx.register_binary_op_handler({OP_ADD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, add_assign_intmax_i32);
ctx.register_binary_op_handler({OP_ADD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, add_assign_intmax_i64);
ctx.register_binary_op_handler({OP_ADD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, add_assign_intmax_i8);
ctx.register_binary_op_handler({OP_ADD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, add_assign_intmax_intmax);
ctx.register_binary_op_handler({OP_ADD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, add_assign_u16_u16);
ctx.register_binary_op_handler({OP_ADD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, add_assign_u16_u8);
ctx.register_binary_op_handler({OP_ADD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, add_assign_u32_u16);
ctx.register_binary_op_handler({OP_ADD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, add_assign_u32_u32);
ctx.register_binary_op_handler({OP_ADD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, add_assign_u32_u8);
ctx.register_binary_op_handler({OP_ADD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, add_assign_u64_u16);
ctx.register_binary_op_handler({OP_ADD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, add_assign_u64_u32);
ctx.register_binary_op_handler({OP_ADD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, add_assign_u64_u64);
ctx.register_binary_op_handler({OP_ADD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, add_assign_u64_u8);
ctx.register_binary_op_handler({OP_ADD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, add_assign_u64_uintmax);
ctx.register_binary_op_handler({OP_ADD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, add_assign_u8_u8);
ctx.register_binary_op_handler({OP_ADD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, add_assign_uintmax_u16);
ctx.register_binary_op_handler({OP_ADD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, add_assign_uintmax_u32);
ctx.register_binary_op_handler({OP_ADD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, add_assign_uintmax_u64);
ctx.register_binary_op_handler({OP_ADD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, add_assign_uintmax_u8);
ctx.register_binary_op_handler({OP_ADD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, add_assign_uintmax_uintmax);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, add_i16_i16);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, add_i16_i32);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, add_i16_i64);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, add_i16_i8);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, add_i16_intmax);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, add_i32_i16);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, add_i32_i32);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, add_i32_i64);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, add_i32_i8);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, add_i32_intmax);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, add_i64_i16);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, add_i64_i32);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, add_i64_i64);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, add_i64_i8);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, add_i64_intmax);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, add_i8_i16);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, add_i8_i32);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, add_i8_i64);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, add_i8_i8);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, add_i8_intmax);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, add_intmax_i16);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, add_intmax_i32);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, add_intmax_i64);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, add_intmax_i8);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, add_intmax_intmax);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, add_u16_u16);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, add_u16_u32);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, add_u16_u64);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, add_u16_u8);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, add_u16_uintmax);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, add_u32_u16);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, add_u32_u32);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, add_u32_u64);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, add_u32_u8);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, add_u32_uintmax);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, add_u64_u16);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, add_u64_u32);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, add_u64_u64);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, add_u64_u8);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, add_u64_uintmax);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, add_u8_u16);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, add_u8_u32);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, add_u8_u64);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, add_u8_u8);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, add_u8_uintmax);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, add_uintmax_u16);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, add_uintmax_u32);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, add_uintmax_u64);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, add_uintmax_u8);
ctx.register_binary_op_handler({OP_ADD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, add_uintmax_uintmax);
ctx.register_binary_op_handler({OP_AND_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, and_assign_i16_i16);
ctx.register_binary_op_handler({OP_AND_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, and_assign_i16_i8);
ctx.register_binary_op_handler({OP_AND_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, and_assign_i32_i16);
ctx.register_binary_op_handler({OP_AND_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, and_assign_i32_i32);
ctx.register_binary_op_handler({OP_AND_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, and_assign_i32_i8);
ctx.register_binary_op_handler({OP_AND_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, and_assign_i64_i16);
ctx.register_binary_op_handler({OP_AND_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, and_assign_i64_i32);
ctx.register_binary_op_handler({OP_AND_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, and_assign_i64_i64);
ctx.register_binary_op_handler({OP_AND_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, and_assign_i64_i8);
ctx.register_binary_op_handler({OP_AND_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, and_assign_i64_intmax);
ctx.register_binary_op_handler({OP_AND_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, and_assign_i8_i8);
ctx.register_binary_op_handler({OP_AND_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, and_assign_intmax_i16);
ctx.register_binary_op_handler({OP_AND_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, and_assign_intmax_i32);
ctx.register_binary_op_handler({OP_AND_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, and_assign_intmax_i64);
ctx.register_binary_op_handler({OP_AND_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, and_assign_intmax_i8);
ctx.register_binary_op_handler({OP_AND_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, and_assign_intmax_intmax);
ctx.register_binary_op_handler({OP_AND_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, and_assign_u16_u16);
ctx.register_binary_op_handler({OP_AND_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, and_assign_u16_u8);
ctx.register_binary_op_handler({OP_AND_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, and_assign_u32_u16);
ctx.register_binary_op_handler({OP_AND_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, and_assign_u32_u32);
ctx.register_binary_op_handler({OP_AND_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, and_assign_u32_u8);
ctx.register_binary_op_handler({OP_AND_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, and_assign_u64_u16);
ctx.register_binary_op_handler({OP_AND_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, and_assign_u64_u32);
ctx.register_binary_op_handler({OP_AND_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, and_assign_u64_u64);
ctx.register_binary_op_handler({OP_AND_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, and_assign_u64_u8);
ctx.register_binary_op_handler({OP_AND_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, and_assign_u64_uintmax);
ctx.register_binary_op_handler({OP_AND_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, and_assign_u8_u8);
ctx.register_binary_op_handler({OP_AND_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, and_assign_uintmax_u16);
ctx.register_binary_op_handler({OP_AND_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, and_assign_uintmax_u32);
ctx.register_binary_op_handler({OP_AND_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, and_assign_uintmax_u64);
ctx.register_binary_op_handler({OP_AND_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, and_assign_uintmax_u8);
ctx.register_binary_op_handler({OP_AND_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, and_assign_uintmax_uintmax);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, and_i16_i16);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, and_i16_i32);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, and_i16_i64);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, and_i16_i8);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, and_i16_intmax);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, and_i32_i16);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, and_i32_i32);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, and_i32_i64);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, and_i32_i8);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, and_i32_intmax);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, and_i64_i16);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, and_i64_i32);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, and_i64_i64);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, and_i64_i8);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, and_i64_intmax);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, and_i8_i16);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, and_i8_i32);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, and_i8_i64);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, and_i8_i8);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, and_i8_intmax);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, and_intmax_i16);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, and_intmax_i32);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, and_intmax_i64);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, and_intmax_i8);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, and_intmax_intmax);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, and_u16_u16);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, and_u16_u32);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, and_u16_u64);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, and_u16_u8);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, and_u16_uintmax);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, and_u32_u16);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, and_u32_u32);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, and_u32_u64);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, and_u32_u8);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, and_u32_uintmax);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, and_u64_u16);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, and_u64_u32);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, and_u64_u64);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, and_u64_u8);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, and_u64_uintmax);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, and_u8_u16);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, and_u8_u32);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, and_u8_u64);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, and_u8_u8);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, and_u8_uintmax);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, and_uintmax_u16);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, and_uintmax_u32);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, and_uintmax_u64);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, and_uintmax_u8);
ctx.register_binary_op_handler({OP_BITWISE_AND, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, and_uintmax_uintmax);
ctx.register_binary_op_handler({OP_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::BOOL), ctx.get_sema_ctx().langtype(primitive_type::BOOL)}, assign_bool);
ctx.register_binary_op_handler({OP_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, assign_i16_i16);
ctx.register_binary_op_handler({OP_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, assign_i32_i32);
ctx.register_binary_op_handler({OP_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, assign_i64_i64);
ctx.register_binary_op_handler({OP_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, assign_i8_i8);
ctx.register_binary_op_handler({OP_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, assign_intmax_intmax);
ctx.register_binary_op_handler({OP_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, assign_u16);
ctx.register_binary_op_handler({OP_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, assign_u32);
ctx.register_binary_op_handler({OP_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, assign_u64);
ctx.register_binary_op_handler({OP_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, assign_u8);
ctx.register_binary_op_handler({OP_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, assign_uintmax);
ctx.register_binary_op_handler({OP_DIV_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, div_assign_i16_i16);
ctx.register_binary_op_handler({OP_DIV_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, div_assign_i16_i8);
ctx.register_binary_op_handler({OP_DIV_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, div_assign_i32_i16);
ctx.register_binary_op_handler({OP_DIV_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, div_assign_i32_i32);
ctx.register_binary_op_handler({OP_DIV_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, div_assign_i32_i8);
ctx.register_binary_op_handler({OP_DIV_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, div_assign_i64_i16);
ctx.register_binary_op_handler({OP_DIV_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, div_assign_i64_i32);
ctx.register_binary_op_handler({OP_DIV_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, div_assign_i64_i64);
ctx.register_binary_op_handler({OP_DIV_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, div_assign_i64_i8);
ctx.register_binary_op_handler({OP_DIV_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, div_assign_i64_intmax);
ctx.register_binary_op_handler({OP_DIV_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, div_assign_i8_i8);
ctx.register_binary_op_handler({OP_DIV_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, div_assign_intmax_i16);
ctx.register_binary_op_handler({OP_DIV_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, div_assign_intmax_i32);
ctx.register_binary_op_handler({OP_DIV_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, div_assign_intmax_i64);
ctx.register_binary_op_handler({OP_DIV_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, div_assign_intmax_i8);
ctx.register_binary_op_handler({OP_DIV_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, div_assign_intmax_intmax);
ctx.register_binary_op_handler({OP_DIV_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, div_assign_u16_u16);
ctx.register_binary_op_handler({OP_DIV_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, div_assign_u16_u8);
ctx.register_binary_op_handler({OP_DIV_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, div_assign_u32_u16);
ctx.register_binary_op_handler({OP_DIV_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, div_assign_u32_u32);
ctx.register_binary_op_handler({OP_DIV_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, div_assign_u32_u8);
ctx.register_binary_op_handler({OP_DIV_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, div_assign_u64_u16);
ctx.register_binary_op_handler({OP_DIV_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, div_assign_u64_u32);
ctx.register_binary_op_handler({OP_DIV_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, div_assign_u64_u64);
ctx.register_binary_op_handler({OP_DIV_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, div_assign_u64_u8);
ctx.register_binary_op_handler({OP_DIV_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, div_assign_u64_uintmax);
ctx.register_binary_op_handler({OP_DIV_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, div_assign_u8_u8);
ctx.register_binary_op_handler({OP_DIV_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, div_assign_uintmax_u16);
ctx.register_binary_op_handler({OP_DIV_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, div_assign_uintmax_u32);
ctx.register_binary_op_handler({OP_DIV_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, div_assign_uintmax_u64);
ctx.register_binary_op_handler({OP_DIV_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, div_assign_uintmax_u8);
ctx.register_binary_op_handler({OP_DIV_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, div_assign_uintmax_uintmax);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, div_i16_i16);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, div_i16_i32);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, div_i16_i64);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, div_i16_i8);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, div_i16_intmax);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, div_i32_i16);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, div_i32_i32);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, div_i32_i64);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, div_i32_i8);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, div_i32_intmax);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, div_i64_i16);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, div_i64_i32);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, div_i64_i64);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, div_i64_i8);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, div_i64_intmax);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, div_i8_i16);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, div_i8_i32);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, div_i8_i64);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, div_i8_i8);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, div_i8_intmax);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, div_intmax_i16);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, div_intmax_i32);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, div_intmax_i64);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, div_intmax_i8);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, div_intmax_intmax);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, div_u16_u16);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, div_u16_u32);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, div_u16_u64);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, div_u16_u8);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, div_u16_uintmax);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, div_u32_u16);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, div_u32_u32);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, div_u32_u64);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, div_u32_u8);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, div_u32_uintmax);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, div_u64_u16);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, div_u64_u32);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, div_u64_u64);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, div_u64_u8);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, div_u64_uintmax);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, div_u8_u16);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, div_u8_u32);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, div_u8_u64);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, div_u8_u8);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, div_u8_uintmax);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, div_uintmax_u16);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, div_uintmax_u32);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, div_uintmax_u64);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, div_uintmax_u8);
ctx.register_binary_op_handler({OP_DIV, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, div_uintmax_uintmax);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, eq_i16_i16);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, eq_i16_i32);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, eq_i16_i64);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, eq_i16_i8);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, eq_i16_intmax);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, eq_i32_i16);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, eq_i32_i32);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, eq_i32_i64);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, eq_i32_i8);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, eq_i32_intmax);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, eq_i64_i16);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, eq_i64_i32);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, eq_i64_i64);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, eq_i64_i8);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, eq_i64_intmax);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, eq_i8_i16);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, eq_i8_i32);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, eq_i8_i64);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, eq_i8_i8);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, eq_i8_intmax);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, eq_intmax_i16);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, eq_intmax_i32);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, eq_intmax_i64);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, eq_intmax_i8);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, eq_intmax_intmax);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, eq_u16_u16);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, eq_u16_u32);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, eq_u16_u64);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, eq_u16_u8);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, eq_u16_uintmax);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, eq_u32_u16);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, eq_u32_u32);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, eq_u32_u64);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, eq_u32_u8);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, eq_u32_uintmax);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, eq_u64_u16);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, eq_u64_u32);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, eq_u64_u64);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, eq_u64_u8);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, eq_u64_uintmax);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, eq_u8_u16);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, eq_u8_u32);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, eq_u8_u64);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, eq_u8_u8);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, eq_u8_uintmax);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, eq_uintmax_u16);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, eq_uintmax_u32);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, eq_uintmax_u64);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, eq_uintmax_u8);
ctx.register_binary_op_handler({OP_EQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, eq_uintmax_uintmax);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, geq_i16_i16);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, geq_i16_i32);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, geq_i16_i64);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, geq_i16_i8);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, geq_i16_intmax);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, geq_i32_i16);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, geq_i32_i32);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, geq_i32_i64);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, geq_i32_i8);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, geq_i32_intmax);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, geq_i64_i16);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, geq_i64_i32);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, geq_i64_i64);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, geq_i64_i8);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, geq_i64_intmax);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, geq_i8_i16);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, geq_i8_i32);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, geq_i8_i64);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, geq_i8_i8);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, geq_i8_intmax);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, geq_intmax_i16);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, geq_intmax_i32);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, geq_intmax_i64);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, geq_intmax_i8);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, geq_intmax_intmax);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, geq_u16_u16);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, geq_u16_u32);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, geq_u16_u64);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, geq_u16_u8);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, geq_u16_uintmax);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, geq_u32_u16);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, geq_u32_u32);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, geq_u32_u64);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, geq_u32_u8);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, geq_u32_uintmax);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, geq_u64_u16);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, geq_u64_u32);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, geq_u64_u64);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, geq_u64_u8);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, geq_u64_uintmax);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, geq_u8_u16);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, geq_u8_u32);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, geq_u8_u64);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, geq_u8_u8);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, geq_u8_uintmax);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, geq_uintmax_u16);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, geq_uintmax_u32);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, geq_uintmax_u64);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, geq_uintmax_u8);
ctx.register_binary_op_handler({OP_GEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, geq_uintmax_uintmax);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, gt_i16_i16);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, gt_i16_i32);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, gt_i16_i64);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, gt_i16_i8);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, gt_i16_intmax);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, gt_i32_i16);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, gt_i32_i32);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, gt_i32_i64);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, gt_i32_i8);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, gt_i32_intmax);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, gt_i64_i16);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, gt_i64_i32);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, gt_i64_i64);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, gt_i64_i8);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, gt_i64_intmax);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, gt_i8_i16);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, gt_i8_i32);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, gt_i8_i64);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, gt_i8_i8);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, gt_i8_intmax);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, gt_intmax_i16);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, gt_intmax_i32);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, gt_intmax_i64);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, gt_intmax_i8);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, gt_intmax_intmax);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, gt_u16_u16);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, gt_u16_u32);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, gt_u16_u64);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, gt_u16_u8);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, gt_u16_uintmax);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, gt_u32_u16);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, gt_u32_u32);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, gt_u32_u64);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, gt_u32_u8);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, gt_u32_uintmax);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, gt_u64_u16);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, gt_u64_u32);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, gt_u64_u64);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, gt_u64_u8);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, gt_u64_uintmax);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, gt_u8_u16);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, gt_u8_u32);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, gt_u8_u64);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, gt_u8_u8);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, gt_u8_uintmax);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, gt_uintmax_u16);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, gt_uintmax_u32);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, gt_uintmax_u64);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, gt_uintmax_u8);
ctx.register_binary_op_handler({OP_GREATER, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, gt_uintmax_uintmax);
ctx.register_binary_op_handler({OP_LOGICAL_AND, ctx.get_sema_ctx().langtype(primitive_type::BOOL), ctx.get_sema_ctx().langtype(primitive_type::BOOL)}, land_bool_bool);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, leq_i16_i16);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, leq_i16_i32);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, leq_i16_i64);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, leq_i16_i8);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, leq_i16_intmax);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, leq_i32_i16);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, leq_i32_i32);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, leq_i32_i64);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, leq_i32_i8);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, leq_i32_intmax);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, leq_i64_i16);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, leq_i64_i32);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, leq_i64_i64);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, leq_i64_i8);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, leq_i64_intmax);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, leq_i8_i16);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, leq_i8_i32);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, leq_i8_i64);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, leq_i8_i8);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, leq_i8_intmax);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, leq_intmax_i16);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, leq_intmax_i32);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, leq_intmax_i64);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, leq_intmax_i8);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, leq_intmax_intmax);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, leq_u16_u16);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, leq_u16_u32);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, leq_u16_u64);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, leq_u16_u8);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, leq_u16_uintmax);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, leq_u32_u16);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, leq_u32_u32);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, leq_u32_u64);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, leq_u32_u8);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, leq_u32_uintmax);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, leq_u64_u16);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, leq_u64_u32);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, leq_u64_u64);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, leq_u64_u8);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, leq_u64_uintmax);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, leq_u8_u16);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, leq_u8_u32);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, leq_u8_u64);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, leq_u8_u8);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, leq_u8_uintmax);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, leq_uintmax_u16);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, leq_uintmax_u32);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, leq_uintmax_u64);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, leq_uintmax_u8);
ctx.register_binary_op_handler({OP_LEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, leq_uintmax_uintmax);
ctx.register_binary_op_handler({OP_LOGICAL_OR, ctx.get_sema_ctx().langtype(primitive_type::BOOL), ctx.get_sema_ctx().langtype(primitive_type::BOOL)}, lor_bool_bool);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, lt_i16_i16);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, lt_i16_i32);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, lt_i16_i64);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, lt_i16_i8);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, lt_i16_intmax);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, lt_i32_i16);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, lt_i32_i32);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, lt_i32_i64);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, lt_i32_i8);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, lt_i32_intmax);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, lt_i64_i16);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, lt_i64_i32);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, lt_i64_i64);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, lt_i64_i8);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, lt_i64_intmax);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, lt_i8_i16);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, lt_i8_i32);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, lt_i8_i64);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, lt_i8_i8);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, lt_i8_intmax);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, lt_intmax_i16);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, lt_intmax_i32);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, lt_intmax_i64);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, lt_intmax_i8);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, lt_intmax_intmax);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, lt_u16_u16);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, lt_u16_u32);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, lt_u16_u64);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, lt_u16_u8);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, lt_u16_uintmax);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, lt_u32_u16);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, lt_u32_u32);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, lt_u32_u64);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, lt_u32_u8);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, lt_u32_uintmax);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, lt_u64_u16);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, lt_u64_u32);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, lt_u64_u64);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, lt_u64_u8);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, lt_u64_uintmax);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, lt_u8_u16);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, lt_u8_u32);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, lt_u8_u64);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, lt_u8_u8);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, lt_u8_uintmax);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, lt_uintmax_u16);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, lt_uintmax_u32);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, lt_uintmax_u64);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, lt_uintmax_u8);
ctx.register_binary_op_handler({OP_LESS, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, lt_uintmax_uintmax);
ctx.register_binary_op_handler({OP_MOD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, mod_assign_i16_i16);
ctx.register_binary_op_handler({OP_MOD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, mod_assign_i16_i8);
ctx.register_binary_op_handler({OP_MOD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, mod_assign_i32_i16);
ctx.register_binary_op_handler({OP_MOD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, mod_assign_i32_i32);
ctx.register_binary_op_handler({OP_MOD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, mod_assign_i32_i8);
ctx.register_binary_op_handler({OP_MOD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, mod_assign_i64_i16);
ctx.register_binary_op_handler({OP_MOD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, mod_assign_i64_i32);
ctx.register_binary_op_handler({OP_MOD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, mod_assign_i64_i64);
ctx.register_binary_op_handler({OP_MOD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, mod_assign_i64_i8);
ctx.register_binary_op_handler({OP_MOD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, mod_assign_i64_intmax);
ctx.register_binary_op_handler({OP_MOD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, mod_assign_i8_i8);
ctx.register_binary_op_handler({OP_MOD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, mod_assign_intmax_i16);
ctx.register_binary_op_handler({OP_MOD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, mod_assign_intmax_i32);
ctx.register_binary_op_handler({OP_MOD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, mod_assign_intmax_i64);
ctx.register_binary_op_handler({OP_MOD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, mod_assign_intmax_i8);
ctx.register_binary_op_handler({OP_MOD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, mod_assign_intmax_intmax);
ctx.register_binary_op_handler({OP_MOD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, mod_assign_u16_u16);
ctx.register_binary_op_handler({OP_MOD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, mod_assign_u16_u8);
ctx.register_binary_op_handler({OP_MOD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, mod_assign_u32_u16);
ctx.register_binary_op_handler({OP_MOD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, mod_assign_u32_u32);
ctx.register_binary_op_handler({OP_MOD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, mod_assign_u32_u8);
ctx.register_binary_op_handler({OP_MOD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, mod_assign_u64_u16);
ctx.register_binary_op_handler({OP_MOD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, mod_assign_u64_u32);
ctx.register_binary_op_handler({OP_MOD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, mod_assign_u64_u64);
ctx.register_binary_op_handler({OP_MOD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, mod_assign_u64_u8);
ctx.register_binary_op_handler({OP_MOD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, mod_assign_u64_uintmax);
ctx.register_binary_op_handler({OP_MOD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, mod_assign_u8_u8);
ctx.register_binary_op_handler({OP_MOD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, mod_assign_uintmax_u16);
ctx.register_binary_op_handler({OP_MOD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, mod_assign_uintmax_u32);
ctx.register_binary_op_handler({OP_MOD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, mod_assign_uintmax_u64);
ctx.register_binary_op_handler({OP_MOD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, mod_assign_uintmax_u8);
ctx.register_binary_op_handler({OP_MOD_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, mod_assign_uintmax_uintmax);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, mod_i16_i16);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, mod_i16_i32);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, mod_i16_i64);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, mod_i16_i8);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, mod_i16_intmax);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, mod_i32_i16);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, mod_i32_i32);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, mod_i32_i64);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, mod_i32_i8);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, mod_i32_intmax);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, mod_i64_i16);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, mod_i64_i32);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, mod_i64_i64);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, mod_i64_i8);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, mod_i64_intmax);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, mod_i8_i16);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, mod_i8_i32);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, mod_i8_i64);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, mod_i8_i8);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, mod_i8_intmax);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, mod_intmax_i16);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, mod_intmax_i32);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, mod_intmax_i64);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, mod_intmax_i8);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, mod_intmax_intmax);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, mod_u16_u16);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, mod_u16_u32);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, mod_u16_u64);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, mod_u16_u8);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, mod_u16_uintmax);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, mod_u32_u16);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, mod_u32_u32);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, mod_u32_u64);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, mod_u32_u8);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, mod_u32_uintmax);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, mod_u64_u16);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, mod_u64_u32);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, mod_u64_u64);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, mod_u64_u8);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, mod_u64_uintmax);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, mod_u8_u16);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, mod_u8_u32);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, mod_u8_u64);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, mod_u8_u8);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, mod_u8_uintmax);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, mod_uintmax_u16);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, mod_uintmax_u32);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, mod_uintmax_u64);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, mod_uintmax_u8);
ctx.register_binary_op_handler({OP_MOD, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, mod_uintmax_uintmax);
ctx.register_binary_op_handler({OP_MUL_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, mul_assign_i16_i16);
ctx.register_binary_op_handler({OP_MUL_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, mul_assign_i16_i8);
ctx.register_binary_op_handler({OP_MUL_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, mul_assign_i32_i16);
ctx.register_binary_op_handler({OP_MUL_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, mul_assign_i32_i32);
ctx.register_binary_op_handler({OP_MUL_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, mul_assign_i32_i8);
ctx.register_binary_op_handler({OP_MUL_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, mul_assign_i64_i16);
ctx.register_binary_op_handler({OP_MUL_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, mul_assign_i64_i32);
ctx.register_binary_op_handler({OP_MUL_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, mul_assign_i64_i64);
ctx.register_binary_op_handler({OP_MUL_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, mul_assign_i64_i8);
ctx.register_binary_op_handler({OP_MUL_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, mul_assign_i64_intmax);
ctx.register_binary_op_handler({OP_MUL_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, mul_assign_i8_i8);
ctx.register_binary_op_handler({OP_MUL_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, mul_assign_intmax_i16);
ctx.register_binary_op_handler({OP_MUL_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, mul_assign_intmax_i32);
ctx.register_binary_op_handler({OP_MUL_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, mul_assign_intmax_i64);
ctx.register_binary_op_handler({OP_MUL_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, mul_assign_intmax_i8);
ctx.register_binary_op_handler({OP_MUL_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, mul_assign_intmax_intmax);
ctx.register_binary_op_handler({OP_MUL_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, mul_assign_u16_u16);
ctx.register_binary_op_handler({OP_MUL_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, mul_assign_u16_u8);
ctx.register_binary_op_handler({OP_MUL_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, mul_assign_u32_u16);
ctx.register_binary_op_handler({OP_MUL_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, mul_assign_u32_u32);
ctx.register_binary_op_handler({OP_MUL_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, mul_assign_u32_u8);
ctx.register_binary_op_handler({OP_MUL_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, mul_assign_u64_u16);
ctx.register_binary_op_handler({OP_MUL_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, mul_assign_u64_u32);
ctx.register_binary_op_handler({OP_MUL_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, mul_assign_u64_u64);
ctx.register_binary_op_handler({OP_MUL_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, mul_assign_u64_u8);
ctx.register_binary_op_handler({OP_MUL_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, mul_assign_u64_uintmax);
ctx.register_binary_op_handler({OP_MUL_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, mul_assign_u8_u8);
ctx.register_binary_op_handler({OP_MUL_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, mul_assign_uintmax_u16);
ctx.register_binary_op_handler({OP_MUL_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, mul_assign_uintmax_u32);
ctx.register_binary_op_handler({OP_MUL_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, mul_assign_uintmax_u64);
ctx.register_binary_op_handler({OP_MUL_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, mul_assign_uintmax_u8);
ctx.register_binary_op_handler({OP_MUL_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, mul_assign_uintmax_uintmax);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, mul_i16_i16);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, mul_i16_i32);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, mul_i16_i64);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, mul_i16_i8);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, mul_i16_intmax);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, mul_i32_i16);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, mul_i32_i32);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, mul_i32_i64);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, mul_i32_i8);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, mul_i32_intmax);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, mul_i64_i16);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, mul_i64_i32);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, mul_i64_i64);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, mul_i64_i8);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, mul_i64_intmax);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, mul_i8_i16);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, mul_i8_i32);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, mul_i8_i64);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, mul_i8_i8);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, mul_i8_intmax);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, mul_intmax_i16);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, mul_intmax_i32);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, mul_intmax_i64);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, mul_intmax_i8);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, mul_intmax_intmax);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, mul_u16_u16);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, mul_u16_u32);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, mul_u16_u64);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, mul_u16_u8);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, mul_u16_uintmax);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, mul_u32_u16);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, mul_u32_u32);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, mul_u32_u64);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, mul_u32_u8);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, mul_u32_uintmax);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, mul_u64_u16);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, mul_u64_u32);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, mul_u64_u64);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, mul_u64_u8);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, mul_u64_uintmax);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, mul_u8_u16);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, mul_u8_u32);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, mul_u8_u64);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, mul_u8_u8);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, mul_u8_uintmax);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, mul_uintmax_u16);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, mul_uintmax_u32);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, mul_uintmax_u64);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, mul_uintmax_u8);
ctx.register_binary_op_handler({OP_MUL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, mul_uintmax_uintmax);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, neq_i16_i16);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, neq_i16_i32);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, neq_i16_i64);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, neq_i16_i8);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, neq_i16_intmax);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, neq_i32_i16);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, neq_i32_i32);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, neq_i32_i64);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, neq_i32_i8);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, neq_i32_intmax);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, neq_i64_i16);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, neq_i64_i32);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, neq_i64_i64);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, neq_i64_i8);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, neq_i64_intmax);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, neq_i8_i16);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, neq_i8_i32);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, neq_i8_i64);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, neq_i8_i8);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, neq_i8_intmax);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, neq_intmax_i16);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, neq_intmax_i32);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, neq_intmax_i64);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, neq_intmax_i8);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, neq_intmax_intmax);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, neq_u16_u16);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, neq_u16_u32);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, neq_u16_u64);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, neq_u16_u8);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, neq_u16_uintmax);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, neq_u32_u16);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, neq_u32_u32);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, neq_u32_u64);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, neq_u32_u8);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, neq_u32_uintmax);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, neq_u64_u16);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, neq_u64_u32);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, neq_u64_u64);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, neq_u64_u8);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, neq_u64_uintmax);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, neq_u8_u16);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, neq_u8_u32);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, neq_u8_u64);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, neq_u8_u8);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, neq_u8_uintmax);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, neq_uintmax_u16);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, neq_uintmax_u32);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, neq_uintmax_u64);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, neq_uintmax_u8);
ctx.register_binary_op_handler({OP_NEQ, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, neq_uintmax_uintmax);
ctx.register_binary_op_handler({OP_OR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, or_assign_i16_i16);
ctx.register_binary_op_handler({OP_OR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, or_assign_i16_i8);
ctx.register_binary_op_handler({OP_OR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, or_assign_i32_i16);
ctx.register_binary_op_handler({OP_OR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, or_assign_i32_i32);
ctx.register_binary_op_handler({OP_OR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, or_assign_i32_i8);
ctx.register_binary_op_handler({OP_OR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, or_assign_i64_i16);
ctx.register_binary_op_handler({OP_OR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, or_assign_i64_i32);
ctx.register_binary_op_handler({OP_OR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, or_assign_i64_i64);
ctx.register_binary_op_handler({OP_OR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, or_assign_i64_i8);
ctx.register_binary_op_handler({OP_OR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, or_assign_i64_intmax);
ctx.register_binary_op_handler({OP_OR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, or_assign_i8_i8);
ctx.register_binary_op_handler({OP_OR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, or_assign_intmax_i16);
ctx.register_binary_op_handler({OP_OR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, or_assign_intmax_i32);
ctx.register_binary_op_handler({OP_OR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, or_assign_intmax_i64);
ctx.register_binary_op_handler({OP_OR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, or_assign_intmax_i8);
ctx.register_binary_op_handler({OP_OR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, or_assign_intmax_intmax);
ctx.register_binary_op_handler({OP_OR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, or_assign_u16_u16);
ctx.register_binary_op_handler({OP_OR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, or_assign_u16_u8);
ctx.register_binary_op_handler({OP_OR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, or_assign_u32_u16);
ctx.register_binary_op_handler({OP_OR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, or_assign_u32_u32);
ctx.register_binary_op_handler({OP_OR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, or_assign_u32_u8);
ctx.register_binary_op_handler({OP_OR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, or_assign_u64_u16);
ctx.register_binary_op_handler({OP_OR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, or_assign_u64_u32);
ctx.register_binary_op_handler({OP_OR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, or_assign_u64_u64);
ctx.register_binary_op_handler({OP_OR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, or_assign_u64_u8);
ctx.register_binary_op_handler({OP_OR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, or_assign_u64_uintmax);
ctx.register_binary_op_handler({OP_OR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, or_assign_u8_u8);
ctx.register_binary_op_handler({OP_OR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, or_assign_uintmax_u16);
ctx.register_binary_op_handler({OP_OR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, or_assign_uintmax_u32);
ctx.register_binary_op_handler({OP_OR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, or_assign_uintmax_u64);
ctx.register_binary_op_handler({OP_OR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, or_assign_uintmax_u8);
ctx.register_binary_op_handler({OP_OR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, or_assign_uintmax_uintmax);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, or_i16_i16);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, or_i16_i32);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, or_i16_i64);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, or_i16_i8);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, or_i16_intmax);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, or_i32_i16);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, or_i32_i32);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, or_i32_i64);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, or_i32_i8);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, or_i32_intmax);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, or_i64_i16);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, or_i64_i32);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, or_i64_i64);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, or_i64_i8);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, or_i64_intmax);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, or_i8_i16);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, or_i8_i32);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, or_i8_i64);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, or_i8_i8);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, or_i8_intmax);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, or_intmax_i16);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, or_intmax_i32);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, or_intmax_i64);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, or_intmax_i8);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, or_intmax_intmax);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, or_u16_u16);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, or_u16_u32);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, or_u16_u64);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, or_u16_u8);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, or_u16_uintmax);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, or_u32_u16);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, or_u32_u32);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, or_u32_u64);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, or_u32_u8);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, or_u32_uintmax);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, or_u64_u16);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, or_u64_u32);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, or_u64_u64);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, or_u64_u8);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, or_u64_uintmax);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, or_u8_u16);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, or_u8_u32);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, or_u8_u64);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, or_u8_u8);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, or_u8_uintmax);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, or_uintmax_u16);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, or_uintmax_u32);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, or_uintmax_u64);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, or_uintmax_u8);
ctx.register_binary_op_handler({OP_BITWISE_OR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, or_uintmax_uintmax);
ctx.register_binary_op_handler({OP_SHL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, shl_u16_u16);
ctx.register_binary_op_handler({OP_SHL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, shl_u16_u32);
ctx.register_binary_op_handler({OP_SHL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, shl_u16_u64);
ctx.register_binary_op_handler({OP_SHL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, shl_u16_u8);
ctx.register_binary_op_handler({OP_SHL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, shl_u16_uintmax);
ctx.register_binary_op_handler({OP_SHL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, shl_u32_u16);
ctx.register_binary_op_handler({OP_SHL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, shl_u32_u32);
ctx.register_binary_op_handler({OP_SHL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, shl_u32_u64);
ctx.register_binary_op_handler({OP_SHL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, shl_u32_u8);
ctx.register_binary_op_handler({OP_SHL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, shl_u32_uintmax);
ctx.register_binary_op_handler({OP_SHL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, shl_u64_u16);
ctx.register_binary_op_handler({OP_SHL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, shl_u64_u32);
ctx.register_binary_op_handler({OP_SHL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, shl_u64_u64);
ctx.register_binary_op_handler({OP_SHL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, shl_u64_u8);
ctx.register_binary_op_handler({OP_SHL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, shl_u64_uintmax);
ctx.register_binary_op_handler({OP_SHL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, shl_u8_u16);
ctx.register_binary_op_handler({OP_SHL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, shl_u8_u32);
ctx.register_binary_op_handler({OP_SHL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, shl_u8_u64);
ctx.register_binary_op_handler({OP_SHL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, shl_u8_u8);
ctx.register_binary_op_handler({OP_SHL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, shl_u8_uintmax);
ctx.register_binary_op_handler({OP_SHL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, shl_uintmax_u16);
ctx.register_binary_op_handler({OP_SHL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, shl_uintmax_u32);
ctx.register_binary_op_handler({OP_SHL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, shl_uintmax_u64);
ctx.register_binary_op_handler({OP_SHL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, shl_uintmax_u8);
ctx.register_binary_op_handler({OP_SHL, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, shl_uintmax_uintmax);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, shr_u16_i16);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, shr_u16_i32);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, shr_u16_i64);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, shr_u16_i8);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, shr_u16_intmax);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, shr_u16_u16);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, shr_u16_u32);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, shr_u16_u64);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, shr_u16_u8);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, shr_u16_uintmax);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, shr_u32_i16);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, shr_u32_i32);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, shr_u32_i64);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, shr_u32_i8);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, shr_u32_intmax);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, shr_u32_u16);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, shr_u32_u32);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, shr_u32_u64);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, shr_u32_u8);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, shr_u32_uintmax);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, shr_u64_i16);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, shr_u64_i32);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, shr_u64_i64);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, shr_u64_i8);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, shr_u64_intmax);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, shr_u64_u16);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, shr_u64_u32);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, shr_u64_u64);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, shr_u64_u8);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, shr_u64_uintmax);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, shr_u8_i16);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, shr_u8_i32);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, shr_u8_i64);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, shr_u8_i8);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, shr_u8_intmax);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, shr_u8_u16);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, shr_u8_u32);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, shr_u8_u64);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, shr_u8_u8);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, shr_u8_uintmax);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, shr_uintmax_i16);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, shr_uintmax_i32);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, shr_uintmax_i64);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, shr_uintmax_i8);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, shr_uintmax_intmax);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, shr_uintmax_u16);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, shr_uintmax_u32);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, shr_uintmax_u64);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, shr_uintmax_u8);
ctx.register_binary_op_handler({OP_SHR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, shr_uintmax_uintmax);
ctx.register_binary_op_handler({OP_SUB_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, sub_assign_i16_i16);
ctx.register_binary_op_handler({OP_SUB_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, sub_assign_i16_i8);
ctx.register_binary_op_handler({OP_SUB_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, sub_assign_i32_i16);
ctx.register_binary_op_handler({OP_SUB_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, sub_assign_i32_i32);
ctx.register_binary_op_handler({OP_SUB_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, sub_assign_i32_i8);
ctx.register_binary_op_handler({OP_SUB_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, sub_assign_i64_i16);
ctx.register_binary_op_handler({OP_SUB_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, sub_assign_i64_i32);
ctx.register_binary_op_handler({OP_SUB_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, sub_assign_i64_i64);
ctx.register_binary_op_handler({OP_SUB_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, sub_assign_i64_i8);
ctx.register_binary_op_handler({OP_SUB_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, sub_assign_i64_intmax);
ctx.register_binary_op_handler({OP_SUB_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, sub_assign_i8_i8);
ctx.register_binary_op_handler({OP_SUB_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, sub_assign_intmax_i16);
ctx.register_binary_op_handler({OP_SUB_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, sub_assign_intmax_i32);
ctx.register_binary_op_handler({OP_SUB_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, sub_assign_intmax_i64);
ctx.register_binary_op_handler({OP_SUB_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, sub_assign_intmax_i8);
ctx.register_binary_op_handler({OP_SUB_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, sub_assign_intmax_intmax);
ctx.register_binary_op_handler({OP_SUB_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, sub_assign_u16_u16);
ctx.register_binary_op_handler({OP_SUB_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, sub_assign_u16_u8);
ctx.register_binary_op_handler({OP_SUB_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, sub_assign_u32_u16);
ctx.register_binary_op_handler({OP_SUB_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, sub_assign_u32_u32);
ctx.register_binary_op_handler({OP_SUB_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, sub_assign_u32_u8);
ctx.register_binary_op_handler({OP_SUB_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, sub_assign_u64_u16);
ctx.register_binary_op_handler({OP_SUB_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, sub_assign_u64_u32);
ctx.register_binary_op_handler({OP_SUB_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, sub_assign_u64_u64);
ctx.register_binary_op_handler({OP_SUB_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, sub_assign_u64_u8);
ctx.register_binary_op_handler({OP_SUB_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, sub_assign_u64_uintmax);
ctx.register_binary_op_handler({OP_SUB_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, sub_assign_u8_u8);
ctx.register_binary_op_handler({OP_SUB_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, sub_assign_uintmax_u16);
ctx.register_binary_op_handler({OP_SUB_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, sub_assign_uintmax_u32);
ctx.register_binary_op_handler({OP_SUB_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, sub_assign_uintmax_u64);
ctx.register_binary_op_handler({OP_SUB_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, sub_assign_uintmax_u8);
ctx.register_binary_op_handler({OP_SUB_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, sub_assign_uintmax_uintmax);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, sub_i16_i16);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, sub_i16_i32);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, sub_i16_i64);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, sub_i16_i8);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, sub_i16_intmax);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, sub_i32_i16);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, sub_i32_i32);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, sub_i32_i64);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, sub_i32_i8);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, sub_i32_intmax);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, sub_i64_i16);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, sub_i64_i32);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, sub_i64_i64);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, sub_i64_i8);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, sub_i64_intmax);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, sub_i8_i16);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, sub_i8_i32);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, sub_i8_i64);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, sub_i8_i8);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, sub_i8_intmax);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, sub_intmax_i16);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, sub_intmax_i32);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, sub_intmax_i64);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, sub_intmax_i8);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, sub_intmax_intmax);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, sub_u16_u16);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, sub_u16_u32);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, sub_u16_u64);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, sub_u16_u8);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, sub_u16_uintmax);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, sub_u32_u16);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, sub_u32_u32);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, sub_u32_u64);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, sub_u32_u8);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, sub_u32_uintmax);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, sub_u64_u16);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, sub_u64_u32);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, sub_u64_u64);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, sub_u64_u8);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, sub_u64_uintmax);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, sub_u8_u16);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, sub_u8_u32);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, sub_u8_u64);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, sub_u8_u8);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, sub_u8_uintmax);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, sub_uintmax_u16);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, sub_uintmax_u32);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, sub_uintmax_u64);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, sub_uintmax_u8);
ctx.register_binary_op_handler({OP_SUB, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, sub_uintmax_uintmax);
ctx.register_binary_op_handler({OP_XOR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, xor_assign_i16_i16);
ctx.register_binary_op_handler({OP_XOR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, xor_assign_i16_i8);
ctx.register_binary_op_handler({OP_XOR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, xor_assign_i32_i16);
ctx.register_binary_op_handler({OP_XOR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, xor_assign_i32_i32);
ctx.register_binary_op_handler({OP_XOR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, xor_assign_i32_i8);
ctx.register_binary_op_handler({OP_XOR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, xor_assign_i64_i16);
ctx.register_binary_op_handler({OP_XOR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, xor_assign_i64_i32);
ctx.register_binary_op_handler({OP_XOR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, xor_assign_i64_i64);
ctx.register_binary_op_handler({OP_XOR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, xor_assign_i64_i8);
ctx.register_binary_op_handler({OP_XOR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, xor_assign_i64_intmax);
ctx.register_binary_op_handler({OP_XOR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, xor_assign_i8_i8);
ctx.register_binary_op_handler({OP_XOR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, xor_assign_intmax_i16);
ctx.register_binary_op_handler({OP_XOR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, xor_assign_intmax_i32);
ctx.register_binary_op_handler({OP_XOR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, xor_assign_intmax_i64);
ctx.register_binary_op_handler({OP_XOR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, xor_assign_intmax_i8);
ctx.register_binary_op_handler({OP_XOR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, xor_assign_intmax_intmax);
ctx.register_binary_op_handler({OP_XOR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, xor_assign_u16_u16);
ctx.register_binary_op_handler({OP_XOR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, xor_assign_u16_u8);
ctx.register_binary_op_handler({OP_XOR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, xor_assign_u32_u16);
ctx.register_binary_op_handler({OP_XOR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, xor_assign_u32_u32);
ctx.register_binary_op_handler({OP_XOR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, xor_assign_u32_u8);
ctx.register_binary_op_handler({OP_XOR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, xor_assign_u64_u16);
ctx.register_binary_op_handler({OP_XOR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, xor_assign_u64_u32);
ctx.register_binary_op_handler({OP_XOR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, xor_assign_u64_u64);
ctx.register_binary_op_handler({OP_XOR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, xor_assign_u64_u8);
ctx.register_binary_op_handler({OP_XOR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, xor_assign_u64_uintmax);
ctx.register_binary_op_handler({OP_XOR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, xor_assign_u8_u8);
ctx.register_binary_op_handler({OP_XOR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, xor_assign_uintmax_u16);
ctx.register_binary_op_handler({OP_XOR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, xor_assign_uintmax_u32);
ctx.register_binary_op_handler({OP_XOR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, xor_assign_uintmax_u64);
ctx.register_binary_op_handler({OP_XOR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, xor_assign_uintmax_u8);
ctx.register_binary_op_handler({OP_XOR_ASSIGN, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, xor_assign_uintmax_uintmax);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, xor_i16_i16);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, xor_i16_i32);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, xor_i16_i64);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, xor_i16_i8);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, xor_i16_intmax);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, xor_i32_i16);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, xor_i32_i32);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, xor_i32_i64);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, xor_i32_i8);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, xor_i32_intmax);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, xor_i64_i16);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, xor_i64_i32);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, xor_i64_i64);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, xor_i64_i8);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, xor_i64_intmax);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, xor_i8_i16);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, xor_i8_i32);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, xor_i8_i64);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, xor_i8_i8);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, xor_i8_intmax);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B16)}, xor_intmax_i16);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)}, xor_intmax_i32);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B64)}, xor_intmax_i64);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B8)}, xor_intmax_i8);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_MAX)}, xor_intmax_intmax);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, xor_u16_u16);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, xor_u16_u32);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, xor_u16_u64);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, xor_u16_u8);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, xor_u16_uintmax);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, xor_u32_u16);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, xor_u32_u32);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, xor_u32_u64);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, xor_u32_u8);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, xor_u32_uintmax);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, xor_u64_u16);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, xor_u64_u32);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, xor_u64_u64);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, xor_u64_u8);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, xor_u64_uintmax);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, xor_u8_u16);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, xor_u8_u32);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, xor_u8_u64);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, xor_u8_u8);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, xor_u8_uintmax);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B16)}, xor_uintmax_u16);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B32)}, xor_uintmax_u32);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B64)}, xor_uintmax_u64);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UNSIGNED_B8)}, xor_uintmax_u8);
ctx.register_binary_op_handler({OP_BITWISE_XOR, ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX), ctx.get_sema_ctx().langtype(primitive_type::INTEGRAL_UMAX)}, xor_uintmax_uintmax);
}

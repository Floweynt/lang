#include "lang/ast/char_literal_expr_ast.h"
#include "lang/lexer/code_location.h"
#include "lang/sema/ct_value.h"
#include "lang/sema/sema_ctx.h"
#include "lang/sema/types.h"

char_literal_expr::char_literal_expr(code_location start, code_location end, char val) : base_ast(start, end, CHAR_LITERAL), val(val) {}
void char_literal_expr::visit_children(const std::function<void(const base_ast&)>& consumer) const {}

auto char_literal_expr::do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result
{
    return {context.langtype(primitive_type::CHAR_B8), true, true};
}

auto char_literal_expr::do_consteval(sema_ctx& context) const -> ct_value { return {context.langtype(primitive_type::CHAR_B8), val}; }

auto char_literal_expr::do_codegen(codegen_ctx& context) const -> codegen_value
{
    return codegen_value::make_constant(
        get_sema_result().ty, llvm::ConstantInt::get(context.get_sema_ctx().langtype(primitive_type::CHAR_B8)->get_llvm_type(context), val));
}

auto char_literal_expr::serialize() const -> std::string { return fmt::format("(character_literal '{}')", val); }

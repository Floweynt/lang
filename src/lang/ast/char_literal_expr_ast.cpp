#include "lang/ast/char_literal_expr_ast.h"
#include "lang/lexer/code_location.h"
#include "lang/sema/ct_value.h"
#include "lang/sema/sema_ctx.h"
#include "lang/sema/types.h"

char_literal_expr::char_literal_expr(code_location start, code_location end, char val) : base_ast(start, end, CHAR_LITERAL), val(val) {}
void char_literal_expr::visit_children(const std::function<void(const base_ast&)>& f) const {}

semantic_analysis_result char_literal_expr::do_semantic_analysis(sema_ctx& c) const { return {c.langtype(primitive_type::CHAR_B8), true, true}; }

ct_value char_literal_expr::do_consteval(sema_ctx& ctx) const { return {ctx.langtype(primitive_type::CHAR_B8), val}; }

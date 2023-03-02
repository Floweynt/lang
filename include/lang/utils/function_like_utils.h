#pragma once
#include "lang/ast/base_ast.h"
#include "lang/ast/block_expr_ast.h"
#include "lang/ast/control/return_expr_ast.h"
#include "lang/sema/sema_ctx.h"
#include "lang/sema/types.h"
#include <string>

auto do_sema_func(sema_ctx& context, const std::vector<ast_ref>& args, const ast_ref& body, const ast_ref& return_type, const std::string& name)
    -> semantic_analysis_result;
auto do_codegen_func(codegen_ctx& context, llvm::GlobalValue::LinkageTypes linkage, const std::string& name, type_descriptor this_ty,
                     const std::vector<ast_ref>& args, const ast_ref& body, bool is_lambda) -> codegen_value;


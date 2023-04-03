#pragma once

#include "lang/ast/base_ast.h"
#include "lang/compiler_context.h"
#include "lang/lexer/lexer.h"
#include <memory>

auto parse(lexer& lexer, compiler_context& ctx) -> ast_ref;

auto parse_binary_op_expr(lexer& lexer, compiler_context& ctx, int expr_prec, ast_ref lhs) -> ast_ref;
auto parse_attribute_list(lexer& lexer, compiler_context& ctx) -> ast_ref;
auto parse_post_identifier(lexer& lexer, compiler_context& ctx, ast_ref ref) -> ast_ref;
auto parse_block_expr(lexer& lexer, compiler_context& ctx) -> ast_ref;
auto parse_char_literal_expr(lexer& lexer, compiler_context& ctx) -> ast_ref;
auto parse_expr(lexer& lexer, compiler_context& ctx) -> ast_ref;
auto parse_identifier_expr(lexer& lexer, compiler_context& ctx) -> ast_ref;
auto parse_lambda_expr(lexer& lexer, compiler_context& ctx) -> ast_ref;
auto parse_lang_identifier_expr(lexer& lexer, compiler_context& ctx) -> ast_ref;
auto parse_namespace_stmt(lexer& lexer, compiler_context& ctx) -> ast_ref;
auto parse_paren_expr(lexer& lexer, compiler_context& ctx) -> ast_ref;
auto parse_literal_expr(lexer& lexer, compiler_context& ctx) -> ast_ref;
auto parse_primary_expr(lexer& lexer, compiler_context& ctx) -> ast_ref;
auto parse_top_level_stmt(lexer& lexer, compiler_context& ctx) -> ast_ref;
auto parse_function_decl_stmt(lexer& lexer, compiler_context& ctx) -> ast_ref;
auto parse_type_expr(lexer& lexer, compiler_context& ctx) -> ast_ref;
auto parse_unary_expr(lexer& lexer, compiler_context& ctx) -> ast_ref;
auto parse_using_expr(lexer& lexer, compiler_context& ctx) -> ast_ref;
auto parse_variable_def_expr(lexer& lexer, compiler_context& ctx) -> ast_ref;
auto expect_semi(ast_ref ref, lexer& lexer, compiler_context& ctx) -> ast_ref;

auto parse_if_expr(lexer& lexer, compiler_context& ctx) -> ast_ref;
auto parse_return_expr(lexer& lexer, compiler_context& ctx) -> ast_ref;
auto parse_yield_expr(lexer& lexer, compiler_context& ctx) -> ast_ref;
auto parse_while_expr(lexer& lexer, compiler_context& ctx) -> ast_ref;

auto parse_expr_as_statement(lexer& lexer, compiler_context& ctx) -> ast_ref;
auto parse_struct_literal_expr(lexer& lexer, compiler_context& ctx) -> ast_ref;

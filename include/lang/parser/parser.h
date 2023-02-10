#pragma once

#include <lang/ast/ast.h>
#include <lang/compiler_context.h>
#include <lang/lexer/lexer.h>
#include <memory>

auto parse(lexer& l, compiler_context& ctx) -> ast_ref;

auto parse_binary_op_expr(lexer& l, compiler_context& ctx, int expr_prec, ast_ref lhs) -> ast_ref;
auto parse_block_expr(lexer& l, compiler_context& ctx) -> ast_ref;
auto parse_char_literal_expr(lexer& l, compiler_context& ctx) -> ast_ref;
auto parse_expr(lexer& l, compiler_context& ctx) -> ast_ref;
auto parse_identifier_expr(lexer& l, compiler_context& ctx) -> ast_ref;
auto parse_lambda_expr(lexer& l, compiler_context& ctx) -> ast_ref;
auto parse_lang_identifier_expr(lexer& l, compiler_context& ctx) -> ast_ref;
auto parse_namespace_stmt(lexer& l, compiler_context& ctx) -> ast_ref;
auto parse_paren_expr(lexer& l, compiler_context& ctx) -> ast_ref;
auto parse_literal_expr(lexer& l, compiler_context& ctx) -> ast_ref;
auto parse_primary_expr(lexer& l, compiler_context& ctx) -> ast_ref;
auto parse_top_level_stmt(lexer& l, compiler_context& ctx) -> ast_ref;
auto parse_function_decl_stmt(lexer& l, compiler_context& ctx) -> ast_ref;
auto parse_type_expr(lexer& l, compiler_context& ctx) -> ast_ref;
auto parse_unary_expr(lexer& l, compiler_context& ctx) -> ast_ref;
auto parse_using_expr(lexer& l, compiler_context& ctx) -> ast_ref;
auto parse_variable_def_expr(lexer& l, compiler_context& ctx) -> ast_ref;
auto expect_semi(ast_ref r, lexer& l, compiler_context& ctx) -> ast_ref;

auto parse_if_expr(lexer& l, compiler_context& ctx) -> ast_ref;
auto parse_return_expr(lexer& l, compiler_context& ctx) -> ast_ref;
auto parse_yield_expr(lexer& l, compiler_context& ctx) -> ast_ref;

auto parse_expr_as_statement(lexer& l, compiler_context& ctx) -> ast_ref;
auto parse_struct_literal_expr(lexer& l, compiler_context& ctx) -> ast_ref;

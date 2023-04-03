project('lang', 'cpp', version: '0.0.1', default_options: [
    'cpp_std=c++20', 
    'warning_level=2',
])
add_global_arguments('-DFMT_HEADER_ONLY', language : 'cpp')

sources = [
  'src/compiler.cpp',
  'src/main.cpp',
  'src/lang/sema/simple_namespace.cpp',
  'src/lang/sema/sema_ctx.cpp',
  'src/lang/sema/types.cpp',
  'src/lang/ast/name_ref_expr_ast.cpp',
  'src/lang/ast/block_expr_ast.cpp',
  'src/lang/ast/namespaced_name_ref_expr_ast.cpp',
  'src/lang/ast/using_expr_ast.cpp',
  'src/lang/ast/lang_name_ref_expr_ast.cpp',
  'src/lang/ast/lambda_expr_ast.cpp',
  'src/lang/ast/namespace_stmt_ast.cpp',
  'src/lang/ast/base_ast.cpp',
  'src/lang/ast/unary_op_expr_ast.cpp',
  'src/lang/ast/module_ast.cpp',
  'src/lang/ast/attribute_ast.cpp',
  'src/lang/ast/binary_op_expr_ast.cpp',
  'src/lang/ast/function_decl_stmt_ast.cpp',
  'src/lang/ast/function_call_expr_ast.cpp',
  'src/lang/ast/top_level_blk_ast.cpp',
  'src/lang/ast/struct_literal_expr_ast.cpp',
  'src/lang/ast/char_literal_expr_ast.cpp',
  'src/lang/ast/control/yield_expr_ast.cpp',
  'src/lang/ast/control/while_expr_ast.cpp',
  'src/lang/ast/control/if_expr_ast.cpp',
  'src/lang/ast/control/return_expr_ast.cpp',
  'src/lang/ast/variable_decl_expr_ast.cpp',
  'src/lang/lexer/lexer.cpp',
  'src/lang/utils/function_like_utils.cpp',
  'src/lang/codegen/codegen_value.cpp',
  'src/lang/codegen/codegen_ctx.cpp',
  'src/lang/parser/parse_function_decl_stmt.cpp',
  'src/lang/parser/parse_binary_op_expr.cpp',
  'src/lang/parser/parse_type_expr.cpp',
  'src/lang/parser/parse_namespace_stmt.cpp',
  'src/lang/parser/parser.cpp',
  'src/lang/parser/parse_expect_semi.cpp',
  'src/lang/parser/parse_identifier_expr.cpp',
  'src/lang/parser/parse_char_literal_expr.cpp',
  'src/lang/parser/parse_expr.cpp',
  'src/lang/parser/parse_primary_expr.cpp',
  'src/lang/parser/parse_parse_paren_expr.cpp',
  'src/lang/parser/parse_top_level_stmt.cpp',
  'src/lang/parser/parse_lang_identifier_expr.cpp',
  'src/lang/parser/parse_lambda_expr.cpp',
  'src/lang/parser/parse_variable_def_expr.cpp',
  'src/lang/parser/parse_block_expr.cpp',
  'src/lang/parser/parse_post_identifier.cpp',
  'src/lang/parser/parse_struct_literal_expr.cpp',
  'src/lang/parser/parse_using_expr.cpp',
  'src/lang/parser/parse_attribute_list.cpp',
  'src/lang/parser/control/parse_yield_expr.cpp',
  'src/lang/parser/control/parse_if_expr.cpp',
  'src/lang/parser/control/parse_return_expr.cpp',
  'src/lang/parser/control/parse_while_expr.cpp',
  'src/lang/parser/parse_unary_expr.cpp'
]

include_dirs = [
  'include',
  'deps/magic_enum/include',
  'deps/argparse/include', 
]

llvm_dep = dependency(
  'llvm', 
  version : '>=16.0', 
  modules: ['all']
)

fmt_dep = dependency('fmt')

operator_tblgen = executable(
  'operator-tblgen', 
  'tools/operator_tablegen.cpp', 
  dependencies: [llvm_dep, fmt_dep],
  link_args: ['-lLLVMTableGen'] # TODO: fix
)

lexer_generator = executable(
  'lexer-generator', 
  'tools/lexer_generator.cpp', 
  dependencies: [fmt_dep],
)

operator_tablegen_files = custom_target(
  'operator-tablgen-files', 
  command: [operator_tblgen, '@INPUT@'],
  input: ['src/operators.td'], 
  output: ['binop_codegen.cpp', 'register_ops.cpp']
)

lexer_generator_files = custom_target(
  'lexer-generator-files', 
  command: [lexer_generator, '-o', '@OUTPUT@', '@INPUT@'],
  input: 'src/lexer.leg', 
  output: 'lexer.cpp'
)

compiler = executable(
  'compiler', 
  lexer_generator_files,
  operator_tablegen_files,
  sources, 
  dependencies: [llvm_dep, fmt_dep], 
  include_directories: include_directories(include_dirs)
)

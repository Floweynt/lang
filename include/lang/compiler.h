#pragma once

#include "lang/ast/base_ast.h"
#include "lang/codegen/codegen_ctx.h"
#include "lang/compiler_context.h"
#include "lang/lexer/lexer.h"
#include "lang/lexer/token.h"
#include "lang/parser/parser.h"
#include "lang/sema/sema_ctx.h"
#include <llvm/Analysis/LoopAnalysisManager.h>
#include <llvm/Passes/OptimizationLevel.h>
#include <llvm/Passes/PassBuilder.h>
#include <llvm/Support/raw_ostream.h>
#include <string>

class compiler
{
    compiler_context context;
    lexer lex;
    sema_ctx sema;
    codegen_ctx codegen;
    ast_ref module;

    enum
    {
        NONE,
        AST_PARSED,
        AST_ANALYZED,
        CODE_GENERATED,
        CODE_OPTIMIZED,
        ERROR
    } stage;

public:
    compiler(std::istream& module) : context(module), lex(context), sema(context), codegen(sema), stage(NONE) {}

    // Pipeline stages
    auto parse_src() -> bool;
    auto semantic_analysis() -> bool;
    void emit_ir();
    void optimize(llvm::OptimizationLevel level);
    // Not pipeline stages
    constexpr auto get_compiler_ctx() -> const auto& { return context; };
    auto get_serialized_ast() -> std::string;
    auto get_tokens() -> const std::vector<token>&;
    auto get_raw_ir() -> llvm::Module&;
    auto get_optimized_ir() -> llvm::Module&;
};

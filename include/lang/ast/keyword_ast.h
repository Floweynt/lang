#pragma once

#include "lang/ast/base_ast.h"
#include "lang/codegen/codegen_ctx.h"

#define MAKE_KEYWORD_AST(name, cap_name)                                                                                                             \
    class name##_kw : public base_ast                                                                                                                \
    {                                                                                                                                                \
    public:                                                                                                                                          \
        inline name##_kw(code_location start, code_location end) : base_ast(start, end, cap_name##_KW) {}                                            \
        inline void visit_children(const std::function<void(const base_ast&)>& /* */) const override {}                                              \
        inline auto do_semantic_analysis(sema_ctx& /* */) const -> semantic_analysis_result override { return {nullptr, false}; }                    \
        inline auto do_codegen(codegen_ctx& /* */) const -> codegen_value override { return codegen_value::make_null(); }                            \
        auto serialize() const -> std::string override { return "(" #name "_keyword)"; }                                                             \
    };

MAKE_KEYWORD_AST(auto, AUTO);
MAKE_KEYWORD_AST(const, CONST);
MAKE_KEYWORD_AST(var, VAR);
MAKE_KEYWORD_AST(consteval, CONSTEVAL);
MAKE_KEYWORD_AST(comptime, COMPTIME);

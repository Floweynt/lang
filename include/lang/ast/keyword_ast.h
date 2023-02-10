#pragma once

#include <lang/ast/base_ast.h>

#define MAKE_KEYWORD_AST(name, cap_name)                                                                                                             \
    class name##_kw : public base_ast                                                                                                                \
    {                                                                                                                                                \
    public:                                                                                                                                          \
        inline name##_kw(code_location start, code_location end) : base_ast(start, end, cap_name##_KW) {}                                            \
        inline void visit_children(const std::function<void(const base_ast&)>& f) const override {}                                                  \
        inline semantic_analysis_result do_semantic_analysis(sema_ctx& c) const override { return {nullptr, false}; }                                \
    };

MAKE_KEYWORD_AST(auto, AUTO);
MAKE_KEYWORD_AST(const, CONST);
MAKE_KEYWORD_AST(var, VAR);
MAKE_KEYWORD_AST(consteval, CONSTEVAL);
MAKE_KEYWORD_AST(comptime, COMPTIME);

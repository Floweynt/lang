#pragma once

#include "lang/sema/ct_value.h"
#include "lang/sema/types.h"
#include <functional>
#include <lang/lexer/code_location.h>
#include <lang/sema/sema_ctx.h>
#include <memory>
#include <optional>

enum ast_type
{
    STRING_LITERAL,
    INT_LITERAL,
    FLOAT_LITERAL,
    CHAR_LITERAL,
    NAME_REF,
    BINOP_EXPR,
    UNARY_EXPR,
    FUNCTION_CALL_EXPR,
    PAREN_EXPR,
    VARIABLE_DECL_STMT,
    AUTO_KW,
    CONST_KW,
    VAR_KW,
    CONSTEVAL_KW,
    LANG_NAME_REF,
    USING_STMT,
    LAMBDA_EXPR,
    BLOCK_EXPR,
    COMPTIME_KW,
    NS_STMT,
    TOP_LEVEL_BLOCK,
    IF_EXPR,
    MATCH_EXPR,
    STRUCT_LITERAL_EXPR,
    YIELD_EXPR,
    RETURN_EXPR,
    FUN_DECL_STMT,
    EMPTY_STMT
};

inline static constexpr const char* AST_KIND_NAME[] = {"string_literal",
                                                       "integer_literal",
                                                       "numeric_literal",
                                                       "character_literal",
                                                       "name_reference",
                                                       "binary_op_expression",
                                                       "unary_op_expression",
                                                       "function_call_expression",
                                                       "parenthesized_expression",
                                                       "variable_decl_expression",
                                                       "auto_keyword",
                                                       "const_keyword",
                                                       "var_keyword",
                                                       "consteval_keyword",
                                                       "language_name_reference",
                                                       "using_statement",
                                                       "lambda_expression",
                                                       "block_expression",
                                                       "comptime_keyword",
                                                       "namespace_statement",
                                                       "top_level_block",
                                                       "if_expression",
                                                       "match_expression",
                                                       "struct_literal_expression",
                                                       "yield_expression",
                                                       "return_expression",
                                                       "function_decleration_statement",
                                                       "empty_statement"};

class base_ast
{
    const code_location start;
    const code_location end;
    const ast_type type;
    const bool requires_semicolon_stmt;
    std::optional<semantic_analysis_result> result;

protected:
    // semantic analysis
    virtual semantic_analysis_result do_semantic_analysis(sema_ctx& c) const = 0;

public:
    constexpr base_ast(code_location start, code_location end, ast_type type, bool requires_semicolon_stmt = true)
        : start(start), end(end), type(type), requires_semicolon_stmt(requires_semicolon_stmt)
    {
    }

    // token information
    [[nodiscard]] constexpr auto get_start() const -> const auto& { return start; }
    [[nodiscard]] constexpr auto get_end() const -> const auto& { return end; }
    [[nodiscard]] constexpr auto range() const { return code_range{start, end}; }
    [[nodiscard]] constexpr auto get_ast_kind() const { return type; }
    [[nodiscard]] constexpr auto does_require_semicolon_stmt() const { return requires_semicolon_stmt; }

    // virtual functions to be implemented
    // tree iteration
    virtual void visit_children(const std::function<void(const base_ast&)>& f) const = 0;
    // get semantic result
    inline auto semantic_analysis(sema_ctx& c) -> const auto&
    {
        if (!result)
            result = do_semantic_analysis(c);
        return *result;
    }

    virtual ct_value do_consteval(sema_ctx& c) const;

    // destructor
    virtual ~base_ast() = default;
};

using ast_ref = std::unique_ptr<base_ast>;

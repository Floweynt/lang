#pragma once
#include "lang/compiler_context.h"
#include "lang/sema/types.h"
#include <lang/ast/base_ast.h>

#include <llvm/IR/Constants.h>
#include <utility>

template <typename T>
class literal_expr : public base_ast
{
    T val;
    std::string literal;

protected:
    auto do_semantic_analysis(sema_ctx& context) const -> semantic_analysis_result override
    {
        if constexpr (std::is_same_v<T, std::string>)
        {
            const auto* literal_type = context.resolve_literal_string(literal);
            if (literal_type == context.langtype(primitive_type::ERROR))
            {
                context.get_compiler_ctx().report_diagnostic({{range(), "unknown string literal specifier '" + literal + "'"}});
            }
            return {literal_type, literal_type != context.langtype(primitive_type::ERROR)};
        }

        else if constexpr (std::is_same_v<T, intmax_t>)
        {
            const auto* literal_type = context.resolve_literal_integer(literal);
            if (literal_type == context.langtype(primitive_type::ERROR))
            {
                context.get_compiler_ctx().report_diagnostic({{range(), "unknown integer literal specifier '" + literal + "'"}});
            }

            if (literal_type->is_integral())
            {
                if (literal_type->is_unsigned_integral() && val < 0)
                {
                    context.get_compiler_ctx().report_diagnostic({{range(), "integer literal specifier is unsigned; the value is not"}});
                }

                // not implement
            }

            return {literal_type, literal_type != context.langtype(primitive_type::ERROR)};
        }
        else
        {
            const auto* literal_type = context.resolve_literal_floating(literal);
            if (literal_type == context.langtype(primitive_type::ERROR))
            {
                context.get_compiler_ctx().report_diagnostic({{range(), "unknown floating literal specifier '" + literal + "'"}});
            }
            return {literal_type, literal_type != context.langtype(primitive_type::ERROR)};
        }
    }

    auto do_codegen(codegen_ctx& context) const -> codegen_value override
    {
        if constexpr (std::is_same_v<T, std::string>)
        {
            return context.make_literal_string(literal, val);
        }
        else if constexpr (std::is_same_v<T, intmax_t>)
        {
            return context.make_literal_integer(literal, val);
        }
        else
        {
            return context.make_literal_floating(literal, val);
        }
    }

public:
    literal_expr(code_location start, code_location end, T val, std::string literal)
        : base_ast(start, end,
                   []() constexpr {
                       if constexpr (std::is_same_v<T, std::string>)
                       {
                           return STRING_LITERAL;
                       }
                       else if constexpr (std::is_same_v<T, intmax_t>)
                       {
                           return INT_LITERAL;
                       }
                       return FLOAT_LITERAL;
                   }()),
          val(std::move(val)), literal(std::move(literal))
    {
    }

    void visit_children(const std::function<void(const base_ast&)>& consumer) const override {}

    auto serialize() const -> std::string override
    {
        if constexpr (std::is_same_v<T, std::string>)
        {
            return fmt::format("(string_literal \"{}\")", val);
        }
        else if constexpr (std::is_same_v<T, intmax_t>)
        {
            return fmt::format("(integer_literal \"{}\")", val);
        }

        return fmt::format("(numeric_literal \"{}\")", val);
    }

    constexpr auto get_literal() -> const auto& { return literal; }
    constexpr auto get_value() -> const auto& { return val; }
};

template class literal_expr<intmax_t>;
template class literal_expr<std::string>;
template class literal_expr<long double>;

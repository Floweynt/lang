#pragma once
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
        switch (get_ast_kind())
        {
        case STRING_LITERAL:
            // not implemented
        case INT_LITERAL:
            return {context.langtype(primitive_type::INTEGRAL_SIGNED_B32), true};
        case FLOAT_LITERAL:
            return {context.langtype(primitive_type::FLOATING_B32), true};
        default:
            __builtin_unreachable();
        }

        __builtin_unreachable();
    }

    inline auto do_codegen(codegen_ctx& context) const -> codegen_value override
    {
        if constexpr (std::is_same_v<T, std::string>)
        {
            __builtin_unreachable();
        }
        else if constexpr (std::is_same_v<T, intmax_t>)
        {
            return codegen_value::make_constant(
                get_sema_result().ty,
                llvm::ConstantInt::get(context.get_sema_ctx().langtype(primitive_type::INTEGRAL_SIGNED_B32)->get_llvm_type(context), val));
        }
        else
        {
            __builtin_unreachable();
            // return llvm::ConstantFl::get(context.get_sema_ctx().langtype(primitive_type::FLOATING_B64)->get_llvm_type(context), val);
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
    inline auto serialize() const -> std::string override
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

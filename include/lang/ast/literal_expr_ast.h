#pragma once
#include "lang/sema/types.h"
#include <lang/ast/base_ast.h>

template <typename T>
class literal_expr : public base_ast
{
    T val;
    std::string literal;

protected:
    virtual semantic_analysis_result do_semantic_analysis(sema_ctx& c) const override
    {
        switch (get_ast_kind())
        {
        case STRING_LITERAL:
            // not implemented
        case INT_LITERAL:
            return {c.langtype(primitive_type::INTEGRAL_SIGNED_B32), true};
        case FLOAT_LITERAL:
            return {c.langtype(primitive_type::FLOATING_B32), true};
        default:
            __builtin_unreachable();
        }

        __builtin_unreachable();
    }

public:
    literal_expr(code_location start, code_location end, T val, std::string literal)
        : base_ast(start, end,
                   []() constexpr {
                       if constexpr (std::is_same_v<T, std::string>)
                           return STRING_LITERAL;
                       else if constexpr (std::is_same_v<T, intmax_t>)
                           return INT_LITERAL;
                       return FLOAT_LITERAL;
                   }()),
          val(val), literal(literal)
    {
    }

    virtual void visit_children(const std::function<void(const base_ast&)>& f) const override {}

    constexpr const auto& get_literal() { return literal; }
    constexpr const auto& get_value() { return val; }
};

template class literal_expr<intmax_t>;
template class literal_expr<std::string>;
template class literal_expr<long double>;

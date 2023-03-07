#include "lang/ast/operator_types.h"
#include <lang/parser/parser.h>

static auto tok_to_unary_op(token::operators op) -> unary_op_type
{
    static constexpr int TOK_TO_BIN_OP[] = {
        OP_INC,
        OP_DEC,
        -1,
        OP_PROMOTE,
        OP_NEGATE,
        OP_LOGICAL_NOT,
        OP_BITWISE_NOT,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        OP_ASSIGN,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
        -1,
    };

    return (unary_op_type)TOK_TO_BIN_OP[op];
}

auto parse_unary_expr(lexer& lexer, compiler_context& ctx) -> ast_ref
{
    if (!lexer.curr_token().is(token::TOK_OPERATOR))
    {
        return parse_primary_expr(lexer, ctx);
    }

    auto start = lexer.curr_token().location();
    auto op = lexer.curr_token().op();
    auto op_range = lexer.curr_token().range();
    lexer.consume();

    if (auto operand = parse_primary_expr(lexer, ctx))
    {
        return std::make_unique<unary_op_expr>(start, operand->get_end(), op_range, tok_to_unary_op(op), std::move(operand));
    }
    return nullptr;
}

#include "lang/ast/binary_op_expr_ast.h"
#include <lang/parser/parser.h>

static int get_tok_prec(const token& op)
{
    if (!op.is(token::TOK_OPERATOR))
        return -1;

    static constexpr int TOKEN_PRECEDENCE[] = {
        1000, -1, -1, 130, 110, 110, -1, -1, 120, 60, 120, 120, 100, 100, 90, 80, 80, 80, 80,
        70,   70, 50, 40,  30,  20,  10, 10, 10,  10, 10,  10,  10,  10,  10, 10, 10, -1,
    };

    return TOKEN_PRECEDENCE[op.get_value<token::operators>()];
}

static binary_op_type tok_to_bin_op(token::operators op)
{
    static constexpr int TOK_TO_BIN_OP[] = {
        OP_NAMESPACED_REFERENCE,
        -1,
        -1,
        OP_MEMBER_ACCESS,
        OP_ADD,
        OP_SUB,
        -1,
        -1,
        OP_MUL,
        OP_BITWISE_AND,
        OP_DIV,
        OP_MOD,
        OP_SHL,
        OP_SHR,
        OP_SPACESHIP,
        OP_LESS,
        OP_LEQ,
        OP_GREATER,
        OP_GEQ,
        OP_EQ,
        OP_NEQ,
        OP_BITWISE_XOR,
        OP_BITWISE_OR,
        OP_LOGICAL_AND,
        OP_LOGICAL_OR,
        OP_ASSIGN,
        OP_ADD_ASSIGN,
        OP_SUB_ASSIGN,
        OP_MUL_ASSIGN,
        OP_DIV_ASSIGN,
        OP_MOD_ASSIGN,
        OP_SHL_ASSIGN,
        OP_SHR_ASSIGN,
        OP_AND_ASSIGN,
        OP_XOR_ASSIGN,
        OP_OR_ASSIGN,
        -1,
    };

    return (binary_op_type)TOK_TO_BIN_OP[op];
}

ast_ref parse_binary_op_expr(lexer& l, compiler_context& ctx, int expr_prec, ast_ref lhs)
{
    while (true)
    {
        int curr_prec = get_tok_prec(l.curr_token());

        if (curr_prec < expr_prec)
            return lhs;

        auto op = l.curr_token().op();
        auto op_range = l.curr_token().range();
        l.consume();

        auto rhs = parse_unary_expr(l, ctx);
        if (!rhs)
            return nullptr;

        int next_prec = get_tok_prec(l.curr_token());
        if (curr_prec < next_prec)
        {
            rhs = parse_binary_op_expr(l, ctx, curr_prec + 1, std::move(rhs));
            if (!rhs)
                return nullptr;
        }

        lhs = std::make_unique<binary_op_expr>(tok_to_bin_op(op), op_range, std::move(lhs), std::move(rhs));
    }
}

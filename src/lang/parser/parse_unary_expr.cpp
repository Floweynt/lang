#include <lang/parser/parser.h>

static unary_op_type tok_to_unary_op(token::operators op)
{
    static constexpr int TOK_TO_BIN_OP[] = {
        -1, OP_INC, -1, -1, -1, -1, -1, -1,        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1,     -1, -1, -1, -1, -1, OP_ASSIGN, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    };

    return (unary_op_type)TOK_TO_BIN_OP[op];
}

ast_ref parse_unary_expr(lexer& l, compiler_context& ctx)
{
    if (!l.curr_token().is(token::TOK_OPERATOR))
        return parse_primary_expr(l, ctx);

    auto start = l.curr_token().location();
    auto op = l.curr_token().op();
    auto op_range = l.curr_token().range();
    l.consume();

    if (auto operand = parse_unary_expr(l, ctx))
        return std::make_unique<unary_op_expr>(start, operand->get_end(), op_range, tok_to_unary_op(op), std::move(operand));
    return nullptr;
}

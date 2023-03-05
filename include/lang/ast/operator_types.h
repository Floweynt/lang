#pragma once

enum binary_op_type
{
    OP_BAD_BINARY = -1,

    // misc
    OP_MEMBER_ACCESS,

    // bitwise
    OP_BITWISE_AND,
    OP_BITWISE_XOR,
    OP_BITWISE_OR,
    OP_SHR,
    OP_SHL,

    OP_LOGICAL_AND,
    OP_LOGICAL_OR,

    // compare
    OP_SPACESHIP,
    OP_LESS,
    OP_LEQ,
    OP_GREATER,
    OP_GEQ,
    OP_EQ,
    OP_NEQ,

    // simple math
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_MOD,

    // assignment
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
};

inline static constexpr const char* OPERATOR_SYMBOLS[] = {
    ".", "&", "^", "|", ">>", "<<", "&&", "||", "<=>", "<",  "<=",  ">",   ">=", "==", "!=",
    "+", "-", "*", "/", "%",  "=",  "+=", "-=", "*=",  "%=", "<<=", ">>=", "&=", "^=", "|=",
};

enum unary_op_type
{
    OP_BAD_UNARY = -1,
    OP_INC,
    OP_DEC,
    OP_LOGICAL_NOT,
    OP_BITWISE_NOT,
    OP_PROMOTE,
    OP_NEGATE
};

#pragma once
#include "code_location.h"
#include <string>
#include <variant>

template <typename T>
struct literal_value
{
    T value;
    std::string literal_specifier;
};

class token
{
public:
    enum operators
    {
        OP_NS = 0,      // ::
        OP_INC,         // ++
        OP_DEC,         // --
        OP_MEMBER,      // .
        OP_PLUS,        // +
        OP_MINUS,       // -
        OP_LOGICAL_NOT, // !
        OP_BITWISE_NOT, // ~
        OP_STAR,        // *
        OP_AT,          // &
        OP_DIV,         // /
        OP_MOD,         // %
        OP_SHL,         // <<
        OP_SHR,         // >>
        OP_SPACESHIP,   // <=>
        OP_LESS,        // <
        OP_LEQ,         // <=
        OP_GREATER,     // >
        OP_GEQ,         // >=
        OP_EQ,          // ==
        OP_NEQ,         // !=
        OP_BITWISE_XOR, // ^
        OP_BITWISE_OR,  // |
        OP_LOGICAL_AND, // &&
        OP_LOGICAL_OR,  // ||
        OP_ASSIGN,      // =
        OP_ADD_ASSIGN,  // +=
        OP_SUB_ASSIGN,  // -=
        OP_MUL_ASSIGN,  // *=
        OP_DIV_ASSIGN,  // /=
        OP_MOD_ASSIGN,  // %=
        OP_SHL_ASSIGN,  // <<=
        OP_SHR_ASSIGN,  // >>=
        OP_AND_ASSIGN,  // &=
        OP_XOR_ASSIGN,  // ^=
        OP_OR_ASSIGN,   // |=
        OP_ARROW        // ->
    };

    enum types
    {
        // identifier types
        TOK_IDENTIFIER,
        TOK_LANG_IDENTIFIER, // @id

        // other stuff
        TOK_EOF,

        // constant types
        TOK_INTEGER,
        TOK_FLOATING,
        TOK_STRING,
        TOK_CHAR,

        // operators
        TOK_OPERATOR,

        // punctuation
        TOK_PAREN_OPEN,
        TOK_PAREN_CLOSE,
        TOK_BRACKET_OPEN,
        TOK_BRACKET_CLOSE,
        TOK_ATTR_OPEN,
        TOK_ATTR_CLOSE,
        TOK_BRACE_OPEN,
        TOK_BRACE_CLOSE,
        TOK_SEMICOLON,
        TOK_COLON,
        TOK_COMMA,
        TOK_BKSLASH,
        TOK_ELLIPSIS,

        // keywords
        TOK_KW_AUTO,
        TOK_KW_FN,
        TOK_KW_CONST,
        TOK_KW_VAR,
        TOK_KW_CONSTEVAL,
        TOK_KW_COMPTIME,
        TOK_KW_USING,
        TOK_KW_NAMESPACE,

        TOK_KW_YIELD,
        TOK_KW_RETURN,

        TOK_KW_IF,
        TOK_KW_ELSE,
        TOK_KW_FOR,
        TOK_KW_WHILE,
        TOK_KW_MATCH,
        TOK_KW_CASE,

        TOK_KW_STRUCT
    };

private:
    std::variant<literal_value<std::string>, literal_value<intmax_t>, literal_value<long double>, std::string, operators, char, std::monostate> value;

    types tok;
    code_location loc;
    code_location end;

public:
    constexpr token(const code_location& loc, const code_location& end, types tok, const auto& val) : value(val), tok(tok), loc(loc), end(end) {}
    constexpr token(const code_location& loc, const code_location& end, types tok) : value(std::monostate()), tok(tok), loc(loc), end(end) {}

    [[nodiscard]] constexpr auto type() const -> types { return tok; }
    [[nodiscard]] constexpr auto identifier() const -> const auto& { return std::get<std::string>(value); }

    template <typename T>
    constexpr auto get_literal() const -> const auto&
    {
        return std::get<literal_value<T>>(value);
    }

    [[nodiscard]] constexpr auto op() const { return std::get<operators>(value); }

    [[nodiscard]] constexpr auto location() const -> const code_location& { return loc; }
    [[nodiscard]] constexpr auto end_location() const -> const code_location& { return end; }
    [[nodiscard]] constexpr auto range() const -> code_range { return {loc, end}; }

    template <typename T>
    constexpr auto get_value() const -> const auto&
    {
        return std::get<T>(value);
    }

    template <typename T>
    [[nodiscard]] constexpr auto has_value() const -> bool
    {
        return std::holds_alternative<T>(value);
    }

    constexpr auto operator==(operators rhs) const -> bool { return type() == TOK_OPERATOR && op() == rhs; }
    [[nodiscard]] constexpr auto is(types tok) const -> bool { return type() == tok; }
};

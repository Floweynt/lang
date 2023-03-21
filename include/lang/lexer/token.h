#pragma once
#include "code_location.h"
#include "lang/compiler_context.h"
#include <cctype>
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
        OP_INC = 0,     // ++
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
        TOK_DOUBLECOLON,

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

        TOK_KW_STRUCT,

        TOK_KW_MODULE,
        TOK_KW_IMPORT
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

inline auto from_integer_literal(const code_location& loc, const code_location& end, const std::string& value, int base) -> token
{
    size_t index = 0;
    auto lit_value = std::stoll(value, &index, base);
    auto lit_specifier = value.substr(index);
    return token(loc, end, token::TOK_INTEGER, literal_value<intmax_t>{lit_value, lit_specifier});
}

inline auto from_double_literal(const code_location& loc, const code_location& end, const std::string& value) -> token
{
    size_t index = 0;
    auto lit_value = std::stold(value, &index);
    auto lit_specifier = value.substr(index);
    return token(loc, end, token::TOK_FLOATING, literal_value<long double>{lit_value, lit_specifier});
}

inline auto from_string_literal(compiler_context& ctx, const code_location& loc, const code_location& end, const std::string& value) -> token
{
    std::string str = value.substr(1, value.find_last_of('"') - 1);
    std::string result;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '\\')
        {
            if (i + 1 >= str.length())
            {
                ctx.report_error(loc, end, "invalid escape sequence at end of string");
                break; // stop processing the string
            }
            switch (str[i + 1])
            {
            case 'n':
                result += '\n';
                break;
            case 't':
                result += '\t';
                break;
            case 'r':
                result += '\r';
                break;
            case '\'':
                result += '\'';
                break;
            case '\"':
                result += '\"';
                break;
            case '\\':
                result += '\\';
                break;
            case 'x': {
                if (i + 3 >= str.length())
                {
                    ctx.report_error(loc, end, "incomplete hexadecimal escape sequence");
                    result += str.substr(i, 2); // append the original escape sequence
                    break;                      // continue processing the string
                }
                char hex[3] = {str[i + 2], str[i + 3], '\0'};
                int value = std::stoi(hex, nullptr, 16);
                result += static_cast<char>(value);
                i += 3; // skip the next 3 characters (the \x and two hex digits)
                break;
            }
            case '0': {
                bool valid = false;
                int value = 0;
                for (int j = i + 1; j <= i + 3 && j < str.length(); j++)
                {
                    if (str[j] >= '0' && str[j] <= '7')
                    {
                        valid = true;
                        value = (value << 3) + (str[j] - '0');
                    }
                    else
                    {
                        break;
                    }
                }
                if (!valid)
                {
                    if (i + 1 == str.length() || (i + 2 < str.length() && str[i + 2] >= '0' && str[i + 2] <= '7'))
                    {
                        result += '\0';
                        i++; // skip the next character ('\0')
                    }
                    else
                    {
                        ctx.report_error(loc, end, "incomplete or invalid octal escape sequence");
                        result += str.substr(i, 2); // append the original escape sequence
                        break;                      // continue processing the string
                    }
                }
                else
                {
                    result += static_cast<char>(value);
                    i += 3; // skip the next 3 characters (the \0 and up to three octal digits)
                }
                break;
            }
            default: {
                result += str[i + 1]; // append the character
                break;
            }
            }
            i++;
        }
        else
        {
            result += str[i];
        }
    }

    return token(loc, end, token::TOK_STRING, literal_value<std::string>{result, value.substr(value.find_last_of('"') + 1)});
}

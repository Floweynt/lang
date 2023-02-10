#pragma once
#include <fmt/core.h>
#include <iostream>
#include <istream>
#include <lang/lexer/code_location.h>
#include <optional>
#include <string>
#include <variant>
#include <vector>

struct error
{
    std::variant<code_range, code_location> main_error;
    std::string message;
    std::optional<std::string> fix;
    std::vector<std::pair<code_range, std::string>> related;
};

class compiler_context
{
    std::istream& is;
    std::vector<error> errors;

public:
    compiler_context(std::istream& is) : is(is) {}

    constexpr std::istream& io() { return is; }

    constexpr void report_error(const code_location& from, const code_location& to, const std::string& err, const std::string& fix)
    {
        report_error(error{code_range{from, to}, err, fix, {}});
    }

    constexpr void report_error(const code_location& loc, const std::string& err, const std::string& fix) { report_error(error{loc, err, fix, {}}); }

    constexpr void report_error(const code_location& from, const code_location& to, const std::string& err)
    {
        report_error(error{code_range{from, to}, err, std::nullopt, {}});
    }

    constexpr void report_error(const code_location& loc, const std::string& err) { report_error(error{loc, err, std::nullopt, {}}); }

    constexpr void report_error(const error& e) { errors.push_back(e); }

    constexpr const auto& get_errors() const { return errors; }
};

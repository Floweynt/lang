#pragma once
#include <fmt/core.h>
#include <iostream>
#include <istream>
#include <lang/lexer/code_location.h>
#include <optional>
#include <string>
#include <variant>
#include <vector>

struct diagnostic
{
    struct diagnostic_entry
    {
        std::variant<code_range, code_location, std::monostate> location;
        std::string message;
    };

    diagnostic_entry main_diagnostic;
    std::optional<std::string> fix;
    std::vector<diagnostic_entry> related;

    enum
    {
        error = 0,
        warning,
        info
    } diagnostic_level = error;
};

class compiler_context
{
    std::istream& stream;
    std::vector<diagnostic> errors;
    size_t error_count{};
    size_t warning_count{};
    size_t info_count{};

public:
    compiler_context(std::istream& stream) : stream(stream) {}

    constexpr std::istream& io() { return stream; }

    constexpr void report_error(const code_location& from, const code_location& to, const std::string& err, const std::string& fix)
    {
        report_diagnostic(diagnostic{{code_range{from, to}, err}, fix, {}});
    }

    constexpr void report_error(const code_location& loc, const std::string& err, const std::string& fix)
    {
        report_diagnostic(diagnostic{{loc, err}, fix, {}});
    }

    constexpr void report_error(const code_location& from, const code_location& to, const std::string& err)
    {
        report_diagnostic(diagnostic{{code_range{from, to}, err}, std::nullopt, {}});
    }

    constexpr void report_error(const code_location& loc, const std::string& err) { report_diagnostic(diagnostic{{loc, err}, std::nullopt, {}}); }

    constexpr void report_diagnostic(const diagnostic& err)
    {
        switch (err.diagnostic_level)
        {
        case diagnostic::error:
            error_count++;
            break;
        case diagnostic::warning:
            warning_count++;
            break;
        case diagnostic::info:
            info_count++;
            break;
        }
        errors.push_back(err);
    }

    [[nodiscard]] constexpr auto get_diagnostics() const -> const auto& { return errors; }

    [[nodiscard]] constexpr auto get_error_count() const { return error_count; }
    [[nodiscard]] constexpr auto get_warning_count() const { return warning_count; }
    [[nodiscard]] constexpr auto get_info_count() const { return info_count; }
};

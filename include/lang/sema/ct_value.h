#pragma once

#include <any>

class type;
class ct_value
{
    const type* type;
    std::any value;

public:
    template <typename T>
    ct_value(const class type* type, const T& val) : type(type), value(val)
    {
    }

    [[nodiscard]] constexpr auto get_type() const { return type; }

    template <typename T>
    auto get_value() const -> T
    {
        return std::any_cast<T>(value);
    }
};

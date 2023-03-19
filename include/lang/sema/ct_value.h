#pragma once

#include <any>

class type;
class ct_value
{
    const type* ty;
    std::any value;

public:
    template <typename T>
    ct_value(const type* ty, const T& val) : ty(ty), value(val)
    {
    }

    [[nodiscard]] constexpr auto get_type() const { return ty; }

    template <typename T>
    auto get_value() const -> T
    {
        return std::any_cast<T>(value);
    }
};

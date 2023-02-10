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

    constexpr auto get_type() const { return type; }

    template <typename T>
    T get_value()
    {
        return std::any_cast<T>(value);
    }
};

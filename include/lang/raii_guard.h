#pragma once

#include <concepts>

template <std::invocable T>
class raii_guard
{
    T value;

public:
    constexpr raii_guard(T exit_action) : value(exit_action) {}
    ~raii_guard() { value(); }
};

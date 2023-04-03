#pragma once

#include <utility>

template <class F>
struct y_combinator
{
    F f; // the lambda will be stored here

    // a forwarding operator():
    template <class... Args>
    auto operator()(Args&&... args) const -> decltype(auto)
    {
        // we pass ourselves to f, then the arguments.
        return f(*this, std::forward<Args>(args)...);
    }
};

// helper function that deduces the type of the lambda:
template <class F>
auto make_y_combinator(F&& f) -> y_combinator<std::decay_t<F>>
{
    return {std::forward<F>(f)};
}

template <class F>
y_combinator(F) -> y_combinator<F>;

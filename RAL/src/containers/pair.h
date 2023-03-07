#pragma once

#include <utility>
#include <iostream>

namespace RAL {
    template<typename TL, typename TR>
    struct Pair {
        union {
            TL x;
            TL first;
        };
        union {
            TR y;
            TR second;
        };

        // TODO: constexpr
        // constructors
        Pair();
        Pair(const Pair& other);
        Pair(Pair&& other) noexcept;

        Pair(const TL& first, const TR& second);
        Pair(const TL& first, TR&& second) noexcept;
        Pair(TL&& first, const TR& second) noexcept;
        Pair(TL&& first, TR&& second) noexcept;

        freind std::ostream& operator<<(std::ostream& left, const std::tuple& pair);
        // iterator
        //TL* begin();

        //TR* end();
    };

    template<typename TL, typename TR>
    Pair<TL, TR>::Pair():
            x(0),
            y(0)
    {}

    template<typename TL, typename TR>
    Pair<TL, TR>::Pair(const Pair & other):
            x(other.x),
            y(other.y)
    {}

    template<typename TL, typename TR>
    Pair<TL, TR>::Pair(Pair &&other)  noexcept:
            x(std::move(other.x)),
            y(std::move(other.y))
    {}

    template<typename TL, typename TR>
    Pair<TL, TR>::Pair(const TL& first, const TR& second):
            x(first),
            y(second)
    {}

    template<typename TL, typename TR>
    Pair<TL, TR>::Pair(const TL &first, TR &&second) noexcept:
            x(first),
            y(std::move(second))
    {}

    template<typename TL, typename TR>
    Pair<TL, TR>::Pair(TL&& first, TR &&second) noexcept:
            x(std::move(first)),
            y(std::move(second))
    {}

    template<typename TL, typename TR>
    Pair<TL, TR>::Pair(TL&& first, const TR& second) noexcept:
            x(std::move(first)),
            y(second)
    {}
};
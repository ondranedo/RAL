#pragma once

#include <utility>
#include <iostream>

namespace RAL {
    template<typename TL, typename TR>
    struct Pair {
        TL x;
        TR y;

        // TODO: constexpr
        // constructors
        Pair();
        Pair(const Pair& other);
        Pair(Pair&& other) noexcept;

        Pair(const TL& first, const TR& second);
        Pair(const TL& first, TR&& second) noexcept;
        Pair(TL&& first, const TR& second) noexcept;
        Pair(TL&& first, TR&& second) noexcept;

        Pair<TL,TR>& operator=(const Pair<TL,TR>& other);
        Pair<TL,TR>& operator=(Pair<TL,TR> &&other) noexcept;
    };

    template<typename TL, typename TR>
    Pair<TL, TR> &Pair<TL, TR>::operator=(const Pair<TL,TR> &other) {
        this->x = other.x;
        this->y = other.y;
        return *this;
    }


    template<typename TL, typename TR>
    Pair<TL,TR>& Pair<TL, TR>::operator=(Pair<TL,TR> &&other) noexcept {
        this->x = std::move(other.x);
        this->y = std::move(other.y);
        memset(&x,0, sizeof(x));
        memset(&y,0, sizeof(y));

        return *this;
    }

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
    {
        std::memset(&other.x, 0, sizeof(other.x));
        std::memset(&other.y, 0, sizeof(other.y));
    }

    template<typename TL, typename TR>
    Pair<TL, TR>::Pair(const TL& first, const TR& second):
            x(first),
            y(second)
    {}

    template<typename TL, typename TR>
    Pair<TL, TR>::Pair(const TL &first, TR &&second) noexcept:
            x(first),
            y(std::move(second))
    {
    }

    template<typename TL, typename TR>
    Pair<TL, TR>::Pair(TL&& first, TR &&second) noexcept:
            x(std::move(first)),
            y(std::move(second))
    {}

    template<typename TL, typename TR>
    Pair<TL, TR>::Pair(TL&& first, const TR& second) noexcept:
            x(std::move(first)),
            y(second)
    {
    }
};
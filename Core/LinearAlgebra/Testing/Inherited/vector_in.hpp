#pragma once

#include <initializer_list>
#include <array>
#include <iostream>
#include <algorithm>

template <typename T, size_t C>
class Vector : public std::array<T, C> {
    public:
        Vector(std::initializer_list<T>);
        Vector(double);
        Vector(int);
        Vector(std::array<T, C>);
        Vector(const Vector<T, C>&);
};

template <typename T, size_t C>
void operator + (Vector<T, C> lhs, double rhs) {
    std::for_each(lhs.begin(), lhs.end(), [rhs](auto& element) noexcept {
        element += rhs;
    });
}
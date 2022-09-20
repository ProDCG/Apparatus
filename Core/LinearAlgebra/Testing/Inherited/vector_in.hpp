#pragma once

#include <initializer_list>
#include <array>
#include <iostream>
#include <algorithm>

template <typename T, size_t C>
class Vector : public std::array<T, C> {
    public:
        Vector();
        Vector(std::initializer_list<T> list) {
            std::copy(list.begin(), list.end(), Vector::begin());
        }
        Vector(double);
        Vector(int);
        Vector(std::array<T, C> arr) {
            std::copy(arr.begin(), arr.end(), Vector::begin());
        }
};

template <typename T, size_t C>
void operator + (Vector<T, C> lhs, double rhs) {
    std::for_each(lhs.begin(), lhs.end(), [rhs](auto& element) noexcept {
        element += rhs;
    });
}
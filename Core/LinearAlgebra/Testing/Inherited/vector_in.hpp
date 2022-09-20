#pragma once

#include <initializer_list>
#include <array>
#include <iostream>
#include <algorithm>

template <size_t T, size_t C>
class Vector : public std::array<T, C> {
    public:
        Vector() {
            std::for_each(begin(), end(), [&](auto &element) {
                value = T;
            });
        }
        Vector(std::initializer_list<T>);
        Vector(double);
        Vector(int);
        Vector(std::array<T, C>);
        Vector(Vector<T, C>);
};
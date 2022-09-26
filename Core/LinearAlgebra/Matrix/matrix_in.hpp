#pragma once

#include <initializer_list>
#include <array>
#include <algorithm>
#include <iostream>

template <typename T, size_t C, size_t R>
class Matrix : public std::array<std::array<T, C>, R> {
    public:
        Matrix();

        Matrix(double num) {
            int i = 0;
            std::for_each([0].begin(), [0].end(), [&](auto& element) noexcept {
                std::cout << i << ' ' << std::endl;
            });
        }
};
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
            // int i = 0;
            // std::for_each([0].begin(), [0].end(), [&](auto& element) noexcept {
            //     std::cout << i << ' ' << std::endl;
            // });
        }
        Matrix(int num) {}
        Matrix(std::initializer_list<std::initializer_list<T>>) {}

        void print() const {}
};

template <typename T, size_t C, size_t R>
Matrix<T, C, R> operator + (Matrix<T, C, R> lhs, double scalar) {
    std::for_each(lhs.begin(), lhs.end(), [scalar](auto& row) noexcept {
        std::for_each(row.begin(), row.end(), [scalar](auto& element) noexcept {
            element += scalar;
        });
    });
    return lhs;
}
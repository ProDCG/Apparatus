#pragma once

#include <initializer_list>
#include <array>
#include <algorithm>
#include <iostream>

#include "../Vector/vector_in.hpp"

template <typename T, size_t C, size_t R>
class Matrix : public std::array<std::array<T, C>, R> {
    public:
        Matrix();
        Matrix(double num) {
            std::for_each(Matrix::begin(), Matrix::end(), [&](auto& row) noexcept {
                std::for_each(row.begin(), row.end(), [&](auto& element) noexcept {
                    element = num;
                });
            });
        }
        Matrix(int num) {}
        Matrix(std::initializer_list<std::initializer_list<T>>) {}

        void print() const {
            std::for_each(Matrix::begin(), Matrix::end(), [&](auto& row) noexcept {
                std::for_each(row.begin(), row.end(), [&](auto& element) noexcept {
                    std::cout << element << ' ';
                });
                std::cout << '\n';
            });
        }
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

template <typename T, size_t C, size_t R>
Matrix<T, C, R> operator - (Matrix<T, C, R> lhs, double scalar) {
    std::for_each(lhs.begin(), lhs.end(), [scalar](auto& row) noexcept {
        std::for_each(row.begin(), row.end(), [scalar](auto& element) noexcept {
            element -= scalar;
        });
    });
    return lhs;
}

template <typename T, size_t C, size_t R>
Matrix<T, C, R> operator * (Matrix<T, C, R> lhs, double scalar) {
    std::for_each(lhs.begin(), lhs.end(), [scalar](auto& row) noexcept {
        std::for_each(row.begin(), row.end(), [scalar](auto& element) noexcept {
            element *= scalar;
        });
    });
    return lhs;
}

template <typename T, size_t C, size_t R>
Matrix<T, C, R> operator / (Matrix<T, C, R> lhs, double scalar) {
    std::for_each(lhs.begin(), lhs.end(), [scalar](auto& row) noexcept {
        std::for_each(row.begin(), row.end(), [scalar](auto& element) noexcept {
            element /= scalar;
        });
    });
    return lhs;
}
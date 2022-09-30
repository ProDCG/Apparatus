#pragma once

#include <initializer_list>
#include <array>
#include <algorithm>
#include <iostream>

#include "../Vector/vector_in.hpp"

template <typename T, size_t R, size_t C>
class Matrix : public std::array<std::array<T, R>, C> {
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
        Matrix(std::initializer_list<std::initializer_list<T>> list) {
            auto element_it = Matrix::begin();

            for (auto& row : list) {
                std::copy(row.begin(), row.end(), element_it->begin());
                ++element_it;
            }
        }

        void print() const {
            std::for_each(Matrix::begin(), Matrix::end(), [&](auto& row) noexcept {
                std::for_each(row.begin(), row.end(), [&](auto& element) noexcept {
                    std::cout << element << ' ';
                });
                std::cout << '\n';
            });
        }
};

template <typename T, size_t R, size_t C>
Matrix<T, R, C> operator + (Matrix<T, R, C> lhs, double scalar) {
    std::for_each(lhs.begin(), lhs.end(), [scalar](auto& row) noexcept {
        std::for_each(row.begin(), row.end(), [scalar](auto& element) noexcept {
            element += scalar;
        });
    });
    return lhs;
}

template <typename T, size_t R, size_t C>
Matrix<T, R, C> operator - (Matrix<T, R, C> lhs, double scalar) {
    std::for_each(lhs.begin(), lhs.end(), [scalar](auto& row) noexcept {
        std::for_each(row.begin(), row.end(), [scalar](auto& element) noexcept {
            element -= scalar;
        });
    });
    return lhs;
}

template <typename T, size_t R, size_t C>
Matrix<T, R, C> operator * (Matrix<T, R, C> lhs, double scalar) {
    std::for_each(lhs.begin(), lhs.end(), [scalar](auto& row) noexcept {
        std::for_each(row.begin(), row.end(), [scalar](auto& element) noexcept {
            element *= scalar;
        });
    });
    return lhs;
}

template <typename T, size_t R, size_t C>
Matrix<T, R, C> operator / (Matrix<T, R, C> lhs, double scalar) {
    std::for_each(lhs.begin(), lhs.end(), [scalar](auto& row) noexcept {
        std::for_each(row.begin(), row.end(), [scalar](auto& element) noexcept {
            element /= scalar;
        });
    });
    return lhs;
}
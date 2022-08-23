#pragma once

#include <initializer_list>
#include <array>
#include <iostream>
#include <algorithm>

#include "Vector.h"

template <size_t m, size_t n>
class Matrix : public std::array<std::array<double, n>, m> {
public:
    Matrix();

    Matrix(std::initializer_list<std::initializer_list<double>> list) noexcept {
        auto element_it = Matrix::begin();

        for (auto& row : list) {
            std::copy(row.begin(), row.end(), element_it->begin());
            ++element_it;
        }
    }

    void print() const {
        std::for_each(Matrix::begin(), Matrix::end(), [](auto& element) noexcept {
            std::for_each(element.begin(), element.end(), [](auto& value) noexcept {
                std::cout << value << " ";
            });

            std::cout << '\n';
        });
    }

    void transpose() noexcept {
        Matrix<m, n> matrix(std::move(Matrix::data));
        std::for_each(Matrix::begin(), Matrix::end(), [](auto& element) noexcept {
            std::for_each(element.begin(), element.end(), [](auto& value) noexcept {
                std::cout << value << " ";
            });

            std::cout << '\n';
        });
    }
};

template <size_t m, size_t n> 
Matrix<m, n> operator * (Matrix<m, n> lhs, double rhs) noexcept {
    Matrix<m, n> matrix(std::move(lhs));

    std::for_each(matrix.begin(), matrix.end(), [rhs](auto& element) noexcept {
        std::for_each(element.begin(), element.end(), [rhs](auto& value) noexcept {
            value *= rhs;
        });
    });

    return matrix;
}

template <size_t m, size_t n>
Matrix<m, n> operator / (Matrix<m, n> lhs, double rhs) noexcept {
    Matrix<m, n> matrix(std::move(lhs));

    std::for_each(matrix.begin(), matrix.end(), [rhs](auto& element) noexcept {
        std::for_each(element.begin(), element.end(), [rhs](auto& value) noexcept {
            value /= rhs;
        });
    });

    return matrix;
}

template<size_t m, size_t n>
Matrix<m, n> operator + (Matrix<m, n> lhs, double rhs) noexcept {
    Matrix<m, n> matrix(std::move(lhs));

    std::for_each(matrix.begin(), matrix.end(), [rhs](auto& element) noexcept {
        std::for_each(element.begin(), element.end(), [rhs](auto& value) noexcept {
            value += rhs;
        });
    });

    return matrix;
}

template<size_t m, size_t n>
Matrix<m, n> operator - (Matrix<m, n> lhs, double rhs) noexcept {
    Matrix<m, n> matrix(std::move(lhs));

    std::for_each(matrix.begin(), matrix.end(), [rhs](auto& element) noexcept {
        std::for_each(element.begin(), element.end(), [rhs](auto& value) noexcept {
            value -= rhs;
        });
    });

    return matrix;
}

template <size_t m, size_t n>
Matrix<m, n> operator + (Matrix<m, n> lhs, Matrix<m, n> rhs) noexcept {
    Matrix<m, n> matrix(std::move(lhs));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = lhs[i][j] + rhs[i][j];
        };
    };

    return matrix;
}

template <size_t m, size_t n>
Matrix<m, n> operator - (Matrix<m, n> lhs, Matrix<m, n> rhs) noexcept {
    Matrix<m, n> matrix(std::move(lhs));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = lhs[i][j] - rhs[i][j];
        };
    };

    return matrix;
}
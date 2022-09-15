#pragma once

#include <initializer_list>
#include <array>
#include <iostream>
#include <algorithm>
#include <../Core/LinearAlgebra/Matrix/matrices.hpp>

template <size_t M, size_t N, typename T>
class Matrix : public std::array<std::array<T, N>, M>{
public:
    Matrix();

    Matrix(std::initializer_list<std::initializer_list<T>> list) noexcept {
        auto element_it = Matrix::begin();

        for (auto& row : list) {
            std::copy(row.begin(), row.end(), element_it->begin());
            ++element_it;
        }
    }

    // template <typename T>
    Matrix(T val) {
        int i = 0, j = 0;
        std::for_each(Matrix::begin(), Matrix::end(), [&](auto& element) noexcept {
            i++;
            std::for_each(element.begin(), element.end(), [&](auto& value) noexcept {
                j++;
                if (i == j) {
                    value = val;
                } else {
                    value = 0.0f;
                }
            });
        });
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
        
    }

    void rotate() noexcept {

    }
};

template <size_t M, size_t N, typename T> 
Matrix<M, N, T> operator * (Matrix<M, N, T> lhs, double rhs) noexcept {
    Matrix<M, N, T> matrix(std::move(lhs));

    std::for_each(matrix.begin(), matrix.end(), [rhs](auto& element) noexcept {
        std::for_each(element.begin(), element.end(), [rhs](auto& value) noexcept {
            value *= rhs;
        });
    });

    return matrix;
}

template <size_t M, size_t N, typename T>
Matrix<M, N, T> operator / (Matrix<M, N, T> lhs, double rhs) noexcept {
    Matrix<M, N, T> matrix(std::move(lhs));

    std::for_each(matrix.begin(), matrix.end(), [rhs](auto& element) noexcept {
        std::for_each(element.begin(), element.end(), [rhs](auto& value) noexcept {
            value /= rhs;
        });
    });

    return matrix;
}

template<size_t M, size_t N, typename T>
Matrix<M, N, T> operator + (Matrix<M, N, T> lhs, double rhs) noexcept {
    Matrix<M, N, T> matrix(std::move(lhs));

    std::for_each(matrix.begin(), matrix.end(), [rhs](auto& element) noexcept {
        std::for_each(element.begin(), element.end(), [rhs](auto& value) noexcept {
            value += rhs;
        });
    });

    return matrix;
}

template<size_t M, size_t N, typename T>
Matrix<M, N, T> operator - (Matrix<M, N, T> lhs, double rhs) noexcept {
    Matrix<M, N, T> matrix(std::move(lhs));

    std::for_each(matrix.begin(), matrix.end(), [rhs](auto& element) noexcept {
        std::for_each(element.begin(), element.end(), [rhs](auto& value) noexcept {
            value -= rhs;
        });
    });

    return matrix;
}

template <size_t M, size_t N, typename T>
Matrix<M, N, T> operator + (Matrix<M, N, T> lhs, Matrix<M, N, T> rhs) noexcept {
    Matrix<M, N, T> matrix(std::move(lhs));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = lhs[i][j] + rhs[i][j];
        };
    };

    return matrix;
}

template <size_t M, size_t N, typename T>
Matrix<M, N, T> operator - (Matrix<M, N, T> lhs, Matrix<M, N, T> rhs) noexcept {
    Matrix<M, N, T> matrix(std::move(lhs));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = lhs[i][j] - rhs[i][j];
        };
    };

    return matrix;
}
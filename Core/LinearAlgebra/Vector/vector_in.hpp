#pragma once

#include <initializer_list>
#include <array>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <typeinfo>

#include "../Matrix/matrix_in.hpp"

template <typename T, size_t R>
class Vector : public std::array<T, R> {
    public:
        Vector() {
            std::for_each(Vector::begin(), Vector::end(), [](auto& element) noexcept {
                element = T{};
            });
        }
        Vector(std::initializer_list<T> list) {
            std::copy(list.begin(), list.end(), Vector::begin());
        }
        Vector(double num) {
            std::for_each(Vector::begin(), Vector::end(), [&](auto& element) noexcept {
                element = num;
            });
        }
        Vector(int num) {
            std::for_each(Vector::begin(), Vector::end(), [&](auto& element) noexcept {
                element = num;
            });
        }
        Vector(std::array<T, R> arr) {
            std::copy(arr.begin(), arr.end(), Vector::begin());
        }

        void print() const {
            std::for_each(Vector::begin(), Vector::end(), [](auto& element) noexcept {
                std::cout << element << " ";
            });

            std::cout << '\n';
        }
};

// -----------------------------
// Operator Overloads, VECTOR, SCALAR, VOID
// -----------------------------
template <typename T, size_t R>
Vector<T, R> operator + (Vector<T, R> lhs, double scalar) {
    std::for_each(lhs.begin(), lhs.end(), [scalar](auto& element) noexcept {
        element += scalar;
    });

    return lhs;
}

template <typename T, size_t R>
Vector<T, R> operator += (Vector<T, R> lhs, double scalar) {
    std::for_each(lhs.begin(), lhs.end(), [scalar](auto& element) noexcept {
        element += scalar;
    });

    return lhs;
}

template <typename T, size_t R>
Vector<T, R> operator - (Vector<T, R> lhs, double scalar) {
    std::for_each(lhs.begin(), lhs.end(), [scalar](auto& element) noexcept {
        element -= scalar;
    });

    return lhs;
}

template <typename T, size_t R>
Vector<T, R> operator -= (Vector<T, R> lhs, double scalar) {
    std::for_each(lhs.begin(), lhs.end(), [scalar](auto& element) noexcept {
        element -= scalar;
    });

    return lhs;
}

template <typename T, size_t R>
Vector<T, R> operator * (Vector<T, R> lhs, double scalar) {
    std::for_each(lhs.begin(), lhs.end(), [scalar](auto& element) noexcept {
        element *= scalar;
    });

    return lhs;
}

template <typename T, size_t R>
Vector<T, R> operator / (Vector<T, R> lhs, double scalar) {
    std::for_each(lhs.begin(), lhs.end(), [scalar](auto& element) noexcept {
        element /= scalar;
    });

    return lhs;
}

// -----------------------------
// Operator Overloads, VECTOR, VECTOR, VECTOR
// -----------------------------
template <typename T, size_t R>
Vector<T, R> operator + (Vector<T, R> lhs, Vector<T, R> rhs) {
    for (int i = 0; i < lhs.at(0) / lhs.size(); i++) {
        lhs.at(i) += rhs.at(i);
    }

    return lhs;
}
 
template <typename T, size_t R> 
Vector<T, R> operator += (Vector<T, R> lhs, Vector<T, R> rhs) {
    for (int i = 0; i < lhs.at(0) / lhs.size(); i++) {
        lhs.at(i) += rhs.at(i);
    }

    return lhs;
}

template <typename T, size_t R>
Vector<T, R> operator - (Vector<T, R> lhs, Vector<T, R> rhs) {
    for (int i = 0; i < lhs.at(0) / lhs.size(); i++) {
        lhs.at(i) -= rhs.at(i);
    } 

    return lhs;
}
 
template <typename T, size_t R>
Vector<T, R> operator -= (Vector<T, R> lhs, Vector<T, R> rhs) {
    for (int i = 0; i < lhs.at(0) / lhs.size(); i++) {
        lhs.at(i) -= rhs.at(i);
    } 

    return lhs;
}
 
template <typename T, size_t R>
Vector<T, R> operator * (Vector<T, R> lhs, Vector<T, R> rhs) {
    for (int i = 0; i < lhs.at(0) / lhs.size(); i++) {
        lhs.at(i) *= rhs.at(i);
    }

    return lhs;
}

template <typename T, size_t R>
Vector<T, R> operator / (Vector<T, R> lhs, Vector<T, R> rhs) {
    for (int i = 0; i < lhs.at(0) / lhs.size(); i++) {
        lhs.at(i) /= rhs.at(i);
    }

    return lhs;
}

// -----------------------------
// Operator Overloads, VECTOR, MATRIX, VECTOR
// -----------------------------
template <typename T, size_t C, size_t R>
Vector<T, R> operator * (Matrix<T, C, R> lhs, Vector<T, R> rhs) {
    Vector<T, R> newVec();
    // https://xaktly.com/MatrixOperations.html
    int i = 0, j, num = 0;
    std::for_each(lhs.begin(), lhs.end(), [&i, &rhs, &j, &lhs, &newVec](auto& row) noexcept {
        j = 0;
        std::for_each(row.begin(), row.end(), [&i, &rhs, &j, &lhs, &newVec](auto& element) noexcept {
            newVec[i] += (lhs[i][j] * rhs[j]);
            ++j;
        });
        ++i;
    });
    return rhs;
}

// -----------------------------
// Misc Functions
// -----------------------------
template <typename T, size_t R>
Vector<T, R> powerFunc(Vector<T, R> lhs, double scalar) {
    standardType(lhs);
    std::for_each(lhs.begin(), lhs.end(), [scalar](auto& element) noexcept {
        element = std::pow(element, scalar);
    });

    return lhs;
}

template <typename T, size_t R>
T magnitude(Vector<T, R> lhs) {
    T sum = {};
    if constexpr ((std::is_same<T, double>()) || (std::is_same<T, int>())) {
        for (int i = 0; i < lhs.at(0) / lhs.size(); i++) {
            sum += lhs.at(i);
        }
        return std::sqrt(sum);
    }

    return sum;
}

template <typename T, size_t R>
void standardType(Vector<T, R> lhs) {
    if (!(typeid(double) == typeid(lhs.at(0)))) {
        std::cout << typeid(int).name() << " " << typeid(double).name() << " " << typeid(lhs.at(0)).name() << '\n';
        throw std::invalid_argument("Vector must be of type int/double");
    }

    if (!(typeid(int) == typeid(lhs.at(0)))) {
        std::cout << typeid(int).name() << " " << typeid(double).name() << " " << typeid(lhs.at(0)).name() << '\n';
        throw std::invalid_argument("Vector must be of type int/double");
    }
}
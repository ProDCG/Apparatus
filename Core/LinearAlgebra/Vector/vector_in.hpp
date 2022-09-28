#pragma once

#include <initializer_list>
#include <array>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <typeinfo>

#include "../Matrix/matrix_in.hpp"

template <typename T, size_t C>
class Vector : public std::array<T, C> {
    public:
        Vector();
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
        Vector(std::array<T, C> arr) {
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
template <typename T, size_t C>
Vector<T, C> operator + (Vector<T, C> lhs, double scalar) {
    std::for_each(lhs.begin(), lhs.end(), [scalar](auto& element) noexcept {
        element += scalar;
    });

    return lhs;
}

template <typename T, size_t C>
Vector<T, C> operator += (Vector<T, C> lhs, double scalar) {
    std::for_each(lhs.begin(), lhs.end(), [scalar](auto& element) noexcept {
        element += scalar;
    });

    return lhs;
}

template <typename T, size_t C>
Vector<T, C> operator - (Vector<T, C> lhs, double scalar) {
    std::for_each(lhs.begin(), lhs.end(), [scalar](auto& element) noexcept {
        element -= scalar;
    });

    return lhs;
}

template <typename T, size_t C>
Vector<T, C> operator -= (Vector<T, C> lhs, double scalar) {
    std::for_each(lhs.begin(), lhs.end(), [scalar](auto& element) noexcept {
        element -= scalar;
    });

    return lhs;
}

template <typename T, size_t C>
Vector<T, C> operator * (Vector<T, C> lhs, double scalar) {
    std::for_each(lhs.begin(), lhs.end(), [scalar](auto& element) noexcept {
        element *= scalar;
    });

    return lhs;
}

template <typename T, size_t C>
Vector<T, C> operator / (Vector<T, C> lhs, double scalar) {
    std::for_each(lhs.begin(), lhs.end(), [scalar](auto& element) noexcept {
        element /= scalar;
    });

    return lhs;
}

// -----------------------------
// Operator Overloads, VECTOR, VECTOR, VECTOR
// -----------------------------
template <typename T, size_t C>
Vector<T, C> operator + (Vector<T, C> lhs, Vector<T, C> rhs) {
    for (int i = 0; i < lhs.at(0) / lhs.size(); i++) {
        lhs.at(i) += rhs.at(i);
    }

    return lhs;
}
 
template <typename T, size_t C> 
Vector<T, C> operator += (Vector<T, C> lhs, Vector<T, C> rhs) {
    for (int i = 0; i < lhs.at(0) / lhs.size(); i++) {
        lhs.at(i) += rhs.at(i);
    }

    return lhs;
}

template <typename T, size_t C>
Vector<T, C> operator - (Vector<T, C> lhs, Vector<T, C> rhs) {
    for (int i = 0; i < lhs.at(0) / lhs.size(); i++) {
        lhs.at(i) -= rhs.at(i);
    } 

    return lhs;
}
 
template <typename T, size_t C>
Vector<T, C> operator -= (Vector<T, C> lhs, Vector<T, C> rhs) {
    for (int i = 0; i < lhs.at(0) / lhs.size(); i++) {
        lhs.at(i) -= rhs.at(i);
    } 

    return lhs;
}
 
template <typename T, size_t C>
Vector<T, C> operator * (Vector<T, C> lhs, Vector<T, C> rhs) {
    for (int i = 0; i < lhs.at(0) / lhs.size(); i++) {
        lhs.at(i) *= rhs.at(i);
    }

    return lhs;
}

template <typename T, size_t C>
Vector<T, C> operator / (Vector<T, C> lhs, Vector<T, C> rhs) {
    for (int i = 0; i < lhs.at(0) / lhs.size(); i++) {
        lhs.at(i) /= rhs.at(i);
    }

    return lhs;
}

// -----------------------------
// Operator Overloads, VECTOR, MATRIX, VECTOR
// -----------------------------
template <typename T, size_t C, size_t R>
Vector<T, C> operator * (Matrix<T, C, R> lhs, Vector<T, C> rhs) {
    // int i = 0;
    // std::for_each(lhs.begin(), lhs.end(), [&i](auto& row) noexcept {
    //     int sum = 0;
    //     std::for_each(row.begin(), row.end(), [&j, &sum](auto& element) noexcept {
    //         sum += (element * rhs[i]);
    //     });
    //     rhs[i] = sum;
    //     i++;
    // });
    // return rhs;
    int i = 0;
    std::for_each(lhs.begin(), lhs.end(), [&i, &rhs](auto& row) noexcept {
        std::for_each(row.begin(), row.end(), [&i](auto& element) noexcept {
            std::cout << i << " "
            std::cout << rhs[i] << std::endl;
        });
        ++i;
    });
}

// -----------------------------
// Misc Functions
// -----------------------------
template <typename T, size_t C>
Vector<T, C> powerFunc(Vector<T, C> lhs, double scalar) {
    standardType(lhs);
    std::for_each(lhs.begin(), lhs.end(), [scalar](auto& element) noexcept {
        element = std::pow(element, scalar);
    });

    return lhs;
}

template <typename T, size_t C>
T magnitude(Vector<T, C> lhs) {
    T sum = {};
    if constexpr ((std::is_same<T, double>()) || (std::is_same<T, int>())) {
        for (int i = 0; i < lhs.at(0) / lhs.size(); i++) {
            sum += lhs.at(i);
        }
        return std::sqrt(sum);
    }

    return sum;
}

template <typename T, size_t C>
void standardType(Vector<T, C> lhs) {
    if (!(typeid(double) == typeid(lhs.at(0)))) {
        std::cout << typeid(int).name() << " " << typeid(double).name() << " " << typeid(lhs.at(0)).name() << '\n';
        throw std::invalid_argument("Vector must be of type int/double");
    }

    if (!(typeid(int) == typeid(lhs.at(0)))) {
        std::cout << typeid(int).name() << " " << typeid(double).name() << " " << typeid(lhs.at(0)).name() << '\n';
        throw std::invalid_argument("Vector must be of type int/double");
    }
}
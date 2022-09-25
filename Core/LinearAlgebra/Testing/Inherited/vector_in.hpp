#pragma once

#include <initializer_list>
#include <array>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <typeinfo>

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
    
}

template <typename T, size_t C>
Vector<T, C> operator - (Vector<T, C> lhs, double scalar) {
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
Vector<T, C> operator - (Vector<T, C> lhs, Vector<T, C> rhs) {
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
}
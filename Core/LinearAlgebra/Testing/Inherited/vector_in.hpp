#pragma once

#include <initializer_list>
#include <array>
#include <iostream>
#include <algorithm>

template <typename T, size_t C>
class Vector : public std::array<T, C> {
    public:
        Vector();
        Vector(std::initializer_list<T> list) {
            std::copy(list.begin(), list.end(), Vector::begin());
        }
        Vector(double);
        Vector(int);
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
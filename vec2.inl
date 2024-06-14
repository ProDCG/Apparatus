#include "vec2.hpp"

#include <iostream>
#include <cmath>

namespace app {

    // Constructors
    template <typename T>
    vec2<T>::vec2(T _x, T _y) : x(_x),  y(_y) {}

    template <typename T>
    vec2<T>::vec2(T val) : x(val), y(val) {}

    // Vector-Vector Operators
    template <typename T>
    vec2<T> vec2<T>::operator+(const vec2<T>& other) const {
        return vec2<T>(x + other.x, y + other.y);
    }

    template <typename T>
    vec2<T> vec2<T>::operator-(const vec2<T>& other) const {
        return vec2<T>(x - other.x, y - other.y);
    }

    template <typename T>
    vec2<T> vec2<T>::operator*(const vec2<T>& other) const {
        return vec2<T>(x * other.x, y * other.y);
    }

    template <typename T>
    vec2<T> vec2<T>::operator/(const vec2<T>& other) const {
        return vec2<T>(x / other.x, y / other.y);
    }

    // Vector-Scalar Operators
    template <typename T>
    vec2<T> vec2<T>::operator+(T scalar) const {
        return vec2<T>(x + scalar, y + scalar);
    }

    template<typename T>
    vec2<T> vec2<T>::operator-(T scalar) const {
        return vec2<T>(x - scalar, y - scalar);
    }

    template <typename T>
    vec2<T> vec2<T>::operator*(T scalar) const {
        return vec2<T>(x * scalar, y * scalar);
    }

    template <typename T>
    vec2<T> vec2<T>::operator/(T scalar) const {
        return vec2<T>(x / scalar, y / scalar);
    }

    // Properties
    template <typename T>
    T vec2<T>::magnitude() const {
        return std::sqrt(x * x + y * y);
    }

    template <typename T>
    vec2<T> vec2<T>::unit() const {
        return vec2<T>(x / magnitude(), y / magnitude());
    }

    // Other Vector Operations
    template <typename T>
    T vec2<T>::dot(const vec2<T>& other) const {
        return (x * other.x + y * other.y);
    }
}
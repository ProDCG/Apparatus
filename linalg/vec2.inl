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

    template <typename T>
    T vec2<T>::cross(const vec2<T>& other) const {
        return x * other.y - y * other.x;
    }

    template <typename T>
    T vec2<T>::angle(const vec2<T>& other) const {
        return std::acos(dot(other) / (magnitude() * other.magnitude()));
    }

    // TODO: finish projection and rejection, as well as print

    // Extraneous
    template <typename T>
    void vec2<T>::print() const {
        std::cout << '<' << x << ", " << y << ">\n";
    }
}
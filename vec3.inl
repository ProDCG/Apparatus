#include "vec3.hpp"

#include <iostream>
#include <cmath>

namespace app {

    // Constructors
    template <typename T>
    vec3<T>::vec3(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}

    template <typename T>
    vec3<T>::vec3(T val) : x(val), y(val), z(val) {}

    // Vector-Vector Operators
    template<typename T>
    vec3<T> vec3<T>::operator+(const vec3<T>& other) const {
        return vec3<T>(x + other.x, y + other.y, z + other.z);
    }

    template<typename T>
    vec3<T> vec3<T>::operator-(const vec3<T>& other) const {
        return vec3<T>(x - other.x, y - other.y, z - other.z);
    }

    template<typename T>
    vec3<T> vec3<T>::operator*(const vec3<T>& other) const {
        return vec3<T>(x * other.x, y * other.y, z * other.z);
    }

    template<typename T>
    vec3<T> vec3<T>::operator/(const vec3<T>& other) const {
        return vec3<T>(x / other.x, y / other.y, z / other.z);
    }

    // Vector-Scalar Operators
    template <typename T>
    vec3<T> vec3<T>::operator+(T scalar) const {
        return vec3<T>(x + scalar, y + scalar, z + scalar);
    }

    template <typename T>
    vec3<T> vec3<T>::operator-(T scalar) const {
        return vec3<T>(x - scalar, y - scalar, z - scalar);
    }

    template <typename T>
    vec3<T> vec3<T>::operator*(T scalar) const {
        return vec3<T>(x * scalar, y * scalar, z * scalar);
    }

    template <typename T>
    vec3<T> vec3<T>::operator/(T scalar) const {
        return vec3<T>(x / scalar, y / scalar, z / scalar);
    }

    // Properties
    template <typename T>
    T vec3<T>::magnitude() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    template <typename T>
    vec3<T> vec3<T>::unit() const {
        return vec3<T>(x / magnitude(), y / magnitude(), z / magnitude());
    }

    // Other Vector Operations
    template <typename T>
    T vec3<T>::dot(const vec3<T>& other) const {
        return (x * other.x + y * other.y + z * other.z);
    }

    template <typename T>
    vec3<T> vec3<T>::cross(const vec3<T>& other) const {
        return vec3<T>(
                y * other.z - z * other.y,
                z * other.x - x * other.z,
                x * other.y - y * other.x
        );
    }

    template <typename T>
    T vec3<T>::angle(const vec3<T>& other) const {
        return std::acos(dot(other) / (magnitude() * other.magnitude()));
    }

    template <typename T>
    vec3<T> vec3<T>::projection(const vec3<T>& other) const {
        return (dot(other) / other.magnitude()) * other;
    }

    template <typename T>
    vec3<T> vec3<T>::rejection(const vec3<T>& other) const {
        return other - projection(other);
    }

    // Extraneous
    template <typename T>
    void vec3<T>::print() const {
        std::cout << "<" << x << ", " << y << ", " << z << ">\n";
    }
}
#pragma once

namespace app {

    template <typename T>
    struct vec3 {
        T x, y, z;

        // Constructors
        explicit vec3(T _x, T _y, T _z);
        explicit vec3(T val);

        // Vector-Vector Operators
        vec3<T> operator+(const vec3<T>& other) const;
        vec3<T> operator-(const vec3<T>& other) const;
        vec3<T> operator*(const vec3<T>& other) const;
        vec3<T> operator/(const vec3<T>& other) const;

        // Vector-Scalar Operators
        vec3<T> operator+(T scalar) const;
        vec3<T> operator-(T scalar) const;
        vec3<T> operator*(T scalar) const;
        vec3<T> operator/(T scalar) const;

        // Properties
        vec3<T> unit() const;
        T magnitude() const;

        // Other Vector Operations
        T dot(const vec3<T>& other) const;
        vec3<T> cross(const vec3<T>& other) const;
        T angle(const vec3<T>& other) const;
        vec3<T> projection(const vec3<T>& other) const;
        vec3<T> rejection(const vec3<T>& other) const;

        // Extraneous
        void print() const;
    };
}

#include "vec3.inl"
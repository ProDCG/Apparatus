#pragma once

namespace app {

    template <typename T>
    struct vec2 {
        T x, y;

        // Constructors
        explicit vec2(T _x, T _y);
        explicit vec2(T val);

        // Vector-Vector Operators
        vec2<T> operator+(const vec2<T>& other) const;
        vec2<T> operator-(const vec2<T>& other) const;
        vec2<T> operator*(const vec2<T>& other) const;
        vec2<T> operator/(const vec2<T>& other) const;

        // Vector-Scalar Operators
        vec2<T> operator+(T scalar) const;
        vec2<T> operator-(T scalar) const;
        vec2<T> operator*(T scalar) const;
        vec2<T> operator/(T scalar) const;

        // Properties
        T magnitude() const;
        vec2<T> unit() const;

        // Other Vector Operations
        T dot(const vec2<T>& other) const;
        vec2<T> cross(const vec2<T>& other) const;
        T angle(const vec2<T>& other) const;
        vec2<T> projection(const vec2<T>& other) const;
        vec2<T> rejection(const vec2<T>& other) const;

        // Extraneous
        void print() const;

    };
}
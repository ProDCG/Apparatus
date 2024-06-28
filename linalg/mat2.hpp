#pragma once

namespace app {
    template <typename T>
    struct mat2 {
        T n11, n12,
          n21, n22;

        // operator overloads
        T operator+(const T& other);
        T operator-(const T& other);
        T operator*(const T& other);
        T operator/(const T& other);

        T operator+(const mat2<T>& other);
        T operator-(const mat2<T>& other);

        T det() const;
        T inverse() const;
    };
}

#include "mat2.inl"
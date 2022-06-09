#pragma once

#include <array>

#include "Matrix.h"

template <size_t m>
class Vector : public std::array<double, m> {
public:

    Vector();

    Vector(std::initializer_list<double> list) noexcept {
        
        std::copy(list.begin(), list.end(), Vector::begin());
    }

    void print() const {
        std::for_each(Vector::begin(), Vector::end(), [](auto& value) noexcept {
            std::cout << value << " ";
        });

        std::cout << '\n';
    }
};

template<size_t m>
Vector<m> operator * (Vector<m> lhs, double rhs) noexcept {
    Vector<m> vector(std::move(lhs));

    std::for_each(vector.begin(), vector.end(), [rhs](auto& value) noexcept {
        value *= rhs;
    });

    return vector;
}

template<size_t m>
Vector<m> operator / (Vector<m> lhs, double rhs) noexcept {
    Vector<m> vector(std::move(lhs));

    std::for_each(vector.begin(), vector.end(), [rhs](auto& value) noexcept {
        value /= rhs;
    });

    return vector;
}

template<size_t m>
Vector<m> operator + (Vector<m> lhs, Vector<m> rhs) noexcept {
    Vector<m> vector(std::move(lhs));

    for (int i = 0; i < m; i++) {
        vector[i] = lhs[i] + rhs[i];
    };

    return vector;
}

template<size_t m>
Vector<m> operator - (Vector<m> lhs, Vector<m> rhs) noexcept {
    Vector<m> vector(std::move(lhs));

    for (int i = 0; i < m; i++) {
        vector[i] = lhs[i] - rhs[i];
    };

    return vector;
}
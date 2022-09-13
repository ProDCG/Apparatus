#pragma once

#include <array>

template <size_t C, typename T>
class Vector : public std::array<double, m> {
public:

    Vector();

    template <typename T>
    Vector(T val) {
        at[0] = val;
    }

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

template<size_t C, typename T>
Vector<C, T> operator * (Vector<C, T> lhs, double rhs) noexcept {
    Vector<C, T> vector(std::move(lhs));

    std::for_each(vector.begin(), vector.end(), [rhs](auto& value) noexcept {
        value *= rhs;
    });

    return vector;
}

template<size_t C, typename T>
Vector<C, T> operator / (Vector<C, T> lhs, double rhs) noexcept {
    Vector<C, T> vector(std::move(lhs));

    std::for_each(vector.begin(), vector.end(), [rhs](auto& value) noexcept {
        value /= rhs;
    });

    return vector;
}

template<size_t C, typename T>
Vector<C, T> operator + (Vector<C, T> lhs, Vector<C, T> rhs) noexcept {
    Vector<C, T> vector(std::move(lhs));

    for (int i = 0; i < m; i++) {
        vector[i] = lhs[i] + rhs[i];
    };

    return vector;
}

template<size_t C, typename T>
Vector<C, T> operator - (Vector<C, T> lhs, Vector<C, T> rhs) noexcept {
    Vector<C, T> vector(std::move(lhs));

    for (int i = 0; i < m; i++) {
        vector[i] = lhs[i] - rhs[i];
    };

    return vector;
}
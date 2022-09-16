#pragma once

#include <array>

namespace app {
    template <typename T, size_t C, size_t R> class Matrix {
        private:
            
        public:
            std::array<std::array<T, C>, R> mat;
        
            Matrix(std::initializer_list<std::initializer_list<T>> list);
            virtual ~Matrix();

            Matrix<T, C, R> operator+(const Matrix<T, C, R>& rhs);
            Matrix<T, C, R> operator-(const Matrix<T, C, R>& rhs);
            Matrix<T, C, R> operator*(const Matrix<T, C, R>& rhs);

            Matrix<T, C, R> operator+(const T& rhs);
            Matrix<T, C, R> operator-(const T& rhs);
            Matrix<T, C, R> operator*(const T& rhs);
            Matrix<T, C, R> operator/(const T& rhs);

            Matrix<T, C, R> operator*(const Vector<T, R>& rhs);
            Matrix<T, C, R> operator/(const Vector<T, R>& rhs);
    };
}

#include <matrix2.inl>
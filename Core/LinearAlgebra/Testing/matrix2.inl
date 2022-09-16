#include <matrix2.hpp>
#include <vector2.hpp>

namespace app {

    // CONSTRUCTORS
    template <typename T, size_t C, size_t R>
    Matrix<T, C, R>::Matrix(std::initializer_list<std::initializer_list<T>> list) {
        auto element_it = mat.begin();

        for (auto& row : list) {
            std::copy(row.begin(), row.end(), element_it -> begin());
            ++element_it;
        }
    }

    template <typename T, size_t C, size_t R>
    Matrix<T, C, R>::~Matrix() {}

    // OPERATOR OVERLOADING - MATRICES
    template <typename T, size_t C, size_t R>
    Matrix<T, C, R> operator+(const Matrix<T, C, R>& rhs) {
        
    }
    template <typename T, size_t C, size_t R>
    Matrix<T, C, R> operator-(const Matrix<T, C, R>& rhs);
    template <typename T, size_t C, size_t R>
    Matrix<T, C, R> operator*(const Matrix<T, C, R>& rhs);

    // OPERATOR OVERLOADING - SCALARS
    template <typename T, size_t C, size_t R>
    Matrix<T, C, R> operator+(const T& rhs);
    template <typename T, size_t C, size_t R>
    Matrix<T, C, R> operator-(const T& rhs);
    template <typename T, size_t C, size_t R>
    Matrix<T, C, R> operator*(const T& rhs);
    template <typename T, size_t C, size_t R>
    Matrix<T, C, R> operator/(const T& rhs);

    // OPERATOR OVERLOADING - VECTORS
    template <typename T, size_t C, size_t R>
    Matrix<T, C, R> operator*(const Vector<T, R>& rhs);
    template <typename T, size_t C, size_t R>
    Matrix<T, C, R> operator/(const Vector<T, R>& rhs);
}
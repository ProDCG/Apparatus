#include <matrix2.hpp>

template <typename T, size_t C, size_t R>
Matrix<T, C, R>::Matrix(std::initializer_list<std::initializer_list<T>> list) {
    auto element_it = mat.begin();

    for (auto& row : list) {
        std::copy(row.begin(), row.end(), element_it -> begin());
        ++element_it;
    }
}

Matrix<T, C, R>::Matrix<T, C, R>() {

}

virtual ~Matrix();

template <typename T, size_t C, size_t R>
Matrix<T, C, R> operator+(const Matrix<T, C, R>& rhs) {
    std::for_each()
}

Matrix<T, C, R> operator-(const Matrix<T, C, R>& rhs);
Matrix<T, C, R> operator*(const Matrix<T, C, R>& rhs);

Matrix<T, C, R> operator+(const T& rhs);
Matrix<T, C, R> operator-(const T& rhs);
Matrix<T, C, R> operator*(const T& rhs);
Matrix<T, C, R> operator/(const T& rhs);

Matrix<T, C, R> operator*(const Vector<T, R>& rhs);
Matrix<T, C, R> operator/(const Vector<T, R>& rhs);



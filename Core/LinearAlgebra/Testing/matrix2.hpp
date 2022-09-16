#include <array>

namespace app {
    template <typename T, size_t C, size_t R>
    class Matrix {
        private:
            std::array<std::array<T, C>, R> mat;
        public:
            Matrix(std::initializer_list<std::initializer_list<T>> list) {
                auto element_it = mat.begin();

                for (auto& row : list) {
                    std::copy(row.begin(), row.end(), element_it -> begin());
                    ++element_it;
                }
            }

            Matrix();

            Matrix<T, C, R> operator+(const Matrix<T, C, R>& rhs);
    };
}
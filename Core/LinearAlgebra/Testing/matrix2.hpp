#include <vector>

namespace app {
    template <typename T, size_t C, size_t R>
    class Matrix {
        private:
            std::array<std::array<T, C> R> mat;
    }
}
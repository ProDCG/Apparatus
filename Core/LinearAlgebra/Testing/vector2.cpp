#include "../Core/LinearAlgebra/Testing/vector2.hpp"

template <typename T, size_t C>
app::Vector<T, C> app::operator+(const T& rhs) {
    std::for_each(vec.begin(), vec.end(), [rhs](auto& element) noexcept {
        element += rhs;
    });
}
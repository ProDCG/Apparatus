#include "../Core/LinearAlgebra/Testing/vector2.hpp"

template <typename T, size_t C>
app::Vector<T, C>::Vector(std::initializer_list<T> list) {
    std::copy(list.begin(), list.end(), app::Vector<T, C>::vec);
}

template <typename T, size_t C>
app::Vector<T, C> app::operator+(const T& rhs) {
    std::for_each(vec.begin(), vec.end(), [rhs](auto& element) noexcept {
        element += rhs;
    });
}

template <typename T, size_t C>
app::Vector<T, C> app::operator+=(Vector<T, C> lhs, const T& rhs) {
    std::for_each(vec.begin(), vec.end(), [rhs](auto& element) noexcept {
        element += rhs;
    });
}
#include "../Core/LinearAlgebra/Testing/vector2.hpp"

template <typename T, size_t C>
app::Vector<T, C>::Vector(std::initializer_list<T> list) {
    std::copy(list.begin(), list.end(), app::Vector<T, C>::vec);
}

template <typename T, size_t C>
app::Vector<T, C>::Vector(std::array<T, C> arr) {
    app::Vector<T, C>::vec = arr;
}

// template <typename T, size_t C>
// app::Vector<T, C> app::operator+(const T& rhs) {
//     std::for_each(vec.begin(), vec.end(), [rhs](auto& element) noexcept {
//         element += rhs;
//     });
// }

// template <typename T, size_t C>
// void app::operator+=(Vector<T, C> lhs, const T& rhs) {
//     std::for_each(vec.begin(), vec.end(), [rhs](auto& element) noexcept {
//         element += rhs;
//     });
// }

template <typename T, size_t C>
app::Vector<T, C> operator+(app::Vector<T, C> rhs) {
    app::Vector<T, C> newVec;

    for (int i = 0; i < lhs.vec.size(); i++) {
        newVec.vec.at(i) = lhs.vec.at(i) + rhs.vec.at(i);
    }

    return newVec;
}

template <typename T, size_t C>
app::Vector<T, C> operator+=(app::Vector<T, C> lhs, app::Vector<T, C> rhs) {
    // to be implemented
}
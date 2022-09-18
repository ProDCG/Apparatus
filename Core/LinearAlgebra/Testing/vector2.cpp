#include "vector2.hpp"

template <typename T, size_t C>
app::Vector<T, C>::Vector(std::initializer_list<T> list) {
    std::copy(list.begin(), list.end(), app::Vector<T, C>::vec);
}

template <typename T, size_t C>
app::Vector<T, C>::Vector(std::array<T, C> arr) {
    app::Vector<T, C>::vec = arr;
}

template <typename T, size_t C>
app::Vector<T, C>::Vector(T& val) {
    std::for_each(app::Vector<T, C>::vec.begin(), app::Vector<T, C>::vec.end(), [&](auto& value) noexcept {
        value = val;
    }) 
}

template <typename T, size_t C>
app::Vector<T, C> app::Vector<T, C>::operator+(const T& rhs) {
    app::Vector<T, C> newVec(0.0f);

    for (int i = 0; i < newVec.vec.size(); i++) {
        newVec[i] += rhs;
    }

    return newVec;
}

template <typename T, size_t C>
std::array<T, C> app::Vector<T, C>::getVec() {
    return this->vec;
}
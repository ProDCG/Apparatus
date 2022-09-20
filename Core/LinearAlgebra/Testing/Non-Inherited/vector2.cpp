#include "vector2.hpp"

// ----------------
// CONSTRUCTORS
// ----------------
template <typename T, size_t C>
app::Vector<T, C>::Vector(std::initializer_list<T> list) {
    std::copy(list.begin(), list.end(), app::Vector<T, C>::vec.begin());
}

template <typename T, size_t C>
app::Vector<T, C>::Vector(std::array<T, C> arr) {
    app::Vector<T, C>::vec = arr;
}

template <typename T, size_t C>
app::Vector<T, C>::Vector(const T& val) {
    std::for_each(app::Vector<T, C>::vec.begin(), app::Vector<T, C>::vec.end(), [&](auto& value) noexcept {
        value = val;
    });
}

template <typename T, size_t C>
app::Vector<T, C>::Vector() {
    T t = {};
    std::for_each(app::Vector<T, C>::vec.begin(), app::Vector<T, C>::vec.end(), [&](auto& value) noexcept {
        value = t;
    });
}

template <typename T, size_t C>
app::Vector<T, C>::~Vector() {}

// ----------------
// OPERATOR OVERLOADS, SCALAR
// ----------------
template <typename T, size_t C>
void app::Vector<T, C>::operator+(const T& rhs) {
    std::for_each(app::Vector<T, C>::vec.begin(), app::Vector<T, C>::vec.end(), [&](auto& value) noexcept {
        value += rhs;
    });
}

template <typename T, size_t C>
void app::Vector<T, C>::operator-(const T& rhs) {
    std::for_each(app::Vector<T, C>::vec.begin(), app::Vector<T, C>::vec.end(), [&](auto& value) noexcept {
        value -= rhs;
    });
}

template <typename T, size_t C>
void app::Vector<T, C>::operator*(const T& rhs) {
    std::for_each(app::Vector<T, C>::vec.begin(), app::Vector<T, C>::vec.end(), [&](auto& value) noexcept {
        value *= rhs;
    });
}

template <typename T, size_t C>
void app::Vector<T, C>::operator/(const T& rhs) {
    std::for_each(app::Vector<T, C>::vec.begin(), app::Vector<T, C>::vec.end(), [&](auto& value) noexcept {
        value /= rhs;
    });
}

// ----------------
// OPERATOR OVERLOADS, VECTOR
// ----------------

// want to pass a vector as a param, so basically vec3 + vec2, where it adds the values to vec3
// or where i can do some_vec = vec3 + vec2
// and thats about it and code no worky
template <typename T, size_t C>
app::Vector<T, C> app::Vector<T, C>::operator+(app::Vector<T, C>& rhs) {
    app::Vector<T, C> arr;
    
    for (int i = 0; i < std::size(); i++) {
        arr[i] = (*this)[i] + rhs.vec[i];
    }

    return arr
}

// ----------------
// MISC FUNCTIONS
// ----------------
template <typename T, size_t C>
void app::Vector<T, C>::print() {
    std::for_each(app::Vector<T, C>::vec.begin(), app::Vector<T, C>::vec.end(), [&](auto& value) noexcept {
        std::cout << value << ' ';
    });
    std::cout << '\n';
}

template <typename T, size_t C>
std::array<T, C> app::Vector<T, C>::getVec() {
    return this->vec;
}
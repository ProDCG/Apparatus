#include "vector_in.hpp"

template <typename T, size_t C>
Vector<T, C>::Vector() {
    std::for_each(Vector.begin(), Vector.end(), [&](auto &element) {
        value = T;
    });
}
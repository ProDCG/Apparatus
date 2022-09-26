#pragma once

template <typename T, size_t C, size_t R>
class Matrix : public std::array<std::array<T, C>, R> {
    public:
        Matrix();

        Matrix(std::initializer_list<std::initializer_list<T>> list) {

        }

};
#pragma once

#include <array>
#include <algorithm>

namespace app {
    template <typename T, size_t C> class Vector{
        private:
            
        public:
            std::array<T, C> vec;

            Vector(std::initializer_list<T> list);
            virtual ~Vector();

            Vector<T, C> operator+(const T& rhs) {
                std::for_each(vec.begin(), vec.end(), [rhs](auto& element) noexcept {
                    element += rhs;
                })
            }
    };
}

#include <../Core/LinearAlgebra/Testing/vector2.cpp>
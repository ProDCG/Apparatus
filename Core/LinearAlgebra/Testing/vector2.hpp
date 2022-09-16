#pragma once

#include <array>
#include <algorithm>

namespace app {
    template <typename T, size_t C> class Vector{
        private:
            // std::array<T, C> vec;
            Vector<T, C> operator+(Vector<T, C> lhs, Vector<T, C> rhs);
            Vector<T, C> operator+=(Vector<T, C> rhs);
            
        public:
            std::array<T, C> vec;
            Vector(std::initializer_list<T> list);
            Vector(Vector<T, C> vec);
            Vector(T& num);
            virtual ~Vector();
    };
}
#pragma once

#include <array>
#include <algorithm>
#include <initializer_list>

namespace app {
    template <typename T, size_t C> class Vector{
        private:
            // std::array<T, C> vec;
            std::array<T, C> vec;
            
        public:
            
            Vector(std::initializer_list<T> list);
            Vector(std::array<T, C> arr);
            Vector(const T& num);
            Vector();
            virtual ~Vector();

            void operator+(const T& rhs);

            std::array<T, C> getVec();
    };
}

#include "vector2.cpp"
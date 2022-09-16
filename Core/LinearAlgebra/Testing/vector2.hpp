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
    };
}

#include <../Core/LinearAlgebra/Testing/vector2.cpp>
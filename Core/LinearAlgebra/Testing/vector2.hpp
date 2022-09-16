#pragma once

#include <array>

namespace app {
    template <typename T, size_t C>
    class Vector{
        private:
            std::array<T, C> vec;
        public:
            Vector();
            virtual ~Vector();
    };
}

#include <../Core/LinearAlgebra/Testing/vector2.cpp>
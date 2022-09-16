#pragma once

#include <array>
#include <algorithm>

namespace app {
    template <typename T, size_t C> class Vector{
        private:
            // std::array<T, C> vec;
            Vector<T, C> operator+(Vector<T, C> lhs, Vector<T, C> rhs);
            
        public:
            std::array<T, C> vec;
            Vector(std::initializer_list<T> list);
            virtual ~Vector();
    };

    // template <typename T, size_t C>
    // Vector<T, C> operator+(const T& rhs);
    // template <typename T, size_t C>
    // void operator+=(Vector<T, C> lhs, const T& rhs);

    template <typename T, size_t C>
    
}
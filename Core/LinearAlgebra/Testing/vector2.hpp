#pragma once

#include <array>
#include <algorithm>

namespace app {
    template <typename T, size_t C> class Vector{
        private:
            std::array<T, C> vec;
        public:
            

            Vector(std::initializer_list<T> list);
            virtual ~Vector();

            
    };

    template <typename T, size_t C>
    Vector<T, C> operator+(const T& rhs) {
        std::for_each(vec.begin(), vec.end(), [rhs](auto& element) noexcept {
            element += rhs;
        });
    }
}
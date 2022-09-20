#pragma once

#include <array>
#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <string>
 
namespace app {
    template <typename T, size_t C> class Vector{
        private:
            std::array<T, C> vec;
            
        public:
            
            Vector(std::initializer_list<T> list);
            Vector(std::array<T, C> arr);
            Vector(const T& num);
            Vector();
            virtual ~Vector();

            void operator+(const T& rhs);
            void operator-(const T& rhs);
            void operator*(const T& rhs);
            void operator/(const T& rhs);

            Vector<T, C> operator+(Vector<T, C> lhs, Vector<T, C> rhs) {
                Vector<T, C> vector(std::move(lhs));

                for (int i = 0; i < c; i++) {
                    vector[i] = lhs::vec[i] + rhs::vec[i];
                }
            }
            // app::Vector<T, C> operator-(app::Vector<T, C> lhs, app::Vector<T, C> rhs);
            // app::Vector<T, C> operator*(app::Vector<T, C> lhs, app::Vector<T, C> rhs);
            // app::Vector<T, C> operator/(app::Vector<T, C> lhs, app::Vector<T, C> rhs);
            
            void operator+(app::Vector<T, C> rhs);
            void operator-(app::Vector<T, C> vec);
            void operator*(app::Vector<T, C> vec);
            app::Vector<T, C> operator/(const app::Vector<T, C> rhs);

            void print();
            std::array<T, C> getVec();
    };
}

#include "vector2.cpp"
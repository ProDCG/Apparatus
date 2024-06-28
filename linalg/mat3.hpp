#pragma once

namespace app {

    template <typename T>
    struct mat3 {
        T n11, n12, n13,
          n21, n22, n23,
          n31, n32, n33;

        explicit mat3(T _n11, T n12, T n13,
                      T _n21, T _n22, T _n23,
                      T _n31, T _n32, T _n33);
        explicit mat3(T val);
        explicit mat3();

        T det() const;
    };
}

#include "mat3.inl"
#pragma once

#include "../Vector/vec3.h"
#include <cmath>
#include <algorithm>
#include <iostream>

namespace app {
    class mat3 {
        public:
            float n00, n01, n02,
                    n10, n11, n12,
                    n20, n21, n22;

                mat3() {}
                mat3(float n00, float n01, float n02, float n10, float n11, float n12, float n20, float n21, float n22);
                mat3(const vec3 &v1, const vec3 &v2, const vec3 &v3);

                // Operator Overloads
                mat3 operator * (float scalar) const;
                mat3 operator *= (float scalar);
                mat3 operator / (float scalar) const;
                mat3 operator /= (float scalar);
                mat3 operator - () const;

                // Other methods
                void set (const mat3 &other);
                void print() const;
    };
}
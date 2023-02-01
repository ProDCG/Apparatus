#pragma once

#include "vec4.h"
#include <cmath>
#include <algorithm>

namespace app {
    class mat4 {
        public:
            float n00, n01, n02, n03,
                    n10, n11, n12, n13,
                    n20, n21, n22, n23,
                    n30, n31, n32, n33;

            mat4() {}
            mat4(float n00, float n01, float n02, float n03, float n10, float n11, float n12, float n13, float n20, float n21, float n22, float n23, float n30, float n31, float n32, float n33);
            mat4(const vec4 &v1, const vec4 &v2, const vec4 &v3, const vec4 &v4);

            // Operator Overloads
            mat4 operator * (float scalar) const;
            mat4 operator *= (float scalar);
            mat4 operator * (mat4 other) const;
            mat4 operator *= (mat4 other);
            mat4 operator / (float scalar) const;
            mat4 operator /= (float scalar);
            mat4 operator - () const;

            // Other methods
            void set (const mat4 &other);
    };
}
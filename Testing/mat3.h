#pragma once

#include "vec3.h"
#include <cmath>
#include <algorithm>

namespace app {
    class mat3 {
        public:
            float x1, y1, z1,
                  x2, y2, z2,
                  x3, y3, z3;

                mat3() {}
                mat3(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);
                mat3(const vec3 &v1, const vec3 &v2, const vec3 &v3);

                // Operator Overloads
                mat3 operator * (float scalar) const;
                mat3 operator / (float scalar) const;
                mat3 operator - () const;

                // Other methods
                void set (const mat3 &other);
    };
}
#pragma once

#include <cmath>
#include <algorithm>

namespace app {
    class vec4 {
        public:
            float n0;
            float n1;
            float n2;
            float n3;

            vec4() {}

            vec4(float n0, float n1, float n2, float n3);

            vec4(const vec4 &rhs);

            explicit vec4(float scalar);

            // Operator Overloads
            vec4 operator + (const vec4 &rhs) const;
            vec4 operator - (const vec4 &rhs) const;
            vec4 operator - () const;

            vec4 operator * (float scalar) const;
            vec4 operator / (float scalar) const;

            vec4 &operator = (const vec4 &rhs);
    };
}
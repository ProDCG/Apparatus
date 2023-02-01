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
            vec4 &operator += (const vec4 &rhs);
            vec4 &operator -= (const vec4 &rhs);
            vec4 &operator *= (float scalar);
            vec4 &operator /= (float scalar);

            // Other methods
            void set (const vec4 &other);

            bool isFinite() const;
            bool isPerpindicular (const vec4 &other) const;
            bool isZero() const;

            float dot(const vec4 &other) const;
            vec4 cross(const vec4 &other);
            float length() const;
            float lengthSq() const;

            vec4 clampLength(float maxLength) const;
            vec4 clampLength(float minLength, float maxLength) const;

            float sum() const;
            float product() const;
            float average() const;
            float min() const;
            float max() const;

            vec4 abs() const;
            vec4 neg() const;
            vec4 recip() const;
    };
}
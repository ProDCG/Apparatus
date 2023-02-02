#pragma once

#include <cmath>
#include <algorithm>

namespace app {
    class vec3 {
        public:
            float n0, n1, n2;

            vec3() {}

            vec3(float n0, float n1, float n2);

            vec3(const vec3 &rhs);

            explicit vec3(float scalar);

            // Operator Overloads
            vec3 operator + (const vec3 &rhs) const;
            vec3 operator - (const vec3 &rhs) const;
            vec3 operator - () const;

            vec3 operator * (float scalar) const;
            vec3 operator / (float scalar) const;

            vec3 &operator = (const vec3 &rhs);
            vec3 &operator += (const vec3 &rhs);
            vec3 &operator -= (const vec3 &rhs);
            vec3 &operator *= (float scalar);
            vec3 &operator /= (float scalar);

            // Other methods
            void set(const vec3 &other);
            void print() const;

            bool isFinite() const;
            bool isPerpindicular(const vec3 &other) const;
            bool isZero() const;

            float dot(const vec3 &other) const;
            vec3 cross(const vec3 &other) const;
            float length() const;
            float lengthSq() const;

            vec3 clampLength(float maxLength) const;
            vec3 clampLength(float minLength, float maxLength) const;

            float sum() const;
            float product() const;
            float average() const;
            float min() const;
            float max() const;

            vec3 abs() const;
            vec3 neg() const;
            vec3 recip() const;
    }; 
}
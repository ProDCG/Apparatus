#pragma once

namespace app {
    class vec3 {
        public:
            float x;
            float y;
            float z;

            vec3() {}

            vec3(float x, float y, float z);

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

            bool isFinite() const;
            bool isPerpindicular(const vec3 &other) const;
            bool isZero() const;

            float dot(const vec3 &other) const;
            float lengthSq() const;

            float clampLength(float maxLength) const;
            float clampLength(float minLength, float maxLength) const;
    }; 
}
#pragma once

namespace app {
    class vector3 {
        public:
            float x;
            float y;
            float z;

            vector3() {}

            vector3(float x, float y, float z);

            vector3(const vector3 &rhs);

            explicit vector3(float scalar);

            // Operator Overloads

            vector3 operator + (const vector3 &rhs) const;
            vector3 operator - (const vector3 &rhs) const;
            vector3 operator / (const vector3 &rhs) const;
            vector3 operator * (const vector3 &rhs) const;

            vector3 operator = (const vector3 &rhs) const;
            vector3 operator += (const vector3 &rhs) const;
            vector3 operator -= (const vector3 &rhs) const;
            vector3 operator *= (const vector3 &rhs) const;
            vector3 operator /= (const vector3 &rhs) const;

            // Other methods
            void set(const vector3 &other);

            bool isFinite() const;
            bool isPerpindicular(const vector3 &other) const;

            float dot(const vector3 &other) const;
    }; 
}
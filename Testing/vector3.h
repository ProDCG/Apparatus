#pragma once

namespace app {
    class vector_3 {
        public:
            float x;
            float y;
            float z;

            vector_3() {}

            vector_3(float x, float y, float z);

            vector_3(const vector_3 &rhs);

            explicit vector_3(float scalar);

            // Operator Overloads

            vector_3 operator + (const vector_3 &rhs) const;
            vector_3 operator - (const vector_3 &rhs) const;
            vector_3 operator / (const vector_3 &rhs) const;
            vector_3 operator * (const vector_3 &rhs) const;

            vector_3 operator = (const vector_3 &rhs) const;
            vector_3 operator += (const vector_3 &rhs) const;
            vector_3 operator -= (const vector_3 &rhs) const;
            vector_3 operator *= (const vector_3 &rhs) const;
            vector_3 operator /= (const vector_3 &rhs) const;

            // Other methods
            void setIdentity();
            void set(const vector_3 &other);

            bool isFinite() const;
            bool isPerpindicular(const vector_3 &other) const;
    }; 
}
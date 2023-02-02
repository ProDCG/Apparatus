#include "mat3.h"

using namespace app;

mat3::mat3(float n00, float n01, float n02, float n10, float n11, float n12, float n20, float n21, float n22)
:n00(n00), n01(n01), n02(n02), n10(n10), n11(n11), n12(n12), n20(n20), n21(n21), n22(n22) {}

mat3::mat3(const vec3 &v1, const vec3 &v2, const vec3 &v3)
:n00(v1.n0), n01(v1.n1), n02(v1.n2), n10(v2.n0), n11(v2.n1), n12(v2.n2), n20(v3.n0), n21(v3.n1), n22(v3.n2) {}

mat3 mat3::operator * (float scalar) const {
    mat3 cur = *this;
    cur *= scalar;
    return cur;
}

mat3 mat3::operator / (float scalar) const {
    mat3 cur = *this;
    cur /= scalar;
    return cur;
}

mat3 mat3::operator *= (float scalar) {
    n00 *= scalar;
    n01 *= scalar;
    n02 *= scalar;
    n10 *= scalar;
    n11 *= scalar;
    n12 *= scalar;
    n20 *= scalar;
    n21 *= scalar;
    n22 *= scalar;
    return *this;
}

mat3 mat3::operator /= (float scalar) {
    n00 /= scalar;
    n01 /= scalar;
    n02 /= scalar;
    n10 /= scalar;
    n11 /= scalar;
    n12 /= scalar;
    n20 /= scalar;
    n21 /= scalar;
    n22 /= scalar;
    return *this;
}

mat3 mat3::operator - () const {
    mat3 cur = *this;
    cur *= -1;
    return cur;
}

void mat3::set(const mat3 &other) {
    n00 = other.n00;
    n01 = other.n01;
    n02 = other.n02;
    n10 = other.n10;
    n11 = other.n11;
    n22 = other.n22;
    n20 = other.n20;
    n21 = other.n21;
    n22 = other.n22;
}
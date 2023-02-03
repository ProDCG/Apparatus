#include "vec3.h"

using namespace app;

vec3::vec3(float n0, float n1, float n2)
:n0(n0), n1(n1), n2(n2) {}
vec3::vec3(const vec3 &rhs)
:n0(rhs.n0), n1(rhs.n1), n2(rhs.n2) {}

vec3::vec3(float scalar)
:n0(scalar), n1(scalar), n2(scalar) {}

// ------------------------------------------------
// Operator Overloads
vec3 vec3::operator + (const vec3 &rhs) const {
    return vec3(n0 + rhs.n0, n1 + rhs.n1, n2 + rhs.n2);
}

vec3 vec3::operator - (const vec3 &rhs) const {
    return vec3(n0 - rhs.n0, n1 - rhs.n1, n2 - rhs.n2);
}

vec3 vec3::operator - () const {
    return vec3(-n0, -n1, -n2);
}


vec3 vec3::operator * (float scalar) const {
    return vec3(n0*scalar, n1*scalar, n2*scalar);
}

vec3 vec3::operator / (float scalar) const {
    return vec3(n0/scalar, n1/scalar, n2/scalar);
}

vec3 &vec3::operator = (const vec3 &rhs) {
    n0 = rhs.n0;
    n1 = rhs.n1;
    n2 = rhs.n2;
    return *this;
}

vec3 &vec3::operator += (const vec3 &rhs) {
    n0 += rhs.n0;
    n1 += rhs.n1;
    n2 += rhs.n2;
    return *this;
}

vec3 &vec3::operator -= (const vec3 &rhs) {
    n0 -= rhs.n0;
    n1 -= rhs.n1;
    n2 -= rhs.n2;
    return *this;
}

vec3 &vec3::operator *= (float scalar) {
    n0 *= scalar;
    n1 *= scalar;
    n2 *= scalar;
    return *this;
}

void vec3::set(const vec3 &other) {
    n0 = other.n0;
    n1 = other.n1;
    n2 = other.n2;
}

void vec3::print() const {
    printf("⟨%f, %f, %f⟩\n", n0, n1, n2);
}

bool vec3::isFinite() const {
    return std::isfinite(n0) && std::isfinite(n1) && std::isfinite(n2);
}

bool vec3::isPerpindicular(const vec3 &other) const {
    return dot(other) == 0;
}

bool vec3::isZero() const {
    return lengthSq() <= 1e-7f;
}

float vec3::dot(const vec3 &other) const {
    return n0 * other.n0 + n1 * other.n1 + n2 * other.n2;
}

float vec3::length() const {
    return std::sqrt(lengthSq());
}

float vec3::lengthSq() const {
    return n0*n0 + n1*n1 + n2*n2;
}

vec3 vec3::clampLength(float maxLength) const {
    float lenSq = lengthSq();
    if (lenSq > maxLength*maxLength) {
        return *this * (maxLength / std::sqrt(lenSq));
    } else {
        return *this;
    }
}

vec3 vec3::clampLength(float minLength, float maxLength) const {
    float lenSq = lengthSq();
    if (lenSq > maxLength*maxLength)
        return *this * (maxLength / std::sqrt(lenSq));
    else if (lenSq < minLength*minLength)
        return *this * (minLength / std::sqrt(lenSq));
    else
        return *this;
}

float vec3::sum() const {
    return n0 + n1 + n2;
}

float vec3::product() const {
    return n0 * n1 * n2;
}

float vec3::average() const {
    return (n0 + n1 + n2) / 3;
}

float vec3::min() const {
    return std::min(n0, std::min(n1, n2));
}

float vec3::max() const {
    return std::max(n0, std::max(n1, n2));
}

vec3 vec3::abs() const {
    return vec3(std::abs(n0), std::abs(n1), std::abs(n2));
}

vec3 vec3::neg() const {
    return vec3(-n0, -n1, -n2);
}

vec3 vec3::recip() const {
    return vec3(1/n0, 1/n1, 1/n2);
}
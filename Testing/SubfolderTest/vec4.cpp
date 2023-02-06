#include "vec4.h"

using namespace app;

vec4::vec4(float n0, float n1, float n2, float n3)
:n0(n0), n1(n1), n2(n2), n3(n3) {}

vec4::vec4(const vec4 &rhs)
:n0(rhs.n0), n1(rhs.n1), n2(rhs.n2), n3(rhs.n3) {}

vec4::vec4(float scalar)
:n0(scalar), n1(scalar), n2(scalar), n3(scalar) {}

// Operator Overalods
vec4 vec4::operator + (const vec4 &rhs) const {
    return vec4(n0 + rhs.n0, n1 + rhs.n1, n2 + rhs.n2, n3 + rhs.n3);
}

vec4 vec4::operator - (const vec4 &rhs) const {
    return vec4(n0  - rhs.n0, n1 - rhs.n1, n2 - rhs.n2, n3 - rhs.n3);
}

vec4 vec4::operator - () const {
    return vec4(-n0, -n1, -n2, -n3);
}

vec4 vec4::operator * (float scalar) const {
    return vec4(n0 * scalar, n1 * scalar, n2 * scalar, n3 * scalar);
}

vec4 vec4::operator / (float scalar) const {
    return vec4(n0 / scalar, n1 / scalar, n2 / scalar, n3 / scalar);
}

vec4 &vec4::operator = (const vec4 &rhs) {
    n0 = rhs.n0;
    n1 = rhs.n1;
    n2 = rhs.n2;
    n3 = rhs.n3;
    return *this;
}

vec4 &vec4::operator += (const vec4 &rhs) {
    n0 += rhs.n0;
    n1 += rhs.n1;
    n2 += rhs.n2;
    n3 += rhs.n3;
    return *this;
}

vec4 &vec4::operator -= (const vec4 &rhs) {
    n0 -= rhs.n0;
    n1 -= rhs.n1;
    n2 -= rhs.n2;
    n3 -= rhs.n3;
    return *this;
}

vec4 &vec4::operator *= (float scalar) {
    n0 *= scalar;
    n1 *= scalar;
    n2 *= scalar;
    n3 *= scalar;
    return *this;
}

void vec4::set(const vec4 &other) {
    n0 = other.n0;
    n1 = other.n1;
    n2 = other.n2;
    n3 = other.n3;
}

void vec4::print() const {
    printf("%f, %f, %f, %f\n", n0, n1, n2, n3);
}

bool vec4::isFinite() const {
    return std::isfinite(n0) && std::isfinite(n1) && std::isfinite(n2) && std::isfinite(n3);
}

bool vec4::isPerpindicular(const vec4 &other) const {
    return dot(other) == 0;
}

bool vec4::isZero() const {
    return lengthSq() <= 1e-7f;
}

float vec4::dot(const vec4 &other) const {
    return n0 * other.n0 + n1 * other.n1 + n2 * other.n2 + n3 * other.n3;
}

float vec4::length() const {
    return std::sqrt(lengthSq());
}

float vec4::lengthSq() const {
    return n0*n0 + n1*n1 + n2*n2 + n3*n3;
}

vec4 vec4::clampLength(float maxLength) const {
    float lenSq = lengthSq();
    if (lenSq > maxLength * maxLength) {
        return *this * (maxLength / std::sqrt(lenSq));
    } else {
        return *this;
    }
}

vec4 vec4::clampLength(float minLength, float maxLength) const {
    float lenSq = lengthSq();
    if (lenSq > maxLength * maxLength)
        return *this * (maxLength / std::sqrt(lenSq));
    else if (lenSq < minLength * minLength)
        return *this * (minLength / std::sqrt(lenSq));
    else
        return *this;
}

float vec4::sum() const {
    return n0 + n1 + n2 + n3;
}

float vec4::product() const {
    return n0 * n1 * n2;
}

float vec4::average() const {
    return (n0 + n1 + n2 + n3) / 4;
}

float vec4::min() const {
    return std::min(n0, std::min(n1, std::min(n2, n3)));
}

float vec4::max() const {
    return std::max(n0, std::max(n1, std::max(n2, n3)));
}

vec4 vec4::abs() const {
    return vec4(std::abs(n0), std::abs(n1), std::abs(n2), std::abs(n3));
}

vec4 vec4::neg() const {
    return vec4(-n0, -n1, -n2, -n3);
}

vec4 vec4::recip() const {
    return vec4(1/n0, 1/n1, 1/n2, 1/n3);
}
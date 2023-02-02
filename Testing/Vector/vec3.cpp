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
    return vec3(x + rhs.x, y + rhs.y, z + rhs.z);
}

vec3 vec3::operator - (const vec3 &rhs) const {
    return vec3(x - rhs.x, y - rhs.y, y - rhs.z);
}

vec3 vec3::operator - () const {
    return vec3(-x, -y, -z);
}


vec3 vec3::operator * (float scalar) const {
    return vec3(x*scalar, y*scalar, z*scalar);
}

vec3 vec3::operator / (float scalar) const {
    return vec3(x/scalar, y/scalar, z/scalar);
}

vec3 &vec3::operator = (const vec3 &rhs) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
}

vec3 &vec3::operator += (const vec3 &rhs) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
}

vec3 &vec3::operator -= (const vec3 &rhs) {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
}

vec3 &vec3::operator *= (float scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

void vec3::set(const vec3 &other) {
    x = other.x;
    y = other.y;
    z = other.z;
}

bool vec3::isFinite() const {
    return std::isfinite(x) && std::isfinite(y) && std::isfinite(z);
}

bool vec3::isPerpindicular(const vec3 &other) const {
    return dot(other) == 0;
}

bool vec3::isZero() const {
    return lengthSq() <= 1e-7f;
}

float vec3::dot(const vec3 &other) const {
    return x * other.x + y * other.y + z * other.z;
}

float vec3::length() const {
    return std::sqrt(lengthSq());
}

float vec3::lengthSq() const {
    return x*x + y*y + z*z;
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
    return x + y + z;
}

float vec3::product() const {
    return x * y * z;
}

float vec3::average() const {
    return (x + y + z) / 3;
}

float vec3::min() const {
    return std::min(x, std::min(y, z));
}

float vec3::max() const {
    return std::max(x, std::max(y, z));
}

vec3 vec3::abs() const {
    return vec3(std::abs(x), std::abs(y), std::abs(z));
}

vec3 vec3::neg() const {
    return vec3(-x, -y, -z);
}

vec3 vec3::recip() const {
    return vec3(1/x, 1/y, 1/z);
}
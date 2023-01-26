#include "vec3.h"
#include <cmath>

using namespace app;

#define NULL null_init;

vec3::vec3(float x2, float y2, float z2)
:x(x2), y(y2), z(z2) {}

vec3::vec3(const vec3 &rhs)
:x(rhs.x), y(rhs.y), z(rhs.z) {}

vec3::vec3(float scalar)
:x(scalar), y(scalar), z(scalar) {}

void vec3::set(const vec3 &other) {
    x = other.x;
    y = other.y;
    z = other.z;
}

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

float vec3::lengthSq() const {
    return x*x + y*y + z*z;
}
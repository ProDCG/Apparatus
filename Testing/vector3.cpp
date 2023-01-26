#include "vector3.h"
#include <cmath>

using namespace app;


vector3::vector3(float x2, float y2, float z2)
:x(x2), y(y2), z(z2) {}

vector3::vector3(const vector3 &rhs)
:x(rhs.x), y(rhs.y), z(rhs.z) {}

vector3::vector3(float scalar)
:x(scalar), y(scalar), z(scalar) {}

void vector3::set(const vector3 &other) {
    x = other.x;
    y = other.y;
    z = other.z;
}

bool vector3::isFinite() const {
    std::isfinite(x) && std::isfinite(y) && std::isfinite(z);
}

bool vector3::isPerpindicular(const vector3 &other) const {
    return dot(other) == 0;
}

float vector3::dot(const vector3 &other) const {
    return x * other.x + y * other.y + z * other.z;
}
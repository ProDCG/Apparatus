#include "mat3.h"

using namespace app;

mat3::mat3(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3)
:x1(x1), y1(y1), z1(z1), x2(x2), y2(y2), z2(z2), x3(x3), y3(y3), z3(z3) {}

mat3::mat3(const vec3 &v1, const vec3 &v2, const vec3 &v3)
:x1(v1.x), y1(v1.y), z1(v1.z), x2(v2.x), y2(v2.y), z2(v2.z), x3(v3.x), y3(v3.y), z3(v3.z) {}
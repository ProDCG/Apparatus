#include "mat4.h"

using namespace app;

mat4::mat4(float n00, float n01, float n02, float n03, float n10, float n11, float n12, float n13, float n20, float n21, float n22, float n23, float n30, float n31, float n32, float n33)
:n00(n00), n01(n01), n02(n02), n03(n03), n10(n10), n11(n11), n12(n12), n13(n13), n20(n20), n21(21), n22(n22), n23(n23), n30(n30), n31(n31), n32(n32), n33(n33) {}

mat4::mat4(const vec4 &v1, const vec4 &v2, const vec4 &v3, const vec4 &v4)
:n00(v1.n0), n01(v1.n1), n02(v1.n2), n03(v1.n3), n10(v2.n0), n11(v2.n1), n12(v2.n2), n13(v2.n3) {}
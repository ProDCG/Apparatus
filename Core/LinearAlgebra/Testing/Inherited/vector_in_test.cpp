#include "vector_in.hpp"

int main() {
    Vector<double, 3> vec1{1, 2, 3};
    Vector<double, 3> vec2{4, 5, 6};
    vec2 + 2;
    Vector<double, 3> vec3{7, 8, 9};
    return 0;
}
#include "vector_in.hpp"

int main() {
    Vector<double, 3> vec1{1, 2, 3};
    Vector<double, 3> vec2{4, 5, 6};
    Vector<double, 3> vec3 = vec2 + vec1;
    //Vector<double, 3> vec3{7, 8, 9};
    std::cout << vec3[0] << '\n';
    std::cout << vec3[1] << '\n';
    std::cout << vec3[2] << '\n';
    return 0;
}
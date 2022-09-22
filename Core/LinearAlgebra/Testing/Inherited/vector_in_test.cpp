#include "vector_in.hpp"

int main() {
    Vector<double, 3> vec1{1.0, 2.0, 3.0};
    Vector<double, 3> vec2{4, 5, 6};
    Vector<double, 3> vec3 = vec2 + vec1;
    std::cout << vec3[0] << '\n';
    std::cout << vec3[1] << '\n';
    std::cout << vec3[2] << '\n';
    std::cout << magnitude(vec1) << '\n';
    vec1 = powerFunc(vec1, 5);
    std::cout << vec1[0] << '\n';
    std::cout << vec1[1] << '\n';
    std::cout << vec1[2] << '\n';

    return 0;
}
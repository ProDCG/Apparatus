#include "vector2.hpp"

#include <iostream>

int main() {
    app::Vector<int, 3> vec3{1, 2, 3};
    vec3 - 5;
    std::cout << vec3.getVec().at(0);
    return 0;
}
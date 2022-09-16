#include <../Core/LinearAlgebra/Testing/vector2.hpp>

#include <iostream>

int main() {
    app::Vector<int, 3> vec3{1, 2, 3};
    app::Vector<int, 3> vec2{4, 5, 6};
    std::cout << vec3.vec[0];
    return 0;
}
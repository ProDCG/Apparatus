#include <../Core/LinearAlgebra/Testing/vector2.hpp>

int main() {
    app::Vector<int, 3> vec3{1, 2, 3};
    app::Vector<int, 3> vec2{4, 5, 6};
    vec3 += vec2;
    return 0;
}
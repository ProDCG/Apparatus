#include "vector2.hpp"

#include <iostream>

int main() {
    app::Vector<int, 3> vec3{1, 2, 3};
    vec3 - 5;
    vec3.print();
    return 0;
}
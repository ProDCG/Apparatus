#include "vector2.hpp"

#include <iostream>

int main() { 
    app::Vector<int, 3> vec3{1, 2, 3};
    app::Vector<int, 3> vec2{4, 5, 6};
    app::Vector<int, 3> vec1 = vec3 + vec2;
    vec3.print();
    return 0;
}  
#include "mat3.h"
#include "vec3.h"
#include "mat4.h"
#include "Vec4.h"
#include <iostream>

int main() {
    // std::cout << "here" << std::endl;
    app::mat3 mat = app::mat3(1, 5, 2, 7, 3, 7, 8, 4, 6);
    mat.print();
    // app::vec3 vec = app::vec3(3);
    // vec.print();
    return 0;
}
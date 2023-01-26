#include "vector3.h"
#include <iostream>

int main() {
    // finite test
    // perpindicular vector test
    app::vector3 vec3_1 = app::vector3(0.0/0.0, 36, 5);
    app::vector3 vec3_2 = app::vector3(4, 19, 16);

    // perpindicular vector test
    app::vector3 vec3_3 = app::vector3(0, 6, 0);
    app::vector3 vec3_4 = app::vector3(5, 0, 0);
    
    std::cout << "V1 isFinite: " << vec3_1.isFinite() << std::endl;
    std::cout << "V2 isPerpindicular: " << vec3_1.isPerpindicular(vec3_2) << std::endl;
    std::cout << "V3 isPerpindicular: " << vec3_3.isPerpindicular(vec3_4) << std::endl;

    return 0;
}
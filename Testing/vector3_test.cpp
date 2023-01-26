#include "vector3.h"
#include <iostream>

int main() {
    app::vector3 vec3_1 = app::vector3(0.0/0.0, 36, 5);
    app::vector3 vec3_2 = app::vector3(4, 19, 16);
    
    std::cout << "V1 isFinite: " << vec3_1.isFinite() << std::endl;
    std::cout << "V2 isPerpindicular: " << vec3_1.isPerpindicular(vec3_2) << std::endl;

    return 0;
}
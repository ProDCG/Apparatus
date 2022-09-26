#include "vector_in.hpp"
#include "vector_in_typedef.hpp"

int main() {
    vec3 cam = vec3(1.0f);
    std::cout << cam[0] << std::endl;
    std::cout << cam[1] << std::endl;
    std::cout << cam[2] << std::endl;

    return 0;
}
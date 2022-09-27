#include "matrix_in.hpp"
#include "matrix_in_typedef.hpp"

int main() {
    app::mat4 cam = app::mat4(1.0f);
    cam.print();
    cam = cam + 68;
    cam.print();
    return 0;
}
#include "vec3.h"

#include <iostream>
using namespace std;

int main() {
    app::vec3 test_vec = app::vec3(1, 2, 3);
    test_vec.print();
    test_vec *= 3;
    test_vec.print();
    test_vec = test_vec / 2;
    test_vec.print();
    return 0;
}
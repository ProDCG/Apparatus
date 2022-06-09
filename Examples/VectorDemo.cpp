#include <iostream>

#include "Matrix.h"
#include "Vector.h"

int main() {
    Vector<3> v1{1, 2, 3};
    Vector<3> v2{4, 5, 6};

    v1.print();

    (v1 * 2).print();

    (v1 / 2).print();

    (v1 + v2).print();

    (v1 - v2).print();
}
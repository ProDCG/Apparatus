#include <iostream>
#include "Matrix.h"

int main() {
    Matrix<3, 3> m1{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    m1.print();
    m1.transpose();
    m1.print();
}
#include <iostream>
#include "Matrix.h"

int main() {
    Matrix<3, 3> m1{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Matrix<3, 3> m2{
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };

    m1.print();
    std::cout << '\n';
    m2.print();
    std::cout << '\n';
    
    auto newM = m1 * 2.0;

    newM.print();

    newM = m2 / 2.0;

    newM.print();
}
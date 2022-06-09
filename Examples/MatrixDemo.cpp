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

    Matrix<4, 2> testM {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8}
    };

    m1.print();
    std::cout << '\n';
    m2.print();
    std::cout << '\n';

    Matrix<3,3> m3 = m1 - m2;
    m3.print();

    Matrix<3, 3> m4 = m1 + m2;
    m4.print();

    testM.print();

    // auto newM = m1 * 2.0;

    

    // newM.print();

    // newM = m2 / 2.0;

    // newM.print();
}
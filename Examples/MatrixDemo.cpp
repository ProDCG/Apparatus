#include <iostream>
#include "matrix_obj.h"
#include "../Core/LinearAlgebra/matrix_2x2.hpp"

int main() {
    Matrix<3, 3> m1{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    m1.print();
    m1.transpose();
    m1.print();

    Apparatus::mat3x1 = Apparatus::mat3x1({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
}
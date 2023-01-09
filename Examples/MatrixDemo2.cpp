#include "../Core/LinearAlgebra/Matrix/matrix_in_typedef.hpp"
#include <iostream>
#include <array>

int main() {
    Matrix<double, 3, 3> mat{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    mat.print();
}
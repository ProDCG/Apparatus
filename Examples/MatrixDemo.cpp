#include <iostream>
#include <array>
#include "../Core/LinearAlgebra/matrices.hpp"

int main() {
    Matrix<3, 3, double> m1{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    m1.print();
    m1.transpose();
    m1.print();

    apparatus::mat3x3 cam = apparatus::mat3x3(1.0f);
    
    std::array<std::array<int, 3>, 2> arr = {{{1, 2, 3}, {4, 5, 6}}};
}
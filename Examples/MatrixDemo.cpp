#include <iostream>
#include <array>
#include "../Core/LinearAlgebra/Matrix/matrix_in.hpp"

int main() {
    Matrix<3, 3, double> m1{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    m1.print();
    m1.transpose();
    m1.print();

    app::mat3x3 cam = app::mat3x3(1.0f);

    // app matrix
    app::mat4 cam2 = app::mat4(1.0f);
    app::b_mat4 cam3 = app::b_mat4(true);
    app::i_mat2 cam4 = app::i_mat2(false);

    app::mat2 test_mat = app::mat2(1.0f);
    test_mat.print();

    // initializing with list
    app::mat3 cam5{{1, 2, 3}, {4, 5, 6}, {7,  8, 9}};
    
    std::array<std::array<int, 3>, 2> arr = {{{1, 2, 3}, {4, 5, 6}}};
}
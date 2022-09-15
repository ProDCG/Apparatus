#pragma once

#include <../Core/LinearAlgebra/Matrix/matrix.hpp>

namespace app {

    typedef Matrix<4, 4, int> i_mat4x4, i_mat4;
    typedef Matrix<4, 4, double> d_mat4x4, d_mat4, mat4x4, mat4;
    typedef Matrix<4, 4, bool> b_mat4x4, b_mat4;
}
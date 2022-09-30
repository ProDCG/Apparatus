#include <Vector/vector_in.hpp>
#include <Vector/vector_in_typedef.hpp>
#include <Matrix/matrix_in.hpp>
#include <Matrix/matrix_in_typedef.hpp>

int main() {
    app::vec3 vector{1, 2, 3};
    Matrix<double, 3, 2> matrix{
        {1, -1, 2},
        {0, -3, 1}};
    vector.print();
    matrix.print();

    app::vec2 vector2 = matrix * vector;
    vector2.print();

    return 0;
}
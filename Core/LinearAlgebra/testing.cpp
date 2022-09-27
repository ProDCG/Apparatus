#include <vector_in.hpp>
#include <vector_in_typedef.hpp>
#include <matrix_in.hpp>
#include <matrix_in_typedef.hpp>

int main() {
    app::vec3 vector{1, 2, 3};
    app::mat3 matrix{
        {1, 1, 2},
        {2, 1, 3},
        {1, 4, 2}};
    vector.print();
    matrix.print();
    return 0;
}
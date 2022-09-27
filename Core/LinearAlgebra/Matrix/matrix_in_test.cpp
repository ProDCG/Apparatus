#include "matrix_in.hpp"
#include "matrix_in_typedef.hpp"

int main() {
    app::mat3 matOne = app::mat3(1.0f);
    app::mat3 matTwo = app::mat3(1.0f);
    matOne + 2;
    return 0;
}
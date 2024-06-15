#include "../../pathfinding/Grid.hpp"

#include <iostream>

int main() {
    app::Grid<10, 10> grid;
    std::cout << grid.getWidth() << '\n';
    std::cout << grid.getHeight() << '\n';

    grid.print();
    return 0;
}
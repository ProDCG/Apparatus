#include "../../pathfinding/Grid.hpp"

#include <iostream>

int main() {
    app::Grid<10, 10> grid;
    std::cout << grid.getWidth() << '\n';
    std::cout << grid.getHeight() << '\n';

    for (int i = 3; i < 7; i++) {
        grid.addObstacle(5, i);
    }

    grid.print();
    return 0;
}
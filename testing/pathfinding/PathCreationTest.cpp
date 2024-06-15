#include "../../pathfinding/Grid.hpp"
#include "../../pathfinding/A_Star.hpp"

#include <iostream>

int main() {
    app::Grid<10, 10> grid;
    std::cout << grid.getWidth() << '\n';
    std::cout << grid.getHeight() << '\n';

    for (int i = 3; i < 7; i++) {
        grid.addObstacle(5, i);
    }

    app::vec2<int> start(0, 0);
    app::vec2<int> end(9, 9);

    app::A_Star a_star;
    a_star.findPath(grid, start, end);

    grid.print();
    return 0;
}
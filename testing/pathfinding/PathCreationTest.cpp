#include "../../pathfinding/Grid.hpp"
#include "../../pathfinding/A_Star.hpp"
#include "../../pathfinding/Node.hpp"

#include <iostream>

int main() {

    app::Node start(0, 0, false);
    app::Node end(9, 9, false);

    app::Grid<10, 10> grid(start, end);
    std::cout << grid.getWidth() << '\n';
    std::cout << grid.getHeight() << '\n';

    for (int i = 3; i < 7; i++) {
        grid.addObstacle(5, i);
    }

    app::A_Star a_star;
    a_star.findPath(grid, start, end);

    grid.print();
    return 0;
}
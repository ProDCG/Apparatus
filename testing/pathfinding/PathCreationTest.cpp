#include "../../pathfinding/Grid.hpp"
#include "../../pathfinding/AStar.hpp"
#include "../../pathfinding/Node.hpp"

#include <iostream>

int main() {
    app::Grid<10, 10> grid;
    grid.setWalkable(1, 1, false);
    grid.setWalkable(1, 2, false);

    app::AStar aStar;
    app::Node start(0, 0, true);
    app::Node target(7, 7, true);
    aStar.findPath(start, target, grid);
    std::cout << "Here" << '\n';
    return 0;
}
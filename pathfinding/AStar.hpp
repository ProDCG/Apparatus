#pragma once

#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include "Grid.hpp"
#include "Node.hpp"

namespace app {
    class AStar {
    public:
        template <size_t gridWidth, size_t gridHeight>
        void findPath(const Node& start, const Node& end, Grid<gridWidth, gridHeight>& grid);

        void tracePath(const Node& startNode, const Node& endNode);
        void printPath(const std::vector<Node>& path);
        double getDistance(const Node& nodeA, const Node& nodeB);
    };
}

#include "AStar.inl"
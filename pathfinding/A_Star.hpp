#pragma once

#include "Grid.hpp"
#include "Node.hpp"

namespace app {
    class A_Star {
    private:
    public:
        template <size_t gridWidth, size_t gridHeight>
        void findPath(Grid<gridWidth, gridHeight>& grid, const Node& start, const Node& end) const;

        template <size_t gridWidth, size_t gridHeight>
        void tracePath(Grid<gridWidth, gridHeight>& grid, const app::Node& startNode, const app::Node& endNode) const;
    };
}

#include "A_Star.inl"
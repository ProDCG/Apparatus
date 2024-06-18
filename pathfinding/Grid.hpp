#pragma once

#include "Node.hpp"
#include <vector>

namespace app {

    template <size_t _gridWidth, size_t _gridHeight>
    class Grid {
    public:
        static const size_t gridWidth = _gridWidth;
        static const size_t gridHeight = _gridHeight;
        Node nodes[gridWidth][gridHeight];

        Grid();

        std::vector<Node> getNeighbors(const Node& node) const;

        void setWalkable(int x, int y, bool walkable);
    };
}

#include "Grid.inl"
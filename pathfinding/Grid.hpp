#pragma once

#include "Node.hpp"

#include <vector>
#include <algorithm>

namespace app {

    template <size_t _gridWidth, size_t _gridHeight>
    class Grid {
    private:
        static constexpr size_t gridWidth = _gridWidth;
        static constexpr size_t gridHeight = _gridHeight;

        Node grid[gridWidth][gridHeight];

    public:
        Grid();

        size_t getWidth() const;
        size_t getHeight() const;

        std::vector<Node> getNeighbors(const Node& node) const;

        void print() const;
    };
}

#include "Grid.inl"
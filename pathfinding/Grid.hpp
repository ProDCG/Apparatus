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

        Node start = Node(0, 0, false);
        Node end = Node(9, 9, false);

        Node grid[gridWidth][gridHeight];

    public:
        Grid(const Node& start, const Node& end);

        size_t getWidth() const;
        size_t getHeight() const;

        Node getStartPos() const;
        Node getEndPos() const;

        std::vector<Node> getNeighbors(const Node& node) const;

        void addObstacle(int x, int y);
        void print();
    };
}

#include "Grid.inl"
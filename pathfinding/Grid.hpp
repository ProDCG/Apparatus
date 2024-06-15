#pragma once

#include "Node.hpp"
#include "../linalg/vec2.hpp"

#include <vector>
#include <algorithm>

namespace app {

    template <size_t _gridWidth, size_t _gridHeight>
    class Grid {
    private:
        static constexpr size_t gridWidth = _gridWidth;
        static constexpr size_t gridHeight = _gridHeight;

        app::vec2<int> start = app::vec2<int>(0, 0);
        app::vec2<int> end = app::vec2<int>(0, 0);

        Node grid[gridWidth][gridHeight];

    public:
        Grid();

        size_t getWidth() const;
        size_t getHeight() const;

        app::vec2<int> getStartPos() const;
        app::vec2<int> getEndPos() const;

        std::vector<Node> getNeighbors(const Node& node) const;

        void addObstacle(int x, int y);
        void print();
    };
}

#include "Grid.inl"
#pragma once

#include "Grid.hpp"
#include "../linalg/vec2.hpp"

namespace app {
    class A_Star {
    private:
    public:
        template <size_t gridWidth, size_t gridHeight>
        void findPath(Grid<gridWidth, gridHeight>& grid, const Node& start, const Node& end);
    };
}

#include "A_Star.inl"
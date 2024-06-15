#pragma once

#include "Grid.hpp"
#include "../linalg/vec2.hpp"

namespace app {
    class A_Star {
    private:
    public:
        template <size_t gridWidth, size_t gridHeight>
        void findPath(Grid<gridWidth, gridHeight>& grid, const app::vec2<int>& start, const app::vec2<int>& end);
    };
}

#include "A_Star.inl"
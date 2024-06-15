#include "Grid.hpp"

namespace app {
    template <size_t gridWidth, size_t gridHeight>
    Grid<gridWidth, gridHeight>::Grid() {
//        for (int i = 0; i < gridWidth; i++) {
//            for (int j = 0; )
//        }
    }

    template <size_t gridWidth, size_t gridHeight>
    size_t Grid<gridWidth, gridHeight>::getWidth() const {
        return gridWidth;
    }

    template <size_t gridWidth, size_t gridHeight>
    size_t Grid<gridWidth, gridHeight>::getHeight() const {
        return gridHeight;
    }


}
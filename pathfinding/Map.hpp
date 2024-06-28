#pragma once

namespace app {
    constexpr unsigned char START_X = 0;
    constexpr unsigned char START_Y = 0;

    constexpr unsigned char TARGET_X = 10;
    constexpr unsigned char TARGET_Y = 10;

    constexpr unsigned char COLUMNS = 10;
    constexpr unsigned char ROWS = 10;

    enum Cell {
        Empty,
        Visited,
        Wall,
        End
    };

    template <typename value_type = Cell>
    using Map = std::array<std::array<value_type, ROWS, COLUMNS>;
}
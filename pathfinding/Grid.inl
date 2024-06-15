namespace app {

    template <size_t gridWidth, size_t gridHeight>
    Grid<gridWidth, gridHeight>::Grid() {
        for (int i = 0; i < gridWidth; i++) {
            for (int j = 0; j < gridHeight; j++) {
                grid[i][j] = Node(i, j, false);
            }
        }
    }

    template <size_t gridWidth, size_t gridHeight>
    size_t Grid<gridWidth, gridHeight>::getWidth() const {
        return gridWidth;
    }

    template <size_t gridWidth, size_t gridHeight>
    size_t Grid<gridWidth, gridHeight>::getHeight() const {
        return gridHeight;
    }

    template <size_t gridWidth, size_t gridHeight>
    std::vector<Node> Grid<gridWidth, gridHeight>::getNeighbors(const app::Node &node) const {
        std::vector<Node> neighbors;

        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                int checkX = node.x + i;
                int checkY = node.y + j;
                if (checkX >= 0 && checkX <= gridWidth && checkY >= 0 && checkY <= gridHeight) {
                    neighbors.push_back(grid[i][j]);
                }
            }
        }

        return neighbors;
    }

    template <size_t gridWidth, size_t gridHeight>
    void Grid<gridWidth, gridHeight>::print() const {
        for (int i = 0; i < gridWidth; i++) {
            for (int j = 0; j < gridHeight; j++) {
                if (grid[i][j].obstacle) std::cout << '#';
                else std::cout << '.';
            }
            std::cout << '\n';
        }
    }
}
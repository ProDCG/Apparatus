namespace app {

    template <size_t gridWidth, size_t gridHeight>
    app::Grid<gridWidth, gridHeight> Grid(const Node& start, const Node& end) {
        for (int i = 0; i < gridWidth; i++) {
            for (int j = 0; j < gridHeight; j++) {
                Node node(i, j, false);
                node.gCost = node.distance(start);
                node.hCost = node.distance(end);
                grid[i][j] = node;
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
    Node Grid<gridWidth, gridHeight>::getStartPos() const {
        return start;
    }

    template <size_t gridWidth, size_t gridHeight>
    Node Grid<gridWidth, gridHeight>::getEndPos() const {
        return end;
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
    bool Grid<gridWidth, gridHeight>::isObstacle(int x, int y) {
        return grid[x][y].obstacle;
    }

    template <size_t gridWidth, size_t gridHeight>
    void Grid<gridWidth, gridHeight>::addObstacle(int x, int y) {
        grid[x][y].obstacle = true;
    }

    template <size_t gridWidth, size_t gridHeight>
    void Grid<gridWidth, gridHeight>::print() {
        for (int i = 0; i < gridWidth; i++) {
            for (int j = 0; j < gridHeight; j++) {
                if (grid[i][j].obstacle) std::cout << '#';
                else if (grid[i][j].x == start.x && grid[i][j].y == start.y) std::cout << 'S';
                else if (grid[i][j].x == end.x && grid[i][j].y == end.y) std::cout << 'E';
                else std::cout << '.';
            }
            std::cout << '\n';
        }
    }
}
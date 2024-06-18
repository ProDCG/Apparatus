namespace app {
    template <size_t _gridWidth, size_t _gridHeight>
    Grid<_gridWidth, _gridHeight>::Grid() {
        for (size_t x = 0; x < gridWidth; x++) {
            for (size_t y = 0; y < gridHeight; y++) {
                nodes[x][y] = Node(x, y, true);
            }
        }
    }

    template <size_t _gridWidth, size_t _gridHeight>
    std::vector<Node> Grid<_gridWidth, _gridHeight>::getNeighbors(const app::Node &node) const {
        std::vector<Node> neighbors;
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= -1; dy++) {
                if (dx == 0 && dy == 0) continue;
                int checkX = node.x + dx;
                int checkY = node.y + dy;

                if (checkX >= 0 && checkX < gridWidth && checkY >= 0 && checkY < gridHeight) {
                    neighbors.push_back(nodes[checkX][checkY]);
                }
            }
        }

        return neighbors;
    }

    template <size_t _gridWidth, size_t _gridHeight>
    void Grid<_gridWidth, _gridHeight>::setWalkable(int x, int y, bool walkable) {
        nodes[x][y].walkable = walkable;
    }
}
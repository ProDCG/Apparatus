#include "Node.hpp"

#include <algorithm>

namespace app {
    template <size_t gridWidth, size_t gridHeight>
    void A_Star::findPath(Grid<gridWidth, gridHeight>& grid, const Node& start, const Node& end) {
        Node startNode = start;
        Node endNode = end;

        std::vector<Node> openSet;
        std::vector<Node> closedSet;

        openSet.push_back(startNode);

        while (!openSet.empty()) {
            Node current = openSet[0];

            for (int i = 1; i < openSet.size(); i++) {
                if (openSet[i].fCost() < current.fCost() || openSet[i].fCost() == current.fCost()) {
                    if (openSet[i].hCost < current.hCost) current = openSet[i];
                }
            }

            auto it = std::find(openSet.begin(), openSet.end(), current);
            if (it != openSet.end()) openSet.erase(it);

            closedSet.push_back(current);

            if (current == endNode) {
                // Path Backtracking

                std::vector<Node> path;
                Node* pathNode = &current;
                while (pathNode != nullptr) {
                    path.push_back(*pathNode);
                    pathNode = pathNode->parent;
                }

                char asciiGrid[gridHeight][gridWidth];
                for (size_t y = 0; y < gridHeight; y++) {
                    for (size_t x = 0; x < gridWidth; x++) {
                        if (grid.isObstacle(x, y)) asciiGrid[y][x] = '#';
                        else asciiGrid[y][x] = '.';
                    }
                }

                for (const Node& node : path) {
                    asciiGrid[node.y][node.x] = 'O';
                }

                asciiGrid[startNode.y][startNode.x] = 'S';
                asciiGrid[endNode.y][endNode.x] = 'E';

                for (size_t y = 0; y < gridHeight; y++) {
                    for (size_t x = 0; x < gridWidth; x++) {
                        std::cout << asciiGrid[y][x];
                    }
                    std::cout << '\n';
                }

                return;
            }

            for (Node node : grid.getNeighbors(current)) {
                if (node.obstacle || std::find(closedSet.begin(), closedSet.end(), node) != closedSet.end()) {
                    continue;
                }

                double newCost = current.gCost + node.distance(current);
                if (newCost < node.gCost || !(std::find(closedSet.begin(), closedSet.end(), node) != closedSet.end())) {
                    node.gCost = newCost;
                    node.hCost = node.distance(endNode);
                    node.parent = &current;

                    if (!(std::find(openSet.begin(), openSet.end(), node) != openSet.end())) openSet.push_back(node);
                }
            }
        }
    }
}
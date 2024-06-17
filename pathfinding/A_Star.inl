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
            openSet.erase(openSet.begin());
            closedSet.push_back(current);

            if (current == startNode) return;

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
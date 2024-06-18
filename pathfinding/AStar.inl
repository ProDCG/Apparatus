namespace app {
    template <size_t _gridWidth, size_t _gridHeight>
    void AStar::findPath(const app::Node &startNode, const app::Node &endNode, Grid<_gridWidth, _gridHeight> &grid) {
        Node targetNode = endNode;

        std::vector<Node> openSet;
        std::unordered_set<Node> closedSet;
        openSet.push_back(startNode);

        while (!openSet.empty()) {
            Node currentNode = openSet[0];
            for (size_t i = 1; i < openSet.size(); ++i) {
                if (openSet[i].fCost() < currentNode.fCost() ||
                    (openSet[i].fCost() == currentNode.fCost() && openSet[i].hCost < currentNode.hCost)) {
                    currentNode = openSet[i];
                }
            }

            openSet.erase(std::remove(openSet.begin(), openSet.end(), currentNode), openSet.end());
            closedSet.insert(currentNode);

            if (currentNode == targetNode) {
                tracePath(startNode, targetNode);
                return;
            }

            for (const Node& neighbour : grid.getNeighbors(currentNode)) {
                if (!neighbour.walkable || closedSet.find(neighbour) != closedSet.end()) {
                    continue;
                }

                int newCostToNeighbour = currentNode.gCost + getDistance(currentNode, neighbour);
                if (newCostToNeighbour < neighbour.gCost ||
                    std::find(openSet.begin(), openSet.end(), neighbour) == openSet.end()) {
                    Node& mutableNeighbour = const_cast<Node&>(neighbour);
                    mutableNeighbour.gCost = newCostToNeighbour;
                    mutableNeighbour.hCost = getDistance(mutableNeighbour, targetNode);
                    mutableNeighbour.parent = new Node(currentNode);

                    if (std::find(openSet.begin(), openSet.end(), neighbour) == openSet.end()) {
                        openSet.push_back(neighbour);
                    }
                }
            }
        }
    }

    void AStar::tracePath(const app::Node &startNode, const app::Node &endNode) {
        std::cout << "1";
        std::vector<Node> path;
        Node* currentNode = new Node(endNode);
        while (*currentNode != startNode) {
            path.push_back(*currentNode);
            currentNode = currentNode->parent;
        }
        std::reverse(path.begin(), path.end());
        printPath(path);
    }

    void AStar::printPath(const std::vector<Node> &path) {
        std::cout << "here" << '\n';
        for (const Node& node : path) {
            std::cout << "(" << node.x << "," << node.y << ") ";
        }
        std::cout << std::endl;
    }

    double AStar::getDistance(const app::Node &nodeA, const app::Node &nodeB) {
        int distX = std::abs(nodeA.x - nodeB.x);
        int distY = std::abs(nodeA.y - nodeB.y);
        return std::sqrt(distX * distX + distY * distY);
    }
}
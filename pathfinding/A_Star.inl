#include "Node.hpp"

#include <algorithm>
#include <vector>
#include <unordered_set>
#include <iostream>

namespace app {
    template <size_t gridWidth, size_t gridHeight>
    void A_Star::findPath(Grid<gridWidth, gridHeight>& grid, const Node& start, const Node& end) const {
        app::Node startNode = start;
        app::Node endNode = end;

        std::vector<Node> openSet;
        std::unordered_set<app::Node> closedSet;
        openSet.push_back(startNode);




        while (!openSet.empty()) {
            Node currentNode = openSet[0];

            for (size_t i = 1; i < openSet.size(); ++i) {
                if (openSet[i].fCost() < currentNode.fCost() || openSet[i].fCost() == currentNode.fCost()) {
                    if (openSet[i].hCost < currentNode.hCost) {
                        currentNode = openSet[i];
                    }
                }
            }

            openSet.erase(std::remove(openSet.begin(), openSet.end(), currentNode), openSet.end());
            closedSet.insert(currentNode);

            std::cout << '(' << currentNode.x << ", " << currentNode.y << ") (" << endNode.x << ", " << endNode.y << ')' << '\n';
            if (currentNode == endNode) {
                tracePath(grid, startNode, endNode);
                return;
            }



//            if (currentNode == endNode) {
//                // Path Backtracking
//
//                std::vector<Node> path;
//                Node currentNode = endNode;
//
//                while (currentNode != start) {
//                    path.push_back(currentNode);
//                    currentNode = *(currentNode.parent);
//                }
//
//                char asciiGrid[gridHeight][gridWidth];
//                for (size_t y = 0; y < gridHeight; y++) {
//                    for (size_t x = 0; x < gridWidth; x++) {
//                        if (grid.isObstacle(x, y)) asciiGrid[y][x] = '#';
//                        else asciiGrid[y][x] = '.';
//                    }
//                }
//
//                for (const Node& node : path) {
//                    asciiGrid[node.y][node.x] = 'O';
//                }
//
//                asciiGrid[startNode.y][startNode.x] = 'S';
//                asciiGrid[endNode.y][endNode.x] = 'E';
//
//                for (size_t y = 0; y < gridHeight; y++) {
//                    for (size_t x = 0; x < gridWidth; x++) {
//                        std::cout << asciiGrid[y][x];
//                    }
//                    std::cout << '\n';
//                }

//                return;
//            }

            for (app::Node& neighbor : grid.getNeighbors(currentNode)) {
                if (!neighbor.obstacle || closedSet.find(neighbor) != closedSet.end()) continue;

                double newCostToNeighbor = currentNode.gCost + neighbor.distance(currentNode);
                if (newCostToNeighbor < neighbor.gCost ||
                std::find(openSet.begin(), openSet.end(), neighbor) == openSet.end()) {
                    neighbor.gCost = newCostToNeighbor;
                    neighbor.hCost = neighbor.distance(endNode);
                    neighbor.parent = new Node(currentNode);
                }

                if (std::find(openSet.begin(), openSet.end(), neighbor) == openSet.end()) {
                    openSet.push_back(neighbor);
                }
            }

//            for (Node node : grid.getNeighbors(current)) {
//                if (node.obstacle || std::find(closedSet.begin(), closedSet.end(), node) != closedSet.end()) {
//                    continue;
//                }
//
//                double newCost = current.gCost + node.distance(current);
//                if (newCost < node.gCost || !(std::find(closedSet.begin(), closedSet.end(), node) != closedSet.end())) {
//                    node.gCost = newCost;
//                    node.hCost = node.distance(endNode);
//                    node.parent = &current;
//
//                    if (!(std::find(openSet.begin(), openSet.end(), node) != openSet.end())) openSet.push_back(node);
//                }
//            }
        }
    }

    template <size_t gridWidth, size_t gridHeight>
    void A_Star::tracePath(Grid<gridWidth, gridHeight>& grid, const app::Node &startNode, const app::Node &endNode) const {
        std::vector<app::Node> path;
        auto* currentNode = new Node(endNode);
        while (*currentNode != startNode) {
            path.push_back(*currentNode);
            currentNode = currentNode->parent;
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
    }
}
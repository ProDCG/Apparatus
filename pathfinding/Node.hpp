#pragma once

namespace app {
    struct Node {
        int x, y;
        int gCost, hCost;
        bool obstacle;

        explicit Node(int _x, int _y, bool _obstacle);
        explicit Node();

        double distance(const Node& other) const;
        int fCost() const;
    };
}

#include "Node.inl"
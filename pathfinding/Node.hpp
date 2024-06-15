#pragma once

namespace app {
    struct Node {
        int x, y;
        double gCost, hCost;
        bool obstacle;
        app::Node* parent;

        explicit Node(int _x, int _y, bool _obstacle);
        explicit Node();

        bool operator==(const Node& other) const;

        double distance(const Node& other) const;
        double fCost() const;
    };
}

#include "Node.inl"
#pragma once

#include <cmath>
#include <functional>

namespace app {
    struct Node {
        int x, y;
        bool walkable;
        int gCost, hCost;
        app::Node* parent;

        Node(int _x = 0, int _y = 0, bool _walkable = true);

        bool operator==(const Node& other) const;
        bool operator!=(const Node& other) const;
        int fCost() const;
        double distance(const Node& other) const;
    };
}

namespace std {
    template<>
    struct hash<app::Node> {
        std::size_t operator()(const app::Node& node) const noexcept;
    };

    template<>
    struct equal_to<app::Node> {
        bool operator()(const app::Node& lhs, const app::Node& rhs) const noexcept;
    };
}

#include "Node.inl"
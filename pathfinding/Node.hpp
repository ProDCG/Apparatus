#pragma once

#include <cmath>
#include <functional>

namespace app {
    struct Node {
        int x, y;
        bool obstacle;
        double gCost, hCost;
        app::Node* parent;

        Node(int _x, int _y, bool _obstacle);

        bool operator==(const Node& other) const;
        double fCost() const;
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
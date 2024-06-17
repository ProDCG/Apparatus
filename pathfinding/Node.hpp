#pragma once

#include <functional>

namespace app {
    struct Node {
        int x, y;
        double gCost, hCost;
        bool obstacle;
        app::Node* parent;

        explicit Node(int _x, int _y, bool _obstacle);
        explicit Node();

        bool operator==(const Node& other) const;
        bool operator!=(const Node& other) const;

        double distance(const Node& other) const;
        double fCost() const;
    };
}

namespace std {
    template<>
    struct hash<app::Node> {
        std::size_t operator()(const app::Node& node) const noexcept {
            return std::hash<int>()(node.x) ^ (std::hash<int>()(node.y) << 1);
        }
    };

    template<>
    struct equal_to<app::Node> {
        bool operator()(const app::Node& left, const app::Node& right) const noexcept {
            return left.x == right.x && left.y == right.y;
        }
    };
}

#include "Node.inl"
#pragma once

#include "Node.hpp"

namespace app {
    Node::Node(int _x, int _y, bool _obstacle) : x(_x), y(_y), obstacle(_obstacle), gCost(0), hCost(0), parent(nullptr) {}

    bool Node::operator==(const Node& other) const {
        return x == other.x && y == other.y;
    }

    double Node::fCost() const {
        return gCost + hCost;
    }

    double Node::distance(const app::Node& other) const {
        return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }
}

namespace std {
    std::size_t hash<app::Node>::operator()(const app::Node& node) const noexcept {
        return std::hash<int>()(node.x) ^ (std::hash<int>()(node.y) << 1);
    }

    bool equal_to<app::Node>::operator()(const app::Node& lhs, const app::Node& rhs) const noexcept {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }
}
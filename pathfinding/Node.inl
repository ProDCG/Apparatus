#include <iostream>
#include <cmath>

namespace app {

    Node::Node(int _x, int _y, bool _obstacle) : x(_x), y(_y), obstacle(_obstacle), gCost(0), hCost(0) {}
    Node::Node() : x(0), y(0), obstacle(false), gCost(0), hCost(0) {}

    bool Node::operator==(const Node& other) const {
        return (other.x == x && other.y == y);
    }

     bool Node::operator!=(const Node& other) const {
        return (other.x != x || other.y != y);
    }

    double Node::distance(const Node& other) const {
        return std::sqrt(x * other.x + y * other.y);
    }

    double Node::fCost() const {
        return gCost + hCost;
    }
}
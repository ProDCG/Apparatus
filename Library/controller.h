#ifndef PURE_PURSUIT_CONTROLLER_H
#define PURE_PURSUIT_CONTROLLER_H

namespace controller {
    template <typename Pose>
    Pose relativeDistanceToTarget(Pose self, Pose target) {
        return target.subtract(self);
    }

    template <typename Point>
    void lineCircleIntersection(Point pointA, Point pointB, Point center, double radius) {

    }
}


#endif
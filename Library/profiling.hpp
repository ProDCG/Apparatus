#ifndef PURE_PURSUIT_GEOMETRY_PROFILING_H
#define PURE_PURSUIT_GEOMETRY_PROFILING_H

#include <algorithm>

namespace profiling {
    double update(double time, double maxAcceleration, double maxVelocity) {
        if (time < 0) {
            return 0;
        }

        double velocity = (maxAcceleration * time) / maxVelocity;
        velocity = std::min(velocity, maxVelocity);
        return velocity;
    }

    double trapezoidal(double time, double maxAcceleration, double maxVelocity) {

    }

    double s_curve(double time, double maxAcceleration, double maxVelocity) {
        
    }
}

#endif

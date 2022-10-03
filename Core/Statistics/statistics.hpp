#pragma once

#include <array>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <math.h>

namespace app {
    double z_score(double std_dev, double observed, double average) {
        return (observed - average) / std_dev;
    }

    double normal_distribution(double std_dev, double mean, double observed) {
        double exp = -std::pow(observed - mean, 2) / (2 * std::pow(std_dev, 2));
        double base = 1 / (std_dev * std::sqrt(2 * std::atan(1)*4));
        return base * std::pow(std::exp(1.0), exp);
    }
}

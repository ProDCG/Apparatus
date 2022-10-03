#pragma once

#include <array>
#include <algorithm>
#include <iostream>

namespace app {
    double z_score(double std_dev, double observed, double average) {
    return (observed - average) / std_dev;
}
}

#ifndef CORE_ALGEBRA_QUADRATIC_H
#define CORE_ALGEBRA_QUADRATIC_H

#include <array>
#include <cmath>

template <typename T>
float quadratic(float a, float b, float c) {
    return (-b + std::sqrt(std::pow(b, 2) - 4 * a * c)) / (2 * a);
}

#endif
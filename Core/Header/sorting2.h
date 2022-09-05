#ifndef SORTING2_H
#define SORTING2_H

#include <array>
// POLICY PATTERN
// in implementation of sort() do the desired policy 

template<typename policy, typename T, size_t n>
std::array<T, n> sort(std::array<T, n> arr);

struct insertion_sort_policy_t {};
#endif
#ifndef SORTING2_H
#define SORTING2_H

#include <iostream>
#include <array>

// POLICY PATTERN
// in implementation of sort() do the desired policy 

template <typename T>
T sort(T arr);

struct insertion_sort_policy_t {
    template<typename T>
    T operator()(T arr) {
        return arr;
    }
};

std::array<int, 3> arr = {1, 2, 3};
arr = sort<insertion_sort_policy_t>(arr);


#endif
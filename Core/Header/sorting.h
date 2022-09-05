#ifndef SORTING_H
#define SORTING_H

#include <array>
// POLICY PATTERN
// in implementation of sort() do the desired policy 

template<typename T, size_t s>
struct sort {
    virtual std::array<T, s> sort(std::array<T, s> arr);
};



// template<typename policy, typename T, size_t s> std::array<T, s> sort(std::array<T, s> arr);

// struct insertion_sort_policy_t {    
// };

// struct merge_sort_policy_t {};

// struct bubble_sort_policy_t {};
#endif
#ifndef SORTING_H
#define SORTING_H

#include <array>

template<typename T, size_t s>
std::array<T, s> mergeSort(std::array<T, s> arr);

template<typename T, size_t s>
std::array<T, s> insertionSort(std::array<T, s> arr);

// POLICY PATTERN
// in implementation of sort() do the desired policy

template<typename policy, typename T> T sort(T arr);

struct insertion_sort_policy_t {
    // something about defining insertion sort
};

struct merge_sort_policy_t {};

struct bubble_sort_policy_t {};
#endif
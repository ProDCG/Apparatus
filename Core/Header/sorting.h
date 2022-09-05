#ifndef SORTING_H
#define SORTING_H

#include <array>

template<size_t s>
std::array<int, s> insertionSort(std::array<int, s> arr);

template<size_t s>
std::array<int, s> mergeSort(std::array<int, s> arr);
#endif
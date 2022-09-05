#ifndef SORTING_H
#define SORTING_H

#include <array>

template<typename T, size_t s>
std::array<T, s> mergeSort(std::array<T, s> arr);

template<typename T, size_t s>
std::array<T, s> insertionSort(std::array<T, s> arr);

#endif
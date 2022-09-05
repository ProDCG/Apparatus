#ifndef SORTING_H
#define SORTING_H

#include <array>

namespace sorting {
    template<typename T, size_t s>
    std::array<T, s> quick_sort(std::array<T, s> arr);

    template<typename T, size_t s>
    std::array<T, s> merge_sort(std::array<T, s> arr);
}

#endif
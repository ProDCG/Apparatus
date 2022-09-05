#include "sorting.h"

template<typename policy, typename T, size_t s> std::array<T, s> sort(std::array<T, s> arr) {
    for (int i = 0; i < arr.length; i++) {
        std::cout << i << std::endl;
    }
    return arr;
}
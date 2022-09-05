#include <array>
#include "sorting.h"

int values[] = {1, 2, 3};
std::array<int, 5> values2 = {1, 2, 3, 4, 5};
std::array<int, 5> values3 = sort<insertion_sort_policy_t, int, 5>(values2);
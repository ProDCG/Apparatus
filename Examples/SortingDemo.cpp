#include <array>
#include <sorting.h>

std::array<int, 6> values = {1, 29, 643, 25, -5};
sort<insertion_sort_policy_t>(values);
std::cout << values << std::endl;
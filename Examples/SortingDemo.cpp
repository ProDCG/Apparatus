#include <iostream>
#include <array>
#include <sorting.h>
#include <chrono>

std::array<int, 6> values = {1, 29, 643, 25, -5};
int main() {
    
    sort<insertion_sort_policy_t>(values);
}

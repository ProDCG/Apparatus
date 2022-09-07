#include <iostream>
#include <array>
#include <sorting.h>

std::array<int, 6> values = {1, 29, 643, 25, -5};
int main() {
    for (int num : values) {
        std::cout << num << ", ";
    }
    std::cout << '\n';
    sort<insertion_sort_policy_t>(values);
    for (int num : values) {
        std::cout << num << ", ";
    }
}

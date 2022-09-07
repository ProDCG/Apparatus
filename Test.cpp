//#include <Core/Header/sorting.h>
// https://cloud.proxyxyz.repl.co

#include  <Core/Header/sorting.h>

#include <iostream>
#include <array>

std::array<int, 3> arr = {1, 2, 3};

int main() {
    sort<insertion_sort_policy_t>(arr);
    std::cout << arr[1];
}
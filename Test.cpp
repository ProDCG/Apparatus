//#include <Core/Header/sorting.h>
// https://cloud.proxyxyz.repl.co

#include  <Core/Header/sorting.h>

#include <iostream>
#include <array>

std::array<int, 6> arr = {27, 19, 54, 294, -52, 25};

int main() {
    sort<insertion_sort_policy_t>(arr);
    std::cout << arr[1];
}
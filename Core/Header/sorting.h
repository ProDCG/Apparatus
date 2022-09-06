#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <array>

template <typename Policy, typename T> 
void sort(T arr);

struct quick_sort_policy_t {
    template<typename T>
    void operator()(T arr) {
        arr[1] = -5;
        // return arr;
    }
};


// std::array<int, 3> arr = {1, 2, 3};

// int main() {
//     sort<quick_sort_policy_t>(arr);
//     std::cout << arr.at(1);
// }



#endif
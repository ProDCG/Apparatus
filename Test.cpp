//#include <Core/Header/sorting.h>

#include <iostream>
#include <array>

template <typename Policy, typename T> 
void sort(T arr);

struct quick_sort_policy_t {
    template<typename T>
    void operator()(T& arr) {
        std::cout << typeid(arr).name() << '\n';
    }
};

std::array<int, 3> arr = {1, 2, 3};
int arr2[] = {1, 2, 3};

int main() {
    sort<quick_sort_policy_t>(&arr2);
    std::cout << arr.at(1);
}
//#include <Core/Header/sorting.h>

#include <iostream>
#include <array>

template <typename Policy, typename T> 
void sort(T arr);

struct some_sort_policy {
    template<typename T>
    void operator()(T& arr) {
        std::cout << typeid(arr).name() << '\n';
        // do something with the array
    }
};

std::array<int, 3> arr = {1, 2, 3};
int arr2[] = {1, 2, 3};

int main() {
    sort<some_sort_policy>(&arr2);
    std::cout << arr.at(1);
}

template<typename Policy, typename T>
void sort(T arr) {
    std::cout << "a" << std::endl;
}
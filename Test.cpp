//#include <Core/Header/sorting.h>

#include <iostream>
#include <array>

template <typename Policy, typename T> 
void sort(T& arr) {
    Policy p;

    p(arr);
}

struct some_sort_policy {
    template<typename T>
    void operator()(T& arr) {
        std::cout << typeid(arr).name() << '\n';
        arr[1] = 15;
    }
};

struct some_other_sort_policy {
    template<typename T>
    void operator()(T& arr) {
        std::cout << "dab";
    }
};


std::array<int, 3> arr = {1, 2, 3};

int main() {
    sort<some_other_sort_policy>(arr);
    std::cout << arr[1];
}
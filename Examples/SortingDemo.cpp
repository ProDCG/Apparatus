#include <iostream>
#include <array>
#include <sorting.h>
#include <chrono>

std::array<int, 6> values = {1, 29, 643, 25, -5};
int main() {
    auto start = std::chrono::high_resolution_clock::now();
    sort<insertion_sort_policy_t>(values);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << duration.count() << std::endl;
}

template <typename T>
void insertion_sort(T& arr) {
    int i, key, j;
        for (i = 1; i < arr.size(); i++) {
            key = arr[i];
            j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
}
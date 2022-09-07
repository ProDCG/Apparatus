#ifndef SORTING_H
#define SORTING_H

template <typename Policy, typename T> 
void sort(T& arr) {
    Policy p;

    p(arr);
}

struct insertion_sort_policy_t {
    template <typename T>
    void operator()(T& arr) {
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
};

struct quick_sort_policy_t {
    template <typename T>
    void operator()(T& arr) {
        // sort
    }
};

struct merge_sort_policy_t {
    template <typename T>
    void operator()(T& arr) {
        // sort
    }
};

struct bubble_sort_policy_t {
    template <typename T>
    void operator()(T& arr) {
        // sort
    }
};

struct selection_sort_policy_t {
    template <typename T>
    void operator()(T& arr) {
        // sort
    }
};

struct counting_sort_policy_t {
    template <typename T>
    void operator()(T& arr) {
        // sort
    }
};

struct heap_sort_policy_t {
    template <typename T>
    void operator()(T& arr) {
        // sort
    }
};

struct radix_sort_policy_t {
    template <typename T>
    void operator()(T& arr) {
        // sort
    }
};

#endif
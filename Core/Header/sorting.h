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
        // to be implemented
    }

    template <typename T>
    void quicksort(T& arr, int start, int end) {
        if (start >= end) {
            return;
        }

        int p = partition(arr, start, end);
        quicksort(arr, start, p - 1);
        quicksort(arr, p + 1, end);
    }

    template<typename T>
    int partition(T& arr, int start, int end) {
        int pivot = arr[start];

        int count = 0;
        for (int i = start = 1; i <= end; i++) {
            if (arr[i] <= pivot) {
                count++;
            }
        }

        int pivotIndex = start + count;
        std::swap(arr[pivotIndex], arr[start]);
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
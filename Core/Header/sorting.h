#ifndef SORTING_H
#define SORTING_H

/*
insertion sort
quick sort
selection sort
*/

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
        quicksort(arr, 0, arr.size() - 1);
    }

    template<typename T>
    void quicksort(T& arr, int start, int end) {
        if (start < end) {
            int pi = partition(arr, start, end);

            quicksort(arr, start, pi - 1);
            quicksort(arr, pi + 1, end);
        }
    }

    template<typename T, typename T2>
    int partition(T& arr, T2 start, T2 end) {
        int pivot = arr[end];

        int i = (start - 1);

        for (int j = start; j < end; j++) {
            if (arr[j] <= pivot) {
                i++;
                //std::swap(&arr[i], &arr[j]);
                swap(&arr[i], &arr[j]);
            }
        }

        // std::swap(&arr[i + 1], &arr[end]);
        swap(&arr[i + 1], &arr[end]);

        return (i + 1);
    }

    void swap(int *a, int *b) {
        int t = *a;
        *a = *b;
        *b = t;
    }
};

struct selection_sort_policy_t {
    template <typename T>
    void operator()(T& arr) {
        int min_idx = 0, i = 0, j = 0;
        for (i = 0; i < arr.size() - 1; i++) {
            min_idx = i;
            for (j = i + 1; j < arr.size(); j++) {
                if (arr[j] < arr[min_idx]) {
                    min_idx = j;
                }
            }

            if (min_idx != i) {
                std::swap(&arr[min_idx], &arr[i]);
            }
        }
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
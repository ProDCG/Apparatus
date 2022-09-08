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
        //quicksort(arr, 0, arr.size());
        std::cout << "here" << arr.size() << " " << arr.size() - 1 << std::endl;
        quicksort(arr, 0, arr.size() - 1);
    }

    template<typename T, typename sST, typename sEN>
    void quicksort(T& arr, sST start, sEN end) {
        if (start < end) {
            int pi = partition(arr, start, end);

            quicksort(arr, start, pi - 1);

            quicksort(arr, pi + 1, end);
        }
    }

    template<typename T, typename sST, typename sEN>
    int partition(T& arr, sST start, sEN end) {
        int pivot = arr[end];

        int i = (start - 1);

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }

        swap(&arr[i + 1], &arr[end]);

        return (i + 1);
    }

    void swap(int *a, int *b) {
        int t = *a;
        *a = *b;
        *b = t;
    }

    // template <typename T>
    // void quicksort(T& arr, int start, int end) {
    //     if (start >= end) {
    //         return;
    //     }

    //     int p = partition(arr, start, end);
    //     quicksort(arr, start, p - 1);
    //     quicksort(arr, p + 1, end);
    // }

    // template<typename T>
    // int partition(T& arr, int start, int end) {
    //     int pivot = arr[start];

    //     int count = 0;
    //     for (int i = start = 1; i <= end; i++) {
    //         if (arr[i] <= pivot) {
    //             count++;
    //         }
    //     }

    //     int pivotIndex = start + count;
    //     std::swap(arr[pivotIndex], arr[start]);

    //     int i = start, j = end;
    //     while (i < pivotIndex && j > pivotIndex) {
    //         while (arr[i] <= pivot) {
    //             i++;
    //         }

    //         while (arr[j] > pivot) {
    //             j--;
    //         }

    //         if (i < pivotIndex && j > pivotIndex) {
    //             std::swap(arr[i++], arr[j--]);
    //         }
    //     }

    //     return pivotIndex;
    // }
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
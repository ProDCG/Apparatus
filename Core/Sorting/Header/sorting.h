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
    void quicksort(T& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);

            quicksort(arr, low, pi - 1);
            quicksort(arr, pi + 1, high);
        }
    }

    template<typename T>
    int partition(T& arr, int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
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
                // std::swap(&arr[min_idx], &arr[i]);
                swap(&arr[min_idx], &arr[i]);
            }
        }
    }

    template<typename T>
    void swap(T *a, T *b) {
        T t = *a;
        *a = *b;
        *b = t;
    }
};

struct merge_sort_policy_t {
    template <typename T>
    void operator()(T& arr) {
        // sort
    }
};

struct bogo_sort_policy_t {
    template <typename T>
    void operator()(T& arr) {
        while (!isSorted(arr)) {
            shuffle(arr);
        }
    }

    template <typename T>
    void shuffle(T& arr) {
        for (int i = 0; i < arr.size(); i++) {
            swap(arr[i], arr[std::rand() % arr.size()]);
        }
    }

    template <typename T>
    bool isSorted(T& arr) {
        int n = arr.size();
        while (--n > 0) {
            if (arr[n] < arr[n - 1]) {
                return false;
            }
        }
        return true;
    }

    template <typename T>
    void swap(T *a, T *b) {
        T t = *a;
        *a = *b;
        *b = t;
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
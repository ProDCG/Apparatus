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

struct quick_sort_recursive_policy_t {
    template <typename T>
    void operator()(T& arr) {
        quicksortRecursive(arr, 0, arr.size() - 1);
    }

    template<typename T>
    void quicksortRecursive(T& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);

            quicksortRecursive(arr, low, pi - 1);
            quicksortRecursive(arr, pi + 1, high);
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

struct quick_sort_iterative_policy_t {
    template <typename T>
    void operator()(T& arr) {
        quicksortIterative(arr, 0, arr.size() - 1);
    }

    void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* This function is same in both iterative and recursive*/
template <typename T>
int partition(T& arr, int l, int h)
{
    int x = arr[h];
    int i = (l - 1);
 
    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= x) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}
 
/* A[] --> Array to be sorted,
l --> Starting index,
h --> Ending index */
template <typename T>
void quickSortIterative(T& arr, int l, int h)
{
    // Create an auxiliary stack
    int stack[h - l + 1];
 
    // initialize top of stack
    int top = -1;
 
    // push initial values of l and h to stack
    stack[++top] = l;
    stack[++top] = h;
 
    // Keep popping from stack while is not empty
    while (top >= 0) {
        // Pop h and l
        h = stack[top--];
        l = stack[top--];
 
        // Set pivot element at its correct position
        // in sorted array
        int p = partition(arr, l, h);
 
        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
 
        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
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

    void swap(int *a, int *b) {
        int t = *a;
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
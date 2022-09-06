#ifndef SORTING_H
#define SORTING_H

template <typename Policy, typename T> 
void sort(T& arr) {
    Policy p;

    p(arr);
}

#endif
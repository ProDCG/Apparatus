#ifndef NUMERICAL_H
#define NUMERICAL_H

#include <math.h>

namespace numerical {
    bool isWilsonPrime() {
        
    }

    bool isPrimeNumber() {

    }

    bool isEven() {

    }

    bool isOdd() {

    }

    template <typename T>
    bool isWhole(T num) {
        return (std:floor(num) == num);
    }

    template <typename T>
    bool isComposite(T num) {
        // call !isPrime(), since composite is not a prime number.
    }
}

/*
isPrimeNumber
isWilsonPrime
isEven
isOdd
isWhole
isComposite
*/

#endif
Apparatus is a performance focused and efficient math library with a C++ backend. The library specializes in linear algebra, number theory, and basic arithmetic. A coming feature will allow to use the JNI, so that the library can give you the C++ performance speeds in other languages.



An example use case of declaring a vector using Apparatus:
```cpp
#include <vector_in.hpp>

// Declare a vector of type double and length 3
Vector<double, 3> vec{1, 2, 3};
```


Custom types allow for strong readability and flexibility when declaraing vectors
```cpp
#include <vector_in.hpp>

// Use of custom type, defaults to double, or defines the type based
// on the value passed into the parameter.

app::vec3 camera = vec3(1.0);
```
Another strong use case that this language gives you is access to a wide variety of sorting algorithms.
```cpp
#include <sorting.h>

// Use the insertion sorting algorithm, will automatically modify the array
sort<insertion_sort_policy_t>(/*reference to an array*/);
```


Some of these possible sorting algorithms are:
`
insertion_sort_policy_t
quick_sort_iterative_t
bogo_sort_t
`


There are more features to come, along with matrix multiplication, stressen algorithm implementation, and more useful utilities to speed up performance.
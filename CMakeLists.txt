cmake_minimum_required(VERSION 3.27)
project(Apparatus)

set(CMAKE_CXX_STANDARD 14)

include_directories(Core/LinearAlgebra/Matrix)
include_directories(Core/LinearAlgebra/Vector)
include_directories(Library)
include_directories(Testing/SubfolderTest)

add_executable(Apparatus
        Core/LinearAlgebra/Matrix/matrix_in.hpp
        Core/LinearAlgebra/Matrix/matrix_in_test.cpp
        Core/LinearAlgebra/Matrix/matrix_in_typedef.hpp
        Core/LinearAlgebra/Vector/vector_in.hpp
        Core/LinearAlgebra/Vector/vector_in_test.cpp
        Core/LinearAlgebra/Vector/vector_in_typedef.hpp
        Examples/MatrixDemo.cpp
        Examples/MatrixDemo2.cpp
        Examples/SortingDemo.cpp
        Library/sorting.h
        Testing/SubfolderTest/funny.cpp
        Testing/SubfolderTest/mat3.cpp
        Testing/SubfolderTest/mat3.h
        Testing/SubfolderTest/mat3_test.cpp
        Testing/SubfolderTest/mat4.cpp
        Testing/SubfolderTest/mat4.h
        Testing/SubfolderTest/vec3.cpp
        Testing/SubfolderTest/vec3.h
        Testing/SubfolderTest/vec4.cpp
        Testing/SubfolderTest/vec4.h
        Test.cpp
)

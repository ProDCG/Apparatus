cmake_minimum_required(VERSION 3.27)
project(Apparatus)

set(CMAKE_CXX_STANDARD 11)

add_executable(
        Exec
        Test.cpp
        vec3.hpp
        vec3.inl
        vec2.hpp
        vec2.inl
)

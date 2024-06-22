cmake_minimum_required(VERSION 3.27)
project(Apparatus)

set(CMAKE_CXX_STANDARD 11)

add_executable(
        Exec
#        testing/linalg/VecTest.cpp
        linalg/vec3.hpp
        linalg/vec3.inl
        linalg/vec2.hpp
        linalg/vec2.inl
        pathfinding/Node.hpp
        pathfinding/Node.inl
        pathfinding/AStar.hpp
        pathfinding/AStar.inl
        pathfinding/Grid.hpp
        pathfinding/Grid.inl
        testing/pathfinding/PathCreationTest.cpp
        #        testing/linalg/VecTest.cpp
)

cmake_minimum_required(VERSION 3.25)
project(Root 
    LANGUAGES CXX
)

project(LeetCode
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Root 
    main.cpp
    point.cpp
    point.h
)
add_executable(LeetCode
    leetcode.cpp
)


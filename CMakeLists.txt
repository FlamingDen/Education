cmake_minimum_required(VERSION 3.25)
project(Main 
    LANGUAGES CXX
)

project(LeetCode
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Main 
    main.cpp
    point.cpp
    point.h
)
add_executable(LeetCode
    leetcode.cpp
    timer.cpp
    timer.h
    show.h
)


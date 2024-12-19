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
    utils/timer.cpp
    utils/timer.h
)
add_executable(LeetCode
    leetcode.cpp
    utils/timer.cpp
    utils/timer.h
    utils/show.h
)

target_include_directories(Main INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
)

target_include_directories(Main PRIVATE
    utils
)

target_include_directories(LeetCode INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
)

target_include_directories(LeetCode PRIVATE
    utils
)
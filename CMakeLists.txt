cmake_minimum_required(VERSION 3.25)
project(Main 
    LANGUAGES CXX
)

project(LeetCode_100
    LANGUAGES CXX
)

project(LeetCode_200
    LANGUAGES CXX
)

project(LeetCode_300
    LANGUAGES CXX
)

project(DailyTasksLeetcode
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
    utils/show.h
    algo/DSU.hpp
    algo/DSU.cpp
    algo/Trie.hpp
    algo/Trie.cpp
)
add_executable(LeetCode_100
    leetcode_100.cpp
    utils/ForLeetcode.h
    utils/ForLeetcode.cpp
    utils/timer.cpp
    utils/timer.h
    utils/show.h
    utils/Tree.h
    utils/Tree.cpp
    utils/ListNode.h
    utils/ListNode.cpp
)

add_executable(LeetCode_200
    leetcode_200.cpp
    utils/ForLeetcode.h
    utils/ForLeetcode.cpp
    utils/timer.cpp
    utils/timer.h
    utils/show.h
    utils/Tree.h
    utils/Tree.cpp
    utils/ListNode.h
    utils/ListNode.cpp
)

add_executable(LeetCode_300
    leetcode_300.cpp
    utils/ForLeetcode.h
    utils/ForLeetcode.cpp
    utils/timer.cpp
    utils/timer.h
    utils/show.h
    utils/Tree.h
    utils/Tree.cpp
    utils/ListNode.h
    utils/ListNode.cpp
)

add_executable(DailyTasksLeetcode
    dailytasks.cpp
    utils/ForLeetcode.h
    utils/ForLeetcode.cpp
    utils/timer.cpp
    utils/timer.h
    utils/show.h
    utils/Tree.h
    utils/Tree.cpp
    utils/ListNode.h
    utils/ListNode.cpp
)
#==================================================
target_include_directories(Main INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
    ${CMAKE_CURRENT_SOURCE_DIR}/algo
)

target_include_directories(Main PRIVATE
    utils
    algo
)
#==================================================
target_include_directories(LeetCode_100 INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
)

target_include_directories(LeetCode_100 PRIVATE
    utils
)

#==================================================
target_include_directories(LeetCode_200 INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
)

target_include_directories(LeetCode_200 PRIVATE
    utils
)

#==================================================
target_include_directories(LeetCode_300 INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
)

target_include_directories(LeetCode_300 PRIVATE
    utils
)

#==================================================
target_include_directories(DailyTasksLeetcode INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
)

target_include_directories(DailyTasksLeetcode PRIVATE
    utils
)
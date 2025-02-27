cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#==================================================
project(Main 
    LANGUAGES CXX
)

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
    algo/Sorting.hpp
    algo/Sorting.cpp
)

target_include_directories(Main INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
    ${CMAKE_CURRENT_SOURCE_DIR}/algo
)

target_include_directories(Main PRIVATE
    utils
    algo
)

#==================================================
project(LeetCode_100
    LANGUAGES CXX
)

add_executable(LeetCode_100
    leetcode_/leetcode_100.cpp
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

target_include_directories(LeetCode_100 INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
    ${CMAKE_CURRENT_SOURCE_DIR}/leetcode_
)

target_include_directories(LeetCode_100 PRIVATE
    utils
    leetcode_
)

#==================================================
project(LeetCode_200
    LANGUAGES CXX
)

add_executable(LeetCode_200
    leetcode_/leetcode_200.cpp
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

target_include_directories(LeetCode_200 INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
    ${CMAKE_CURRENT_SOURCE_DIR}/leetcode_
)

target_include_directories(LeetCode_200 PRIVATE
    utils
    leetcode_
)

#==================================================
project(LeetCode_300
    LANGUAGES CXX
)

add_executable(LeetCode_300
    leetcode_/leetcode_300.cpp
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

target_include_directories(LeetCode_300 INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
    ${CMAKE_CURRENT_SOURCE_DIR}/leetcode_
)

target_include_directories(LeetCode_300 PRIVATE
    utils
    leetcode_
)

#==================================================
project(LeetCode_400
    LANGUAGES CXX
)

add_executable(LeetCode_400
    leetcode_/leetcode_400.cpp
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

target_include_directories(LeetCode_400 INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
    ${CMAKE_CURRENT_SOURCE_DIR}/leetcode_
)

target_include_directories(LeetCode_400 PRIVATE
    utils
    leetcode_
)

#==================================================
project(DailyTasksLeetcode
    LANGUAGES CXX
)

add_executable(DailyTasksLeetcode
    leetcode_/dailytasks.cpp
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

target_include_directories(DailyTasksLeetcode INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
    ${CMAKE_CURRENT_SOURCE_DIR}/leetcode_
)

target_include_directories(DailyTasksLeetcode PRIVATE
    utils
    leetcode_
)

#==================================================
project(LeetCode_500
    LANGUAGES CXX
)

add_executable(LeetCode_500
    leetcode_/leetcode_500.cpp
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

target_include_directories(LeetCode_500 INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
    ${CMAKE_CURRENT_SOURCE_DIR}/leetcode_
)

target_include_directories(LeetCode_500 PRIVATE
    utils
    leetcode_
)
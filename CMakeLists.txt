cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LeetCodeCommonHeaders
    utils/ForLeetcode.h
    utils/timer.h
    utils/show.h
    utils/Tree.h
    utils/ListNode.h
)

set(LeetCodeCommonSources
    utils/ForLeetcode.cpp
    utils/timer.cpp
    utils/Tree.cpp
    utils/ListNode.cpp
)

project(Education  
    LANGUAGES CXX
)

set(This Education)

#==================================================
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
add_executable(LeetCode_100
    leetcode_/leetcode_100.cpp
    ${LeetCodeCommonHeaders}
    ${LeetCodeCommonSources}
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
add_executable(LeetCode_200
    leetcode_/leetcode_200.cpp
    ${LeetCodeCommonHeaders}
    ${LeetCodeCommonSources}
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
add_executable(LeetCode_300
    leetcode_/leetcode_300.cpp
    ${LeetCodeCommonHeaders}
    ${LeetCodeCommonSources}
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
add_executable(LeetCode_400
    leetcode_/leetcode_400.cpp
    ${LeetCodeCommonHeaders}
    ${LeetCodeCommonSources}
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
add_executable(DailyTasksLeetcode
    leetcode_/dailytasks.cpp
    ${LeetCodeCommonHeaders}
    ${LeetCodeCommonSources}
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
add_executable(LeetCode_500
    leetcode_/leetcode_500.cpp
    ${LeetCodeCommonHeaders}
    ${LeetCodeCommonSources}
)

target_include_directories(LeetCode_500 INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
    ${CMAKE_CURRENT_SOURCE_DIR}/leetcode_
)

target_include_directories(LeetCode_500 PRIVATE
    utils
    leetcode_
)
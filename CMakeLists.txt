cmake_minimum_required(VERSION 3.25)
project(Education LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(fmt CONFIG REQUIRED)

# Общие файлы
set(LeetCodeCommonHeaders
    utils/ForLeetcode.h
    utils/show.h
    utils/Tree.h
    utils/ListNode.h
    utils/TimeGuard.hpp
)

set(LeetCodeCommonSources
    utils/ForLeetcode.cpp
    utils/Tree.cpp
    utils/ListNode.cpp
    utils/TimeGuard.cpp
)

# Функция для создания цели с fmt
function(add_leetcode_target TARGET_NAME SOURCE_FILE)
    add_executable(${TARGET_NAME}
        ${SOURCE_FILE}
        ${LeetCodeCommonHeaders}
        ${LeetCodeCommonSources}
        ${ARGN}  # Дополнительные файлы, все остальные аргументы (3-й, 4-й, 5-й и т.д.)
    )
    target_include_directories(${TARGET_NAME} PRIVATE utils leetcode_ algo)
    target_link_libraries(${TARGET_NAME} PRIVATE fmt::fmt)
endfunction()

# Создаем цели
add_leetcode_target(Main main.cpp 
    algo/DSU.cpp algo/DSU.hpp algo/Trie.hpp algo/Trie.cpp 
    algo/Sorting.hpp algo/Sorting.cpp
)

add_leetcode_target(LeetCode_100 leetcode_/leetcode_100.cpp)
add_leetcode_target(LeetCode_200 leetcode_/leetcode_200.cpp)
add_leetcode_target(LeetCode_300 leetcode_/leetcode_300.cpp)
add_leetcode_target(LeetCode_400 leetcode_/leetcode_400.cpp)
add_leetcode_target(LeetCode_500 leetcode_/leetcode_500.cpp)
add_leetcode_target(LeetCode_700 leetcode_/leetcode_700.cpp)
add_leetcode_target(DailyTasksLeetcode leetcode_/dailytasks.cpp algo/DSU.cpp algo/DSU.hpp)
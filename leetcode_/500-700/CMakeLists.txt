# leetcode_/500-700/CMakeLists.txt
cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(LeetCode_700 LANGUAGES CXX)
set(This LeetCode_700)

# Получаем путь к корневой директории (поднимаемся на два уровня вверх)
get_filename_component(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../ ABSOLUTE)

# Создаем списки с абсолютными путями
set(COMMON_HEADERS_ABS)
foreach(header ${LeetCodeCommonHeaders})
    list(APPEND COMMON_HEADERS_ABS ${ROOT_DIR}/${header})
endforeach()

set(COMMON_SOURCES_ABS)
foreach(source ${LeetCodeCommonSources})
    list(APPEND COMMON_SOURCES_ABS ${ROOT_DIR}/${source})
endforeach()

add_executable(${This}
    leetcode_700.cpp
    ${COMMON_HEADERS_ABS}
    ${COMMON_SOURCES_ABS}
)

target_include_directories(${This} PRIVATE
    ${ROOT_DIR}/utils
)
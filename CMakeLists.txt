cmake_minimum_required(VERSION 3.20)
project(dijkstra_cpp CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(pathfinding STATIC
    src/graph.cpp
    src/dijkstra.cpp
    src/a_star.cpp
    src/pathfinding_utils.cpp
)
target_include_directories(pathfinding PUBLIC include)

add_library(vec2 STATIC
    src/vec2.cpp
)
target_include_directories(vec2 PUBLIC include)

add_executable(dijkstra_app src/main_dijkstra.cpp)
target_link_libraries(dijkstra_app PRIVATE pathfinding)

add_executable(astar_app src/main_astar.cpp)
target_link_libraries(astar_app PRIVATE pathfinding vec2)

add_executable(misc_app src/main_misc.cpp)
target_link_libraries(misc_app PRIVATE pathfinding vec2)

enable_testing()
find_package(GTest CONFIG REQUIRED)

add_executable(dijkstra_tests tests/test_dijkstra.cpp)
target_link_libraries(dijkstra_tests PRIVATE pathfinding GTest::gtest GTest::gtest_main)

add_test(NAME dijkstra_tests COMMAND dijkstra_tests)

add_executable(vec2_tests tests/test_vec2.cpp)
target_link_libraries(vec2_tests PRIVATE vec2 GTest::gtest GTest::gtest_main)

add_test(NAME vec2_tests COMMAND vec2_tests)
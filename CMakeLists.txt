cmake_minimum_required(VERSION 3.20)
project(dijkstra_cpp CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(dijkstra STATIC
    src/graph.cpp
    src/dijkstra.cpp
)

target_include_directories(dijkstra PUBLIC include)

add_executable(dijkstra_app src/main.cpp)
target_link_libraries(dijkstra_app PRIVATE dijkstra)

enable_testing()
find_package(GTest CONFIG REQUIRED)

add_executable(dijkstra_tests tests/test_dijkstra.cpp)
target_link_libraries(dijkstra_tests PRIVATE dijkstra GTest::gtest GTest::gtest_main)

add_test(NAME dijkstra_tests COMMAND dijkstra_tests)
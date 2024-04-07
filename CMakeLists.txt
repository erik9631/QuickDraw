cmake_minimum_required(VERSION 3.27)
project(QuickDraw)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(libs/glm)
add_subdirectory(libs/catch2)
add_subdirectory(src)

add_subdirectory(test)

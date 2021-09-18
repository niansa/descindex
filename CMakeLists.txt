cmake_minimum_required(VERSION 3.5)

project(descindex LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(descindex src/main.cpp)

target_link_libraries(descindex PRIVATE fmt)

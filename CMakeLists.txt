cmake_minimum_required(VERSION 3.16)
project(ProphecyEngine)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)

add_subdirectory(Prophecy)
add_subdirectory(Client)

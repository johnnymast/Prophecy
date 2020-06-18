cmake_minimum_required(VERSION 3.16)
project(ProphecyEngine)

set(CMAKE_BUILD_TYPE Debug)

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)

include_directories(Prophecy/Prophecy/vendor/spdlog/include Prophecy/Prophecy/vendor/glfw/include)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")



include_directories(Prophecy/Prophecy/src)

add_subdirectory(Prophecy)
add_subdirectory(Client)


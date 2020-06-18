cmake_minimum_required(VERSION 3.16)
project(Client)

set(CMAKE_CXX_STANDARD 17)

add_executable(Client src/Client.cpp)

target_link_libraries(${PROJECT_NAME} Prophecy )
cmake_minimum_required(VERSION 3.16)
project(Client)

set(CMAKE_CXX_STANDARD 17)


add_executable(Client main.cpp)

include_directories(${CMAKE_BINARY_DIR}/../Prophecy)

find_library(PROPHECY_LIBRARY NAMES Prophecy REQUIRED)

if(NOT PROPHECY_LIBRARY_FOUND) # Works with some other methods
    message(STATUS "Prophecy not found...")
else()
    message(STATUS "Prophecy was found in ${PROPHECY_LIBRARY}...")
endif()

target_link_libraries(${PROJECT_NAME} ${PROPHECY_LIBRARY} )
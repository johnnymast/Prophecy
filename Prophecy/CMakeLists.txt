cmake_minimum_required(VERSION 3.16)
project(Prophecy)

set(CMAKE_CXX_STANDARD 17)

add_library(Prophecy library.cpp library.h)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")


find_package(OpenGL REQUIRED)

if(NOT OpenGL_FOUND) # Works with some other methods
    message(STATUS "OpenGL not found...")
else()
    message(STATUS "OpenGL was found in ${OpenGL}...")
endif()



set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(vendor/glfw)

include_directories(${OPENGL_INCLUDE_DIR}  ${GLUT_INCLUDE_DIRS} ${GLFW3_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME} ${PROPHECY_LIBRARY} glwf glu32 opengl32 )
cmake_minimum_required(VERSION 3.16)
project(Prophecy)

set(CMAKE_CXX_STANDARD 17)

file(GLOB PROPHECY_SRC
        "Prophecy/src/Prophecy.h"
        "Prophecy/src/compiled.h"
        "Prophecy/src/Prophecy/Core/Application.h"
        "Prophecy/src/Prophecy/Core/Application.cpp"
        "Prophecy/src/Prophecy/Core/Log.h"
        "Prophecy/src/Prophecy/Core/Log.cpp"
        "Prophecy/src/Prophecy/Core/EntryPoint.h"
        "Prophecy/src/Prophecy/Core/Base.h"
        )



add_library(${PROJECT_NAME} ${PROPHECY_SRC} Prophecy/src/Platform/Windows/WindowsWindow.cpp Prophecy/src/Platform/Windows/WindowsWindow.h Prophecy/src/Prophecy/Core/Window.cpp Prophecy/src/Prophecy/Core/Window.h)


target_precompile_headers(Prophecy
        PUBLIC
        Prophecy/src/compiled.h
        PRIVATE
        <unordered_map>
        )

find_package(OpenGL REQUIRED)

if(NOT OpenGL_FOUND) # Works with some other methods
    message(STATUS "OpenGL not found...")
else()
    message(STATUS "OpenGL was found...")
endif()


set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(Prophecy/vendor/glfw)
add_subdirectory(Prophecy/vendor/spdlog)

include_directories(${OPENGL_INCLUDE_DIR}  ${GLUT_INCLUDE_DIRS} ${GLFW3_INCLUDE_DIR} ${CMAKE_SOURCE_DIR}/vendor/spdlog/include ${CMAKE_SOURCE_DIR}/vendor/glfw/include src/Prophecy)
target_link_libraries(${PROJECT_NAME} glfw ${GLFW_LIBRARIES} glu32 opengl32 spdlog::spdlog_header_only )
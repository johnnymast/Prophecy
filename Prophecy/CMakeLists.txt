cmake_minimum_required(VERSION 3.16)
project(Prophecy)

set(CMAKE_CXX_STANDARD 17)

file(GLOB PROPHECY_SRC
        "Prophecy/src/Prophecy.h"
        "Prophecy/src/compiled.h"
        "Prophecy/src/compiled.cpp"
        "Prophecy/src/Prophecy/Core/Application.h"
        "Prophecy/src/Prophecy/Core/Application.cpp"
        "Prophecy/src/Prophecy/Core/Log.h"
        "Prophecy/src/Prophecy/Core/Log.cpp"
        "Prophecy/src/Prophecy/Core/EntryPoint.h"
        "Prophecy/src/Prophecy/Core/Base.h"
        "Prophecy/src/Prophecy/Core/Layer.h"
        "Prophecy/src/Prophecy/Core/Layer.cpp"
        "Prophecy/src/Prophecy/Core/LayerStack.h"
        "Prophecy/src/Prophecy/Core/LayerStack.cpp"
        "Prophecy/src/Prophecy/Math/Vector2d.h"
        "Prophecy/src/Prophecy/Math/Vector2d.cpp"
        "Prophecy/src/Prophecy/Math/Vector3d.h"
        "Prophecy/src/Prophecy/Math/Vector3d.cpp"
        "Prophecy/src/Prophecy/Math/Matrix.h"
        "Prophecy/src/Prophecy/Math/Matrix.cpp"
        "Prophecy/src/Platform/Linux/Core/MacOSWindow.h"
        "Prophecy/src/Platform/Linux/Core/LinuxWindow.cpp"
        "Prophecy/src/Platform/Windows/Core/WindowsWindow.h"
        "Prophecy/src/Platform/Windows/Core/WindowsWindow.cpp"
        "Prophecy/src/Platform/MacOS/Core/MacOSWindow.h"
        "Prophecy/src/Platform/MacOS/Core/MacOSWindow.cpp"
        )



add_library(${PROJECT_NAME} ${PROPHECY_SRC} Prophecy/src/Platform/Windows/Core/WindowsWindow.cpp Prophecy/src/Platform/Windows/Core/WindowsWindow.h Prophecy/src/Prophecy/Core/Window.cpp Prophecy/src/Prophecy/Core/Window.h Prophecy/src/Prophecy/Event/Event.h)


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

if (WIN32 OR WIN64)
target_link_libraries(${PROJECT_NAME} glfw ${GLFW_LIBRARIES} glu32 opengl32 spdlog::spdlog_header_only )
else()
target_link_libraries(${PROJECT_NAME} glfw ${GLFW_LIBRARIES} ${EXTRA_PROPHECY_LIBS} spdlog::spdlog_header_only )
endif()

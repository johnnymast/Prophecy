project(Prophecy_tests)
set(CMAKE_CXX_STANDARD 17)

include_directories(../Prophecy/Prophecy/src)
add_subdirectory(vendor/gtest)
add_subdirectory(tests)

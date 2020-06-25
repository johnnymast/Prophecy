include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(../Prophecy/Prophecy/src)

add_executable(Prophecy_tests
        Core/LayerStack.cpp
        Math/Vector2dTest.cpp
        Math/Vector3dTest.cpp
        Math/MatrixTest.cpp
        )

target_link_libraries(Prophecy_tests gtest gtest_main)
target_link_libraries(Prophecy_tests Prophecy )

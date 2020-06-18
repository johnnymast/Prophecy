include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Prophecy_tests
        Core/LayerStack.cpp
        Math/Vector3D.cpp
        )

target_link_libraries(Prophecy_tests gtest gtest_main)
#target_link_libraries(Prophecy_tests gtest_test_main)
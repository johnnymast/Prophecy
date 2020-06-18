#include <gtest/gtest.h>


class LayerStackTest : public ::testing::Test {
    void SetUp( ) {
        std::cout << "SetUp" << std::endl;
    }

    void TearDown( ) {
        std::cout << "TearDown" << std::endl;
    }
};

TEST_F (LayerStackTest, UnitTest1) {
    EXPECT_EQ(1,1);
}

TEST_F (LayerStackTest, UnitTest2) {
    EXPECT_EQ(1,1);
}
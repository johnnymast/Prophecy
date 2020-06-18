#include <gtest/gtest.h>


class Vector3DTest : public ::testing::Test {
    void SetUp( ) {
        std::cout << "SetUp" << std::endl;
    }

    void TearDown( ) {
        std::cout << "TearDown" << std::endl;
    }
};

TEST_F (Vector3DTest, UnitTest1) {
    EXPECT_EQ(1,1);
}

TEST_F (Vector3DTest, UnitTest2) {
    EXPECT_EQ(1,1);
}
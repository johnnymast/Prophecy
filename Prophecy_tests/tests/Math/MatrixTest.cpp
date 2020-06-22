#include <gtest/gtest.h>
#include <prophecy.h>

class MatrixTest : public ::testing::Test {

public:
    void SetUp() {
        emptyMatrix = Prophecy::Matrix();
        testMatrix = Prophecy::Matrix(4, 4, 1);
    }


protected:
    Prophecy::Matrix emptyMatrix;
    Prophecy::Matrix testMatrix;
};

TEST_F (MatrixTest, default_values_are_numeric_null) {
    EXPECT_EQ(emptyMatrix.cols, 0);
    EXPECT_EQ(emptyMatrix.rows, 0);
    EXPECT_EQ(emptyMatrix.fill, 0);
}

TEST_F (MatrixTest, constructed_with_values_should_equal_constructed_values) {
     int fill = 4;
    const int rows = 2;
    const int cols = 3;
    int variants = 0;

    EXPECT_EQ(testMatrix.rows, 2);
    EXPECT_EQ(testMatrix.cols, 3);
    EXPECT_EQ(testMatrix.fill, 4);

    int **data = testMatrix.data;

   // fill = 3;
    for (int _r = 0; _r < testMatrix.rows; _r++) {
        for (int _c = 0; _c < testMatrix.cols; _c++) {
            std::cout << data[_r][_c] << " ";
            if (testMatrix.fill != fill) {
                variants++;
            }
        }
        std::cout << std::endl;
    }

    EXPECT_EQ(variants, 0);

}


#include <gtest/gtest.h>
#include <Prophecy.h>

//using Matrix = Prophecy::Matrix<int>;
//using Matrix = class Prophecy::Matrix<int>;

//template<> Prophecy::Matrix::createAndFill(int, int, int);

//template void Prophecy::Matrix<int>::createAndFill(int, int, int);
//void Prophecy::Matrix<int>::createAndFill(int,int,int);
// void Prophecy::Matrix<int>::createAndFill(int,int,int);
//extern Prophecy::Matrix<int>::Matrix(int,int);
//extern
extern template class Prophecy::Matrix<int>;

class MatrixTest : public ::testing::Test {

public:
    void SetUp() {
//        emptyMatrix();
//        filledMatrix(2,2);

//        vec2without = Prophecy::Vector2d();
//        vec2with = Prophecy::Vector2d(1, 2);
    }


protected:
    Prophecy::Matrix<int> emptyMatrix;
//    extern Prophecy::Matrix<int> filledMatrix;

};

TEST_F (MatrixTest, stack_cloned_matrices_should_be_an_new_instance_not_equal_but_same_values) {

//
//    Prophecy::Matrix<int> original(2, 3, 4);
//    Prophecy::Matrix clone = original.clone();
//
//    EXPECT_EQ(original.m_rows, clone.m_rows);
//    EXPECT_EQ(original.m_cols, clone.m_cols);
//    //EXPECT_EQ(original.fill, clone.fill);
//
//    clone.m_rows = 5;
//    clone.m_cols = 6;
//
//    EXPECT_EQ(original.m_rows, 2);
//    EXPECT_EQ(original.m_cols, 3);
//
//    EXPECT_EQ(clone.m_rows, 5);
//    EXPECT_EQ(clone.m_cols, 6);
}

TEST (MatrixTest, default_values_are_numeric_0) {
//    Prophecy::Matrix<int> emptyMatrix(4, 2);
//
//    EXPECT_EQ(emptyMatrix.m_cols, 0);
//    EXPECT_EQ(emptyMatrix.m_rows, 0);
//    EXPECT_EQ(emptyMatrix.m_fill, 0);
}

//TEST_F (MatrixTest, constructed_with_values_should_equal_constructed_values) {
////    int fill = 4;
////    const int rows = 2;
////    const int cols = 3;
////
////    EXPECT_EQ(testMatrix.rows, 4);
////    EXPECT_EQ(testMatrix.cols, 4);
////    EXPECT_EQ(testMatrix.fill, 1);
////
////    int **data = testMatrix.valueOf();
////
////    EXPECT_TRUE(isCorrectlyFilled(data, fill));
//}

//
//TEST_F(MatrixTest, valueat_should_return_the_correct_values) {
////    Prophecy::Matrix m = Prophecy::Matrix(2, 2, 3);
////    int row = 1, col = 2, val = 2;
////
////    m.setValue(row, col, val);
////
////    int expected = val;
////    int result = m.valueAt(row, col);
////
////
////    EXPECT_EQ(expected, result);
////    EXPECT_TRUE(false);
//}

//TEST_F(MatrixTest, setvalue_should_return_the_correct_values) {
////let m = new Prophecy.Math.Matrix(2, 2)
////let row = 1
////let col = 2
////let val = 2
////
////m.setValue(row, col, val)
////
////let expected = 2
////let result = m.valueAt(row, col)
////
////expect(result).toEqual(expected)
//}

//TEST_F(MatrixTest, setvalue_should_mark_matrix_dirty) {
//
//}


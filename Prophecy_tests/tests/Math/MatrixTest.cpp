#include <gtest/gtest.h>
#include <Prophecy/Math/Matrix.h>

#include <iostream>
#include <cstdlib>

template
class Prophecy::Matrix<int>;

extern std::ostream &operator<<(std::ostream &stream, const Prophecy::Matrix<int> &matrix);

class MatrixTest : public ::testing::Test {
protected:
    Prophecy::Matrix<int> m;
    Prophecy::Matrix<int> mEmpty;

public:
    void SetUp() override {
        m = Prophecy::Matrix<int>(2, 3);
    }
};

TEST_F (MatrixTest, default_values_are_numeric_0) {
    EXPECT_EQ(mEmpty.m_Rows, 0);
    EXPECT_EQ(mEmpty.m_Cols, 0);
    EXPECT_EQ(mEmpty.m_Fill, 0);
}

TEST_F (MatrixTest, default_value_for_fill_should_be_0) {
    Prophecy::Matrix<int> matrix = Prophecy::Matrix<int>(2, 3);

    EXPECT_EQ(matrix.m_Rows, 2);
    EXPECT_EQ(matrix.m_Cols, 3);
    EXPECT_EQ(matrix.m_Fill, 0);
}

TEST_F (MatrixTest, stack_cloned_matrices_should_be_an_new_instance_not_equal_but_same_values) {

    Prophecy::Matrix<int> original(2, 3, 4);
    Prophecy::Matrix clone = original.clone();

    EXPECT_EQ(original.m_Rows, clone.m_Rows);
    EXPECT_EQ(original.m_Cols, clone.m_Cols);
    EXPECT_EQ(original.m_Fill, clone.m_Fill);

    clone.m_Rows = 5;
    clone.m_Cols = 6;

    EXPECT_EQ(original.m_Rows, 2);
    EXPECT_EQ(original.m_Cols, 3);

    EXPECT_EQ(clone.m_Rows, 5);
    EXPECT_EQ(clone.m_Cols, 6);
}

TEST_F(MatrixTest, setvalue_should_return_the_correct_values) {
    Prophecy::Matrix<int> m = Prophecy::Matrix<int>(2, 2);
    unsigned int row = 1;
    unsigned int col = 2;
    unsigned int val = 2;

    m.setValue(row, col, val);

    unsigned int expected = 2;
    unsigned int result = m.valueAt(row, col);

    EXPECT_EQ(expected, result);
}

TEST_F(MatrixTest, valueat_should_return_the_correct_values) {
    Prophecy::Matrix<int> m = Prophecy::Matrix<int>(2, 2, 3);
    int row = 1, col = 2, val = 2;

    m.setValue(row, col, val);

    int expected = val;
    int result = m.valueAt(row, col);


    EXPECT_EQ(expected, result);
}

TEST_F(MatrixTest, valueat_should_return_minus_one_if_index_not_found) {
    Prophecy::Matrix<int> m = Prophecy::Matrix<int>(2, 2, 3);
    int row = 1, col = 2, val = 2;

    m.setValue(row, col, val);

    int expected = -1;
    int result = m.valueAt(3, 3);


    EXPECT_EQ(expected, result);
}

TEST_F(MatrixTest, setvalue_should_mark_matrix_dirty) {
    Prophecy::Matrix<int> m = Prophecy::Matrix<int>(2, 2);
    unsigned int row = 1, col = 2, val = 2;

    ASSERT_FALSE(m.isDirty());

    m.setValue(row, col, val);

    ASSERT_TRUE(m.isDirty());
}

// add

TEST_F(MatrixTest, add_should_work_with_a_integer) {
    Prophecy::Matrix<int> m = Prophecy::Matrix<int>(2, 2, 2);

    m.add(3);

    ASSERT_EQ(m.valueAt(0, 0), 5);
    ASSERT_EQ(m.valueAt(0, 1), 5);
    ASSERT_EQ(m.valueAt(1, 0), 5);
    ASSERT_EQ(m.valueAt(1, 1), 5);
}

TEST_F(MatrixTest, add_return_a_matrix_if_passed_a_integer) {
    Prophecy::Matrix<int> m = Prophecy::Matrix<int>(2, 2, 2);

    const auto ret = m.add(3);

    ASSERT_EQ(m.valueAt(0, 0), 5);
    ASSERT_EQ(m.valueAt(0, 1), 5);
    ASSERT_EQ(m.valueAt(1, 0), 5);
    ASSERT_EQ(m.valueAt(1, 1), 5);


    ASSERT_TRUE((typeid(ret) == typeid(Prophecy::Matrix<int>)));
}

TEST_F(MatrixTest, add_should_work_with_a_matrix) {
    Prophecy::Matrix<int> m = Prophecy::Matrix<int>(2, 2, 3);
    Prophecy::Matrix<int> m2 = Prophecy::Matrix<int>(2, 2, 9);

    m.add(m2);

    ASSERT_EQ(m.valueAt(0, 0), 12);
    ASSERT_EQ(m.valueAt(0, 1), 12);
    ASSERT_EQ(m.valueAt(1, 0), 12);
    ASSERT_EQ(m.valueAt(1, 1), 12);
}

TEST_F(MatrixTest, add_should_work_with_a_matrix_if_adding_matrix_is_smaller) {
    Prophecy::Matrix<int> m = Prophecy::Matrix<int>(2, 2, 3);
    Prophecy::Matrix<int> m2 = Prophecy::Matrix<int>(1, 2, 9);

    m.add(m2);

    ASSERT_EQ(m.valueAt(0, 0), 12);
    ASSERT_EQ(m.valueAt(0, 1), 12);
    ASSERT_EQ(m.valueAt(1, 0), 3);
    ASSERT_EQ(m.valueAt(1, 1), 3);
}

TEST_F(MatrixTest, add_should_work_with_a_matrix_if_adding_matrix_is_marger) {
    Prophecy::Matrix<int> m = Prophecy::Matrix<int>(2, 2, 3);
    Prophecy::Matrix<int> m2 = Prophecy::Matrix<int>(4, 4, 9);

    m.add(m2);

    ASSERT_EQ(m.valueAt(0, 0), 12);
    ASSERT_EQ(m.valueAt(0, 1), 12);
    ASSERT_EQ(m.valueAt(1, 0), 12);
    ASSERT_EQ(m.valueAt(1, 1), 12);
}


TEST_F(MatrixTest, add_return_a_matrix_if_passed_a_matrix) {
    Prophecy::Matrix<int> m = Prophecy::Matrix<int>(2, 2, 2);
    Prophecy::Matrix<int> m2 = Prophecy::Matrix<int>(2, 2, 3);

    const auto ret = m.add(m2);

    ASSERT_EQ(m.valueAt(0, 0), 5);
    ASSERT_EQ(m.valueAt(0, 1), 5);
    ASSERT_EQ(m.valueAt(1, 0), 5);
    ASSERT_EQ(m.valueAt(1, 1), 5);

    ASSERT_TRUE((typeid(ret) == typeid(Prophecy::Matrix<int>)));
}


// subtract

TEST_F(MatrixTest, subtract_should_work_with_a_integemultiply) {
    Prophecy::Matrix<int> m = Prophecy::Matrix<int>(2, 2, 2);

    m.subtract(3);

    ASSERT_EQ(m.valueAt(0, 0), -1);
    ASSERT_EQ(m.valueAt(0, 1), -1);
    ASSERT_EQ(m.valueAt(1, 0), -1);
    ASSERT_EQ(m.valueAt(1, 1), -1);
}

TEST_F(MatrixTest, subtract_return_a_matrix_if_passed_a_integer) {
    Prophecy::Matrix<int> m = Prophecy::Matrix<int>(2, 2, 10);

    const auto ret = m.subtract(4);

    ASSERT_EQ(m.valueAt(0, 0), 6);
    ASSERT_EQ(m.valueAt(0, 1), 6);
    ASSERT_EQ(m.valueAt(1, 0), 6);
    ASSERT_EQ(m.valueAt(1, 1), 6);


    ASSERT_TRUE((typeid(ret) == typeid(Prophecy::Matrix<int>)));
}

TEST_F(MatrixTest, subtract_should_work_with_a_matrix) {
    Prophecy::Matrix<int> m = Prophecy::Matrix<int>(2, 2, 3);
    Prophecy::Matrix<int> m2 = Prophecy::Matrix<int>(2, 2, 1);

    m.subtract(m2);

    ASSERT_EQ(m.valueAt(0, 0), 2);
    ASSERT_EQ(m.valueAt(0, 1), 2);
    ASSERT_EQ(m.valueAt(1, 0), 2);
    ASSERT_EQ(m.valueAt(1, 1), 2);
}

TEST_F(MatrixTest, subtract_should_work_with_a_matrix_if_adding_matrix_is_smaller) {
    Prophecy::Matrix<int> m = Prophecy::Matrix<int>(2, 2, 3);
    Prophecy::Matrix<int> m2 = Prophecy::Matrix<int>(1, 2, 2);

    m.subtract(m2);

    ASSERT_EQ(m.valueAt(0, 0), 1);
    ASSERT_EQ(m.valueAt(0, 1), 1);
    ASSERT_EQ(m.valueAt(1, 0), 3);
    ASSERT_EQ(m.valueAt(1, 1), 3);
}

TEST_F(MatrixTest, subtract_should_work_with_a_matrix_if_adding_matrix_is_marger) {
    Prophecy::Matrix<int> m = Prophecy::Matrix<int>(2, 2, 9);
    Prophecy::Matrix<int> m2 = Prophecy::Matrix<int>(4, 4, 4);

    m.subtract(m2);

    ASSERT_EQ(m.valueAt(0, 0), 5);
    ASSERT_EQ(m.valueAt(0, 1), 5);
    ASSERT_EQ(m.valueAt(1, 0), 5);
    ASSERT_EQ(m.valueAt(1, 1), 5);
}


TEST_F(MatrixTest, subtract_return_a_matrix_if_passed_a_matrix) {
    Prophecy::Matrix<int> m = Prophecy::Matrix<int>(2, 2, 2);
    Prophecy::Matrix<int> m2 = Prophecy::Matrix<int>(2, 2, 3);

    const auto ret = m.subtract(m2);

    ASSERT_EQ(m.valueAt(0, 0), -1);
    ASSERT_EQ(m.valueAt(0, 1), -1);
    ASSERT_EQ(m.valueAt(1, 0), -1);
    ASSERT_EQ(m.valueAt(1, 1), -1);

    ASSERT_TRUE((typeid(ret) == typeid(Prophecy::Matrix<int>)));
}

// multiply


TEST_F(MatrixTest, multiply_should_work_with_a_integer) {
    Prophecy::Matrix<int> m = Prophecy::Matrix<int>(2, 2, 2);

    m.multiply(3);

    ASSERT_EQ(m.valueAt(0, 0), 6);
    ASSERT_EQ(m.valueAt(0, 1), 6);
    ASSERT_EQ(m.valueAt(1, 0), 6);
    ASSERT_EQ(m.valueAt(1, 1), 6);
}

TEST_F(MatrixTest, multiply_return_a_matrix_if_passed_a_integer) {
    Prophecy::Matrix<int> m = Prophecy::Matrix<int>(2, 2, 10);

    const auto ret = m.multiply(4);

    ASSERT_EQ(m.valueAt(0, 0), 40);
    ASSERT_EQ(m.valueAt(0, 1), 40);
    ASSERT_EQ(m.valueAt(1, 0), 40);
    ASSERT_EQ(m.valueAt(1, 1), 40);


    ASSERT_TRUE((typeid(ret) == typeid(Prophecy::Matrix<int>)));
}

TEST_F(MatrixTest, multiply_should_work_with_a_matrix) {
    Prophecy::Matrix<int> m = Prophecy::Matrix<int>(2, 2, 3);
    Prophecy::Matrix<int> m2 = Prophecy::Matrix<int>(2, 2, 1);

    m.multiply(m2);

    ASSERT_EQ(m.valueAt(0, 0), 3);
    ASSERT_EQ(m.valueAt(0, 1), 3);
    ASSERT_EQ(m.valueAt(1, 0), 3);
    ASSERT_EQ(m.valueAt(1, 1), 3);
}

TEST_F(MatrixTest, multiply_should_work_with_a_matrix_if_adding_matrix_is_smaller) {
    Prophecy::Matrix<int> m = Prophecy::Matrix<int>(2, 2, 3);
    Prophecy::Matrix<int> m2 = Prophecy::Matrix<int>(1, 2, 2);

    m.multiply(m2);

    ASSERT_EQ(m.valueAt(0, 0), 6);
    ASSERT_EQ(m.valueAt(0, 1), 6);
    ASSERT_EQ(m.valueAt(1, 0), 3);
    ASSERT_EQ(m.valueAt(1, 1), 3);
}

TEST_F(MatrixTest, multiply_should_work_with_a_matrix_if_adding_matrix_is_marger) {
    Prophecy::Matrix<int> m = Prophecy::Matrix<int>(2, 2, 9);
    Prophecy::Matrix<int> m2 = Prophecy::Matrix<int>(4, 4, 4);

    m.multiply(m2);

    ASSERT_EQ(m.valueAt(0, 0), 36);
    ASSERT_EQ(m.valueAt(0, 1), 36);
    ASSERT_EQ(m.valueAt(1, 0), 36);
    ASSERT_EQ(m.valueAt(1, 1), 36);
}


TEST_F(MatrixTest, multiply_return_a_matrix_if_passed_a_matrix) {
    Prophecy::Matrix<int> m = Prophecy::Matrix<int>(2, 2, 2);
    Prophecy::Matrix<int> m2 = Prophecy::Matrix<int>(2, 2, 3);

    const auto ret = m.multiply(m2);

    ASSERT_EQ(m.valueAt(0, 0), 6);
    ASSERT_EQ(m.valueAt(0, 1), 6);
    ASSERT_EQ(m.valueAt(1, 0), 6);
    ASSERT_EQ(m.valueAt(1, 1), 6);

    ASSERT_TRUE((typeid(ret) == typeid(Prophecy::Matrix<int>)));
}


// Operators

//TEST_F(MatrixTest, left_shift_should_return_a_string_version_of_the_matrix) {
//    Prophecy::Matrix<int> m = Prophecy::Matrix<int>(2, 2, 66);
////
//
//    std::cout << m.ToString() << std::endl;
////    std::cout << m << std::endl;
//}


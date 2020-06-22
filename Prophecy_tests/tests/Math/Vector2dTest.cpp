#include <gtest/gtest.h>
#include <prophecy.h>

class Vector2dTest : public ::testing::Test {

public:
    void SetUp() {
        vec2without = Prophecy::Vector2d();
        vec2with = Prophecy::Vector2d(1, 2);
    }


protected:
    Prophecy::Vector2d vec2without;
    Prophecy::Vector2d vec2with;

};

TEST_F (Vector2dTest, default_values_are_numeric_null) {
    EXPECT_EQ(vec2without.x, 0);
    EXPECT_EQ(vec2without.y, 0);
}

TEST_F (Vector2dTest, constructed_with_values_should_equal_constructed_values) {
    EXPECT_EQ(vec2with.x, 1);
    EXPECT_EQ(vec2with.y, 2);
}

TEST_F (Vector2dTest, stack_cloned_vectors_should_be_an_new_instance_not_equal_but_same_values) {


    Prophecy::Vector3d original = Prophecy::Vector3d(2, 3, 4);
    Prophecy::Vector3d clone = original.clone();

    EXPECT_EQ(original.x, clone.x);
    EXPECT_EQ(original.y, clone.y);

    clone.x = 5;
    clone.y = 6;

    EXPECT_EQ(original.x, 2);
    EXPECT_EQ(original.y, 3);

    EXPECT_EQ(clone.x, 5);
    EXPECT_EQ(clone.y, 6);
}


TEST_F (Vector2dTest, add_should_work_with_vector2d_parameter) {

    vec2with.add(Prophecy::Vector2d(10, 11));

    EXPECT_EQ(vec2with.x, 11);
    EXPECT_EQ(vec2with.y, 13);
}

TEST_F (Vector2dTest, add_should_work_with_int_parameter) {

    vec2with.add(5);

    EXPECT_EQ(vec2with.x, 6);
    EXPECT_EQ(vec2with.y, 7);
}

TEST_F (Vector2dTest, add_should_return_it_self) {
    EXPECT_TRUE(false);
}


TEST_F (Vector2dTest, subtract_should_work_with_vector2d_parameter) {
    Prophecy::Vector2d same = vec2with.subtract(Prophecy::Vector2d(1, 1));

    EXPECT_EQ(vec2with.x, 0);
    EXPECT_EQ(vec2with.y, 1);

    EXPECT_EQ(same.x, 0);
    EXPECT_EQ(same.y, 1);
}

TEST_F (Vector2dTest, subtract_should_work_with_int_parameter) {
    Prophecy::Vector2d same = vec2with.subtract(3);

    EXPECT_EQ(vec2with.x, -2);
    EXPECT_EQ(vec2with.y, -1);

    EXPECT_EQ(same.x, -2);
    EXPECT_EQ(same.y, -1);
}

TEST_F (Vector2dTest, subtract_should_return_it_self) {
    EXPECT_TRUE(false);
}


TEST_F (Vector2dTest, multiply_should_work_with_vector2d_parameter) {
    Prophecy::Vector2d same = vec2with.multiply(Prophecy::Vector2d(2, 3));

    EXPECT_EQ(vec2with.x, 2);
    EXPECT_EQ(vec2with.y, 6);

    EXPECT_EQ(same.x, 2);
    EXPECT_EQ(same.y, 6);
}

TEST_F (Vector2dTest, multiply_should_work_with_int_parameter) {
    Prophecy::Vector2d same = vec2with.multiply(7);

    EXPECT_EQ(vec2with.x, 7);
    EXPECT_EQ(vec2with.y, 14);

    EXPECT_EQ(same.x, 7);
    EXPECT_EQ(same.y, 14);
}

TEST_F (Vector2dTest, multiply_should_return_it_self) {
    EXPECT_TRUE(false);
}

TEST_F (Vector2dTest, divide_should_work_with_vector2d_parameter) {
    Prophecy::Vector2d v1 = Prophecy::Vector2d(8, 8);
    Prophecy::Vector2d v2 = Prophecy::Vector2d(2, 2);

    v1.divide(v2);


    EXPECT_EQ(v1.x, 4);
    EXPECT_EQ(v1.y, 4);
}

TEST_F (Vector2dTest, divide_should_work_with_int_parameter) {
    Prophecy::Vector2d v1 = Prophecy::Vector2d(9, 9);
    Prophecy::Vector2d v2 = Prophecy::Vector2d(2, 2);

    v1.divide(3);


    EXPECT_EQ(v1.x, 3);
    EXPECT_EQ(v1.y, 3);
}

TEST_F (Vector2dTest, magnitude_should_return_the_correct_value) {
    Prophecy::Vector2d vect = Prophecy::Vector2d(6, 3);
    double magnitude = vect.magnitude();

    EXPECT_EQ(magnitude, 6.708203932499369);
}

TEST_F (Vector2dTest, distanceto_should_return_the_correct_value) {
    Prophecy::Vector2d v1 = Prophecy::Vector2d(6, 3);
    Prophecy::Vector2d v2 = Prophecy::Vector2d(10, 12);

    double distance = v1.distanceTo(v2);

    EXPECT_EQ(distance, 9.848857801796104);
}

TEST_F (Vector2dTest, normalize_should_return_a_new_vector3d) {
    Prophecy::Vector2d v1 = Prophecy::Vector2d(3, 1);

    Prophecy::Vector2d result = v1.normalize();

    EXPECT_EQ(v1.x, 3);
    EXPECT_EQ(v1.y, 1);

    EXPECT_EQ(result.x, 0.9486832980505138);
    EXPECT_EQ(result.y, 0.31622776601683794);
}

TEST_F (Vector2dTest, getx_should_return_the_correct_value) {
    Prophecy::Vector2d v1 = Prophecy::Vector2d(3, 1);
    EXPECT_EQ(v1.getX(), 3);
}

TEST_F (Vector2dTest, gety_should_return_the_correct_value) {
    Prophecy::Vector2d v1 = Prophecy::Vector2d(3, 5);
    EXPECT_EQ(v1.getY(), 5);
}
#include <gtest/gtest.h>
#include <prophecy.h>



//extern template<typename T>
//Prophecy::Vector3d Prophecy::Vector3d::add<T>(T n);

class Vector3dTest : public ::testing::Test {

public:
    void SetUp() {
        vec3without = Prophecy::Vector3d();
        vec3with = Prophecy::Vector3d(1, 2, 3);
    }


protected:
    Prophecy::Vector3d vec3without;
    Prophecy::Vector3d vec3with;

};

TEST_F (Vector3dTest, default_values_are_numeric_null) {
    EXPECT_EQ(vec3without.x, 0);
    EXPECT_EQ(vec3without.y, 0);
    EXPECT_EQ(vec3without.z, 0);
}

TEST_F (Vector3dTest, constructed_with_values_should_equal_constructed_values) {
    EXPECT_EQ(vec3with.x, 1);
    EXPECT_EQ(vec3with.y, 2);
    EXPECT_EQ(vec3with.z, 3);
}

TEST_F (Vector3dTest, stack_cloned_vectors_should_be_an_new_instance_not_equal_but_same_values) {


    Prophecy::Vector3d original = Prophecy::Vector3d(2, 3, 4);
    Prophecy::Vector3d clone = original.clone();

    EXPECT_EQ(original.x, clone.x);
    EXPECT_EQ(original.y, clone.y);
    EXPECT_EQ(original.z, clone.z);

    clone.x = 5;
    clone.y = 6;
    clone.z = 7;

    EXPECT_EQ(original.x, 2);
    EXPECT_EQ(original.y, 3);
    EXPECT_EQ(original.z, 4);
    EXPECT_EQ(clone.x, 5);
    EXPECT_EQ(clone.y, 6);
    EXPECT_EQ(clone.z, 7);
}


TEST_F (Vector3dTest, add_should_work_with_vector3d_parameter) {

    vec3with.add(Prophecy::Vector3d(10, 11, 15));

    EXPECT_EQ(vec3with.x, 11);
    EXPECT_EQ(vec3with.y, 13);
    EXPECT_EQ(vec3with.z, 18);
}

TEST_F (Vector3dTest, add_should_work_with_int_parameter) {

    vec3with.add(5);

    EXPECT_EQ(vec3with.x, 6);
    EXPECT_EQ(vec3with.y, 7);
    EXPECT_EQ(vec3with.z, 8);
}

TEST_F (Vector3dTest, add_should_return_it_self) {
    EXPECT_TRUE(false);
}


TEST_F (Vector3dTest, subtract_should_work_with_vector3d_parameter) {
    Prophecy::Vector3d same = vec3with.subtract(Prophecy::Vector3d(1, 1, 1));

    EXPECT_EQ(vec3with.x, 0);
    EXPECT_EQ(vec3with.y, 1);
    EXPECT_EQ(vec3with.z, 2);

    EXPECT_EQ(same.x, 0);
    EXPECT_EQ(same.y, 1);
    EXPECT_EQ(same.z, 2);
}

TEST_F (Vector3dTest, subtract_should_work_with_int_parameter) {
    Prophecy::Vector3d same = vec3with.subtract(3);

    EXPECT_EQ(vec3with.x, -2);
    EXPECT_EQ(vec3with.y, -1);
    EXPECT_EQ(vec3with.z, 0);

    EXPECT_EQ(same.x, -2);
    EXPECT_EQ(same.y, -1);
    EXPECT_EQ(same.z, 0);
}

TEST_F (Vector3dTest, subtract_should_return_it_self) {
    EXPECT_TRUE(false);
}


TEST_F (Vector3dTest, multiply_should_work_with_vector3d_parameter) {
    Prophecy::Vector3d same = vec3with.multiply(Prophecy::Vector3d(2, 3, 4));

    EXPECT_EQ(vec3with.x, 2);
    EXPECT_EQ(vec3with.y, 6);
    EXPECT_EQ(vec3with.z, 12);

    EXPECT_EQ(same.x, 2);
    EXPECT_EQ(same.y, 6);
    EXPECT_EQ(same.z, 12);
}

TEST_F (Vector3dTest, multiply_should_work_with_int_parameter) {
    Prophecy::Vector3d same = vec3with.multiply(7);

    EXPECT_EQ(vec3with.x, 7);
    EXPECT_EQ(vec3with.y, 14);
    EXPECT_EQ(vec3with.z, 21);

    EXPECT_EQ(same.x, 7);
    EXPECT_EQ(same.y, 14);
    EXPECT_EQ(same.z, 21);
}

TEST_F (Vector3dTest, multiply_should_return_it_self) {

//    Vector3d ret =  vec3with.add(5);
    EXPECT_TRUE(false);
}

TEST_F (Vector3dTest, divide_should_work_with_vector3d_parameter) {
    Prophecy::Vector3d v1 = Prophecy::Vector3d(8, 8, 8);
    Prophecy::Vector3d v2 = Prophecy::Vector3d(2, 2, 2);

    v1.divide(v2);


    EXPECT_EQ(v1.x, 4);
    EXPECT_EQ(v1.y, 4);
    EXPECT_EQ(v1.z, 4);
}

TEST_F (Vector3dTest, divide_should_work_with_int_parameter) {
    Prophecy::Vector3d v1 = Prophecy::Vector3d(9, 9, 9);
    Prophecy::Vector3d v2 = Prophecy::Vector3d(2, 2, 2);

    v1.divide(3);


    EXPECT_EQ(v1.x, 3);
    EXPECT_EQ(v1.y, 3);
    EXPECT_EQ(v1.z, 3);
}

TEST_F (Vector3dTest, magnitude_should_return_the_correct_value) {
    Prophecy::Vector3d vect = Prophecy::Vector3d(2, 3, 5);
    double magnitude = vect.magnitude();

    EXPECT_EQ(magnitude, 6.164414002968976);
}

TEST_F (Vector3dTest, distanceto_should_return_the_correct_value) {
    Prophecy::Vector3d v1 = Prophecy::Vector3d(6, 3, 2);
    Prophecy::Vector3d v2 = Prophecy::Vector3d(10, 12, 9);

    double distance = v1.distanceTo(v2);

    EXPECT_EQ(distance, 12.083045973594572);
}

TEST_F (Vector3dTest, normalize_should_return_a_new_vector3d) {
    Prophecy::Vector3d v1 = Prophecy::Vector3d(3, 1, 2);

    Prophecy::Vector3d result = v1.normalize();

    EXPECT_EQ(v1.x, 3);
    EXPECT_EQ(v1.y, 1);
    EXPECT_EQ(v1.z, 2);

    EXPECT_EQ(result.x, 0.8017837257372732);
    EXPECT_EQ(result.y, 0.2672612419124244);
    EXPECT_EQ(result.z, 0.5345224838248488);
}

TEST_F (Vector3dTest, getx_should_return_the_correct_value) {
    Prophecy::Vector3d v1 = Prophecy::Vector3d(3, 1, 2);
    EXPECT_EQ(v1.getX(), 3);
}

TEST_F (Vector3dTest, gety_should_return_the_correct_value) {
    Prophecy::Vector3d v1 = Prophecy::Vector3d(3, 5, 2);
    EXPECT_EQ(v1.getY(), 5);
}


TEST_F (Vector3dTest, getz_should_return_the_correct_value) {
    Prophecy::Vector3d v1 = Prophecy::Vector3d(3, 5, 9);
    EXPECT_EQ(v1.getZ(), 9);
}
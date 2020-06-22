#include "Prophecy/Math/Vector3d.h"
#include  <cmath>


namespace Prophecy {

    Vector3d::Vector3d(double x, double y, double z) : x(x), y(y), z(z) {};

    Vector3d Vector3d::clone() {
        return Vector3d(x, y, z);
    }

    template<>
    Vector3d Vector3d::add(Vector3d m) {
        x += m.x;
        y += m.y;
        z += m.z;
        return *this;
    }

    template<>
    Vector3d Vector3d::add(int m) {
        x += m;
        y += m;
        z += m;
        return *this;
    }


    template<>
    Vector3d Vector3d::subtract(Vector3d m) {
        x -= m.x;
        y -= m.y;
        z -= m.z;
        return *this;
    }

    template<>
    Vector3d Vector3d::subtract(int n) {
        x -= n;
        y -= n;
        z -= n;
        return *this;
    }

    template<>
    Vector3d Vector3d::multiply(Vector3d m) {
        x *= m.x;
        y *= m.y;
        z *= m.z;
        return *this;
    }

    template<>
    Vector3d Vector3d::multiply(int m) {
        x *= m;
        y *= m;
        z *= m;
        return *this;
    }

    template<>
    Vector3d Vector3d::divide(Vector3d m) {
        x /= m.x;
        y /= m.y;
        z /= m.z;
        return *this;
    }

    template<>
    Vector3d Vector3d::divide(int m) {
        x /= m;
        y /= m;
        z /= m;
        return *this;
    }

    double Vector3d::magnitude() {
        return std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2));
    }

    double Vector3d::distanceTo(Vector3d vec) {
        return subtract(vec).magnitude();
    }

    double Vector3d::dot(Vector3d m) {
        return (x * m.x + y * m.y + z * m.z);
    }

    Vector3d Vector3d::normalize() {
        double _x = x / magnitude();
        double _y = y / magnitude();
        double _z = z / magnitude();
        return Vector3d(_x, _y, _z);
    }

    double Vector3d::getX() {
        return x;
    }

    double Vector3d::getY() {
        return y;
    }

    double Vector3d::getZ() {
        return z;
    }
}
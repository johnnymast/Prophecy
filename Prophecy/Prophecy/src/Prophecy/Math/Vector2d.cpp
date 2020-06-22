#include "Prophecy/Math/Vector2d.h"
#include  <cmath>


namespace Prophecy {

    Vector2d::Vector2d(double x, double y) : x(x), y(y) {};

    Vector2d Vector2d::clone() {
        return Vector2d(x, y);
    }

    template<>
    Vector2d Vector2d::add(Vector2d m) {
        x += m.x;
        y += m.y;
        return *this;
    }

    template<>
    Vector2d Vector2d::add(int m) {
        x += m;
        y += m;
        return *this;
    }


    template<>
    Vector2d Vector2d::subtract(Vector2d m) {
        x -= m.x;
        y -= m.y;
        return *this;
    }

    template<>
    Vector2d Vector2d::subtract(int n) {
        x -= n;
        y -= n;
        return *this;
    }

    template<>
    Vector2d Vector2d::multiply(Vector2d m) {
        x *= m.x;
        y *= m.y;
        return *this;
    }

    template<>
    Vector2d Vector2d::multiply(int m) {
        x *= m;
        y *= m;
        return *this;
    }

    template<>
    Vector2d Vector2d::divide(Vector2d m) {
        x /= m.x;
        y /= m.y;
        return *this;
    }

    template<>
    Vector2d Vector2d::divide(int m) {
        x /= m;
        y /= m;
        return *this;
    }

    double Vector2d::magnitude() {
        return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
    }

    double Vector2d::distanceTo(Vector2d vec) {
        return subtract(vec).magnitude();
    }

    double Vector2d::dot(Vector2d m) {
        return (x * m.x + y * m.y);
    }

    Vector2d Vector2d::normalize() {
        double _x = x / magnitude();
        double _y = y / magnitude();
        return Vector2d(_x, _y);
    }

    double Vector2d::getX() {
        return x;
    }

    double Vector2d::getY() {
        return y;
    }
}
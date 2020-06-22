#pragma once

namespace Prophecy {
    class Vector2d {
    public:

        Vector2d() = default;
        Vector2d(double x, double y);
        virtual ~Vector2d() {}

        Vector2d clone();


        template<typename T>
        Vector2d add(T n);


        template<typename T>
        Vector2d subtract(T n);

        template<typename T>
        Vector2d multiply(T n);

        template<typename T>
        Vector2d divide(T n);

        double dot(Vector2d n);

        double magnitude();

        double distanceTo(Vector2d vec);

        Vector2d normalize();

        double getX();
        double getY();

        double x = 0;
        double y = 0;
        

    protected:

    };


}


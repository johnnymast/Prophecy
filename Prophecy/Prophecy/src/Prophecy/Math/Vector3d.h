#pragma once

namespace Prophecy {
    class Vector3d {
    public:

        Vector3d() = default;

        Vector3d(double x, double y, double z);

        virtual ~Vector3d() {}

        Vector3d clone();


        template<typename T>
        Vector3d add(T n);


        template<typename T>
        Vector3d subtract(T n);

        template<typename T>
        Vector3d multiply(T n);

        template<typename T>
        Vector3d divide(T n);

        double dot(Vector3d n);

        double magnitude();

        double distanceTo(Vector3d vec);

        Vector3d normalize();

        double getX();
        double getY();
        double getZ();

        double x = 0;
        double y = 0;
        double z = 0;


    protected:

    };


}


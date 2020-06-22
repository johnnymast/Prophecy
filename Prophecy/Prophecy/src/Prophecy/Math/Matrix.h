#pragma once

namespace Prophecy {


    class Matrix {
    public:
        Matrix() = default;

        Matrix(int rows, int cols, int fill = 0);

        virtual ~Matrix() {}

        Matrix clone();


        int rows = 0;
        int cols = 0;
        int fill = 0;
        int** data; // Tijdelijk hier voor debug
    protected:


    };
}
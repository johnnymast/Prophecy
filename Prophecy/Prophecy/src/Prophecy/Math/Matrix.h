#pragma once

#include <vector>
#include <list>

namespace Prophecy {

    template<typename T=int>
    class Matrix {
    private:
        void createAndFill(int m_rows, int m_cols, T m_fill);

        T **m_data;

    protected:
        bool dirty = false;

    public:
        int m_rows = 0;
        int m_cols = 0;
        T m_fill = 0;
        int m_size = 0;

        Matrix(int rows = 0, int cols = 0);

//        Matrix(int rows = 0, int cols = 0, T fill = 0);

        virtual ~Matrix();

        Matrix clone();

        // int **valueOf();

        // Matrix<T> setValue(int row, int col, int value);

        // int valueAt(int row, int col);


        void resize(int rows, int cols);


//        T &operator()(int rows, int cols);


    };
    extern Prophecy::Matrix<int>;

}
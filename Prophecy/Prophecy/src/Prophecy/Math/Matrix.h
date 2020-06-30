#pragma once

#include <vector>
#include <list>

namespace Prophecy {

    template<class T>
    class Matrix {
    private:
        T **m_Data;

    protected:
        bool m_Dirty = false;

    public:
        unsigned int m_Rows = 0;
        unsigned int m_Cols = 0;
        unsigned int m_Fill = 0;
        unsigned int m_Size = 0;

        Matrix();
        Matrix(unsigned int rows, unsigned int cols, unsigned int fill = 0);
        virtual ~Matrix();
        Matrix clone();
        bool isDirty() { return m_Dirty; };
        Matrix setValue(unsigned int row, unsigned int col, T value);
        T valueAt(unsigned int row, unsigned int col);

        Matrix add(T m);
        Matrix add(Matrix<T> m);
        Matrix subtract(T m);
        Matrix subtract(Matrix<T> m);
        Matrix multiply(T m);
        Matrix multiply(Matrix<T> m);
    };



//    template class Prophecy::Matrix<int>;
//    template class Prophecy::Matrix<float>;
//    template class Prophecy::Matrix<double>;

};


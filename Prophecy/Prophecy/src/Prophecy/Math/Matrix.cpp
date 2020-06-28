#include "Prophecy/Math/Matrix.h"

namespace Prophecy {


    template<typename T>
    Matrix<T>::Matrix(int rows, int cols) : m_rows(rows), m_cols(cols){
        std::cout << "COnstructed 2 args" << std::endl;

        m_size = (m_rows * m_cols);
        createAndFill(m_rows, m_cols);


    };

//    template<class T>
//    Matrix<T>::Matrix(int rows, int cols, T fill) : m_rows(rows), m_cols(cols), m_fill(fill) {
//        std::cout << "COnstructed 3 args" << std::endl;
//
//        m_size = (m_rows * m_cols);
//        createAndFill(m_rows, m_cols, m_fill);
//
//
//    };

    template<typename T>
    Matrix<T>::~Matrix() {
//        delete[] m_data;
    }


    // Recently added
//    template<class T>
//    T &Matrix<T>::operator()(int row, int col) {
//        return m_data[row][col];
//    }

    template<typename T>
    Matrix<T> Matrix<T>::clone() {
        return Matrix(m_rows, m_cols, m_fill);
    }

    template<typename T>
    void Matrix<T>::createAndFill(int rows, int cols, T fill) {
        if (m_size > 0) {
            m_data = new T *[rows];

            if (rows > 0 && cols > 0) {
                for (int y = 0; y < rows; y++) {
                    m_data[y] = new T[cols];
                    for (int x = 0; x < cols; x++) {
                        if (fill) {
                            m_data[y][x] = (T) fill;
                        } else
                            m_data[y][x] = 0x0;
                    }
                }
                m_rows = rows;
                m_cols = cols;
                m_fill = fill;
                m_size = (m_rows * m_cols);
            }
        }
    }

    template<typename T>
    void Matrix<T>::resize(int rows, int cols) {

        if (rows < 0 || cols < 0) {
            return;
        }

        T **_newData[rows][cols];

        for (int y = 0; y < rows; rows++) {
            _newData[y] = new T[cols];
            for (int x = 0; x < cols; x++) {
                _newData[y][x] = 0x0;
            }
        }

        /**
         * Copy the original data into the new data.
         */
        for (int y = 0; y < m_rows; m_rows++) {
            if (m_data[y]) {
                for (int x = 0; x < m_cols; x++) {
                    _newData[y][x] = &m_data[y][x];
                }
            }
        }

        delete[] m_data;


        m_data = _newData;
        m_rows = rows;
        m_cols = cols;
        m_size = (m_rows * m_cols);
    }
//    template <class T>
//    int **Matrix<T>::valueOf() {
//        return data;
//    }
//
//    template <class T>
//    Matrix<T> Matrix<T>::setValue(int row, int col, int value) {
//        data[row][col] = value;
//        dirty = true;
//        return *this;
//    }
}
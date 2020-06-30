#include "compiled.h"
#include "Prophecy/Math/Matrix.h"
#include <string>
#include <iostream>

namespace Prophecy {

    template<class T>
    Matrix<T>::Matrix(): m_Rows(0), m_Cols(0) {
        //
    }

    template<class T>
    inline Matrix<T>::Matrix(unsigned int rows, unsigned int cols, unsigned int fill) : m_Rows(rows), m_Cols(cols),
                                                                                        m_Fill(fill) {
        if (m_Rows * m_Cols > 0) {
            m_Data = new int *[rows];

            if (rows > 0 && cols > 0) {
                for (int y = 0; y < rows; y++) {
                    m_Data[y] = new int[cols];
                    for (int x = 0; x < cols; x++) {
                        if (fill) {
                            m_Data[y][x] = (T)fill;
                        } else
                            m_Data[y][x] = 0;
                    }
                }
                m_Rows = rows;
                m_Cols = cols;
                m_Fill = fill;
                m_Size = (m_Rows * m_Cols);
            }
        }
    }


    template<class T>
    Matrix<T>::~Matrix() {
        //   delete [] m_Data;
    }


    template<class T>
    Matrix<T> Matrix<T>::clone() {
        return Matrix(m_Rows, m_Cols, m_Fill);
    }

    template<class T>
    Matrix<T> Matrix<T>::setValue(unsigned int row, unsigned int col, T value) {
        m_Data[row][col] = value;
        m_Dirty = true;
        return *this;
    }

    template<class T>
    T Matrix<T>::valueAt(unsigned int row, unsigned int col) {
        if (row * col > m_Size) return -1;
        return m_Data[row][col];
    }

    template<class T>
    Matrix<T> Matrix<T>::add(T m) {
        for (int y = 0; y < m_Rows; y++) {
            for (int x = 0; x < m_Cols; x++) {
                m_Data[y][x] += (T)m;
            }
        }
        return *this;
    }

    template<class T>
    Matrix<T> Matrix<T>::add(Matrix<T> m) {
        for (int y = 0; y < m.m_Rows; y++) {
            if (y < m_Rows) {
                for (int x = 0; x < m.m_Cols; x++) {
                    if (x < m_Cols) {
                        m_Data[y][x] += m.m_Data[y][x];
                    }
                }
            }
        }
        return *this;
    }

    template<class T>
    Matrix<T> Matrix<T>::subtract(T m) {
        for (int y = 0; y < m_Rows; y++) {
            for (int x = 0; x < m_Cols; x++) {
                m_Data[y][x] -= (T)m;
            }
        }
        return *this;
    }

    template<class T>
    Matrix<T> Matrix<T>::subtract(Matrix<T> m) {
        for (int y = 0; y < m.m_Rows; y++) {
            if (y < m_Rows) {
                for (int x = 0; x < m.m_Cols; x++) {
                    if (x < m_Cols) {
                        m_Data[y][x] -= m.m_Data[y][x];
                    }
                }
            }
        }
        return *this;
    }

    template<class T>
    Matrix<T> Matrix<T>::multiply(T m) {
        for (int y = 0; y < m_Rows; y++) {
            for (int x = 0; x < m_Cols; x++) {
                m_Data[y][x] *= (T)m;
            }
        }
        return *this;
    }

    template<class T>
    Matrix<T> Matrix<T>::multiply(Matrix<T> m) {
        for (int y = 0; y < m.m_Rows; y++) {
            if (y < m_Rows) {
                for (int x = 0; x < m.m_Cols; x++) {
                    if (x < m_Cols) {
                        m_Data[y][x] *= m.m_Data[y][x];
                    }
                }
            }
        }
        return *this;
    }



//    template<class T>
//    std::string Matrix<T>::ToString() {
//        std::string ret;
//        for (int y = 0; y < m_Rows; y++) {
//            for (int x = 0; x < m_Cols; x++) {
////                ret.append<int>(1, m_Data[x][y]);
////                ret.append(9, 1);
//                ret += dynamic_cast<std::string>(&m_Data[x][y])
//
//
//                std::cout << (int)m_Data[y][x] << std::endl;
//
//                if (x < m_Cols) {
//                    ret += " ";
//                }
//            }
//            ret += "\n";
//        }
//        return ret;
//    }



//    template<class T>
//    std::string &Matrix<T>::operator<<(const Matrix<T> &matrix) {
//        return "ABCD";
//    }




//    }
//
//    void Matrix::createAndFill(int rows, int cols, unsigned int fill) {
//
//        if (m_size > 0) {
//            m_data = new int *[rows];
//
//            if (rows > 0 && cols > 0) {
//                for (int y = 0; y < rows; y++) {
//                    m_data[y] = new int[cols];
//                    for (int x = 0; x < cols; x++) {
//                        if (fill) {
//                            m_data[y][x] = fill;
//                        } else
//                            m_data[y][x] = 0x0;
//                    }
//                }
//                m_rows = rows;
//                m_cols = cols;
//                m_fill = fill;
//                m_size = (m_rows * m_cols);
//            }
//        }
//    }
//
//    void Matrix::resize(int rows, int cols) {
//
//        if (rows < 0 || cols < 0) {
//            return;
//        }
//
//        int **_newData[rows][cols];
//
//        for (int y = 0; y < rows; rows++) {
//            _newData[y] = new T[cols];
//            for (int x = 0; x < cols; x++) {
//                _newData[y][x] = 0x0;
//            }
//        }
//
//        /**
//         * Copy the original data into the new data.
//         */
//        for (int y = 0; y < m_rows; m_rows++) {
//            if (m_data[y]) {
//                for (int x = 0; x < m_cols; x++) {
//                    _newData[y][x] = &m_data[y][x];
//                }
//            }
//        }
//
//        delete[] m_data;
//
//
//        m_data = _newData;
//        m_rows = rows;
//        m_cols = cols;
//        m_size = (m_rows * m_cols);
////    }
//    template <class T>
//    T **Matrix<T>::valueOf() {
//        return data;
//    }
//


    template
    class Prophecy::Matrix<int>;

//    template<class T>
//    std::ostream &operator<<(std::ostream& stream, const Prophecy::Matrix<T>& matrix) {
//
//    };
}

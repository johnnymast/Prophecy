#include "Prophecy/Math/Matrix.h"

namespace Prophecy {

    Matrix::Matrix(int rows, int cols, int fill) : rows(rows), cols(cols), fill(fill) {
        data = new int *[rows];

        for (int y = 0; y < rows; y++) {
            data[y] = new int[cols];
            for (int x = 0; x < cols; x++) {
                data[y][x] = fill;
            }
        }
    };

//    Matrix Matrix::clone() {
//        return Matrix(rows, cols, fill);
//    }

    void dump() {
//        for (int _r = 0; _r < testMatrix.rows; _r++) {
//            for (int _c = 0; _c < testMatrix.cols; _c++) {
//                if (_c > 0 && _c < testMatrix.cols) {
//                    std::cout << "| " << _c
//                }
//                if (testMatrix.fill != fill) {
//                    variants++;
//                }
//            }
//        }
    }
}
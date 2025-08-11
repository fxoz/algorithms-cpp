//
// Created by Lynx on 2025-08-09.
//

#ifndef MATRIXMULT_H
#define MATRIXMULT_H
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

typedef std::vector<std::vector<int>> Matrix; // ROWS <cell, cell, ...>

inline void printMatrix(Matrix matrix) {
    int max = INT_MIN;
    for (const auto& row: matrix) {
        for (const int& i: row) {
            if (i>max) max = i;
        }
        std::cout << "\n";
    }

    for (const auto& row: matrix) {
        for (const int& i: row) {
            std::cout << std::setw(std::to_string(max).length()+1) << i;
        }
        std::cout << "\n";
    }
}

inline Matrix multiplyMatrices(Matrix matrixA, Matrix matrixB) {
    Matrix res;
    for (int i=0; i<matrixA.size(); i++) {
        std::vector<int> newRow;
        for (int j=0; j<matrixB[0].size(); j++) {
            int cell = 0;

            for (int k=0; k<matrixB.size(); k++) {
                //std::cout << "a[" << i << "]" << "[" << k << "]" << " * " << "b[" << k << "]" << "[" << j << "]\n";
                cell += matrixA[i][k] * matrixB[k][j];
            }

            newRow.emplace_back(cell);
        }
        res.emplace_back(newRow);
    }
    return res;
}

#endif //MATRIXMULT_H

//
// Created by Felix on 2025-08-11.
//

#ifndef BINOMIALKOEFFIZIENT_H
#define BINOMIALKOEFFIZIENT_H
#include "matrixmult.h"

inline int binomialKoeffizientRek(int n, int k) {
    // O(2^n)
    if (n==k || k==0) return 1;
    return binomialKoeffizientRek(n-1, k-1) + binomialKoeffizientRek(n-1, k);
}

inline int binomialKoeffizientIter(int N, int K) {
    // O(n*k)
    int sum = 1;

    Matrix matrix(N+1, std::vector<int>(K+1));

    for (int k = 0; k <= K; ++k) {
        for (int n = 0; n <= N; ++n) {
            if (n==k || k==0 || n==0) {
                matrix[n][k] = 1;
                continue;
            }

            matrix[n][k] = matrix[n-1][k-1] + matrix[n-1][k];
        }
    }

    printMatrix(matrix);

    return sum;
}

#endif //BINOMIALKOEFFIZIENT_H

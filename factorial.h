//
// Created by Felix on 2025-08-11.
//

#ifndef FACTORIAL_H
#define FACTORIAL_H

inline int factorialRek(int n) {
    return (n == 1 ? 1 : n*factorialRek(n-1));
}

inline int factorialIter(int n) {
    int fac = 1;
    for (int i=1; i<=n; i++) {
        fac = i*fac;
    }
    return fac;
}

#endif //FACTORIAL_H

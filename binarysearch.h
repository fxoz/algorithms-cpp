//
// Created by Felix on 2025-08-11.
//

#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H
#include <iostream>
#include <vector>

inline int binarySearch(std::vector<int> arr, int n) {
    // O(log n)
    int m = (arr.size()-1)/2;
    while (true) {
        std::cout << "m=" << m << "\n";
        if (arr[m] == n) return m;
        if (arr[m] > n) {
            m /= 2;
        }
        if (arr[m] < n) {
            m = (m + (arr.size()-1)) / 2;
        }
    }
}

#endif //BINARYSEARCH_H

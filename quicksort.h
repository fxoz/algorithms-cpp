//
// Created by Felix on 2025-08-11.
//

#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <iomanip>
#include <string>
#include <vector>

inline void printArray(std::vector<int> arr) {
    int max = INT_MIN;
    for (const auto& i : arr) if (i > max) max = i;
    for (const auto& i : arr) std::cout << std::setw(std::to_string(max).size()+1) << i;
    std::cout << "\n";
}

inline void swap(std::vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

inline int partition(std::vector<int> &arr, int l, int r) {
    int p = arr[r]; // element ganz rechts als pivot element wählen
    int i = l; // linker iterator
    int j = r-1; // rechter iterator, wir ignorieren das pivot elt.

    std::cout << "partition(l=" << l << ", r=" << r << ")\n";

    // wir vergleichen immer von "außen" nach "innen"
    // i und j sind immer ein Bereich und dürfen nie gleich sein oder sich "überschneiden"
    while (i < j) {
        while (i < j && arr[i] <= p) { // vergleiche linke schranke mit pivot
            std::cout << "arr[i]: " << arr[i] << " <= "  << p << " => i++\n";
            i++;
        }
        while (j > i && arr[j] > p) { // gehe so lange mit j nach links, bis p größer als arr[j]
            j--;
        }
        if (arr[i] > arr[j]) { // i & j not sorted
            swap(arr, i, j); // sort them
        }
        std::cout << "i= " << i << "; j=" << j << "\n";
    }

    if (arr[i] > p) { // i größer als pivot
        swap(arr, i, r); // tausche r und i
    } else {
        i = r; // ansonsten arbeiten wir später wieder mit dem elt. ganz rechts als pivot weiter
    }

    printArray(arr);
    std::cout << "pivot=" << i << "\n";
    return i;
}

inline void quicksort(std::vector<int>& arr, int l, int r) {
    std::cout << "quicksort(l=" << l << ", r=" << r << ")\n";
    if (l < r) {
        int m = partition(arr, l, r);
        quicksort(arr, l, m-1); // sortiere linken teil
        quicksort(arr, m+1, r);  // sortiere rechten teil
    }
}

#endif //QUICKSORT_H

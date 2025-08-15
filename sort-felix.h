//
// Created by Lynx on 2025-08-09.
//

#ifndef FELIXSORT_H
#define FELIXSORT_H
#include <iostream>

inline void felix_sort_v1(std::vector<int> nums) {
    // Find the next smallest unseen number, copy all its occurrences into the new array, repeat
    // Similar to selection sort? (also: strand sort)
    // not-in-place, comparison-based

    // Worst (all unique)   O(n^2)
    // Avg                  O(n^2)
    // Best (all same)      O(n)

    int n_iterations = 0;

    std::vector<int> nums_sorted;

    int continue_above = -1; // Don't skip any numbers aka. start at (-1)+1 = 0

    while (nums_sorted.size() != nums.size()) {
        int min = INT_MAX; // We're always trying to find the lowest number that we haven't checked yet
        int occurrences = 0;
        for (const int& n : nums) { // Go through original array
            if (n <= continue_above) continue; // ...skip the values we've already checked

            if (n == min) occurrences++; // While sorting, let's count how often the current number occurs, so we can add it *multiple* times later
            if (n < min) { // Find the smallest number
                min = n; // Current number we're working with in this iteration
                occurrences = 1; // We've seen this number for the first time
            }
            n_iterations++;
        }
        // We've gone through one iteration:

        for (int i=0; i<occurrences; i++) nums_sorted.emplace_back(min); // Add the current number as often as it occurred in the original array
        continue_above = min; // Skip anything <= the current number in the next iteration
    }

    for (const auto& n : nums_sorted) {
        std::cout << "Sorted! " << n << "\n";
    }
    std::cout << "iter_n=" << n_iterations << "\n";
}

void felix_sort_v2(std::vector<int> nums) {

}

#endif //FELIXSORT_H

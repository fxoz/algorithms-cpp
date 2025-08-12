#include <iostream>
#include <vector>
#include "quicksort.h"

int main() {
    //std::vector<int> arr = {23, 37, 49, 19, 38, 9, 12, 1, 4, 2, 1, 9, 19, 50};
    std::vector<int> arr = {14, 2, 5, 21, 7, 12, 1};

    quicksort(arr, 0, arr.size()-1);
    return 0;
}

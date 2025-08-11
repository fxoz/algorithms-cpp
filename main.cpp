#include <vector>
#include <limits.h>

#include "binarysearch.h"
#include "binomialkoeffizient.h"
#include "euros.h"
#include "factorial.h"
#include "felixsort.h"
#include "levenshtein.h"
#include "matrixmult.h"
#include "rucksack.h"


int main() {
    std::vector<int> arr{0, 2, 3, 4, 7, 8, 10, 20, 34, 41, 42, 239, 500, 23094, 34999, 394839};
    std::cout << binarySearch(arr, 2);
    return 0;
}

//
// Created by Lynx on 2025-08-10.
//

#ifndef RUCKSACK_H
#define RUCKSACK_H

inline void rucksackProblemSolve(const std::vector<std::pair<int, int>>& itemsValueWeight, int capacity) {
    // items<value, weight>, capacity of knapsack
    // I decided to use my Matrix class (a vector of vectors) / two-dimensional array, since most visualizations use tables.

    Matrix grid; // cols = capacity | rows = items | always including 0
    std::vector<int> emptyItemRow;
    emptyItemRow.assign(capacity+1, 0); // This is the first row. Without any items, our value is always 0.
    grid.emplace_back(emptyItemRow);

    int n_row = 1; // Let's continue with the rows with actual items
    for (const auto& [ itemValue, itemWeight ] : itemsValueWeight) {
        std::vector<int> row;
        int currentValue = 0;
        bool didAddItem = false;

        std::cout << "Item $" << itemValue << " | " << itemWeight << "kg\n";

        for (int cap=0; cap<=capacity; cap++) {
            // Options:
            // - use current cap of last row
            // - keep current value
            // - add value from (last row - weight) + itemValue
            // - just add current item

            std::vector<int> lastRow = grid[n_row-1];

            int backTrackedCapLastRow = 0; // last row - weight. We *can* be out of bounds, so this is why we will set this to 0, and only calculate the possible back-tracked value if we're *in* bounds
            if (cap - itemWeight >= 0) { // can we use back-tracked / last row's value?
                backTrackedCapLastRow = lastRow[cap - itemWeight]; // its value (position: last row, <itemWeight> columns 'left')
            }
            int backTrackedAdded = backTrackedCapLastRow + itemValue; // The value of our knapsack if we did decide to use this back-tracked option (which also adds the current item)
            int currentCapLastRow = lastRow[cap]; // The cell directly above us
            bool canAddItem = itemWeight<=cap && !didAddItem;

            // Let's always use the most efficient option. The second statement can override the value of the first one.

            if (currentValue < currentCapLastRow) {
                currentValue = currentCapLastRow;
            }

            if (canAddItem && currentValue < backTrackedAdded) {
                currentValue = backTrackedAdded;
            }

            std::cout << "  Possible:" << " bTPW: " << backTrackedAdded << " | cCLR: " << currentCapLastRow << "\n";

            row.emplace_back(currentValue);
        }
        grid.emplace_back(row);
        n_row++;
    }

    int finalValue = grid[itemsValueWeight.size()][capacity]; // most bottom right cell

    printMatrix(grid);
    std::cout << "FINAL: $" << finalValue << "\n";
}

#endif //RUCKSACK_H

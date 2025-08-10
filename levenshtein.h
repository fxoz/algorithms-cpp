//
// Created by Lynx on 2025-08-09.
//

#ifndef LEVENSHTEIN_H
#define LEVENSHTEIN_H
#include <algorithm>
#include <string>

#include "matrixmult.h"

inline int levenshteinDistanz(std::string textA, std::string textB) {
    Matrix d;
    std::vector<int> defaultRow;
    defaultRow.assign(textB.size()+1, 0);
    d.assign(textA.size()+1, defaultRow);

    for (int i=1; i<=textA.size(); i++) {
        d[i][0] = i;
    }

    for (int j=1; j<=textB.size(); j++) {
        d[0][j] = j;
    }

    for (int j=1; j<=textB.size(); j++) {
        for (int i=1; i<=textA.size(); i++) {
            int substitutionCost = (textA[i-1] == textB[j-1] ? 0 : 1);

            std::vector methodCosts = {
                d[i-1][j] + 1, // Delete
                d[i][j-1] + 1, // Insert
                d[i-1][j-1] + substitutionCost // Replace
            };

            d[i][j] = *std::ranges::min_element(methodCosts);
        }
    }

    printMatrix(d);

    return d[textA.size()][textB.size()];
}

#endif //LEVENSHTEIN_H

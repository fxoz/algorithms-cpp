#include <vector>
#include <limits.h>

#include "euros.h"
#include "felixsort.h"
#include "levenshtein.h"
#include "matrixmult.h"
#include "rucksack.h"


int main() {
    std::cout << "Enter amount in EUR: ";
    std::string inp;
    std::cin >> inp;

    float amount = std::stof(inp);
    int eur = amount;
    int cents = amount*100 - eur*100;

    std::cout << amount << " EUR = " << eur << " EUR, " << cents << " cents" << std::endl;
    calc(eur, cents);

    return 0;
}

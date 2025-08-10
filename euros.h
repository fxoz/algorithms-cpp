//
// Created by Lynx on 2025-08-10.
//

#ifndef EUROS_H
#define EUROS_H

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <valarray>
#include <vector>

std::string humanize_cents(int cents) {
    std::stringstream ss;
    ss << ((cents >= 100) ? (cents/100) : cents)
    <<  ((cents >= 100) ? "eur" : "ct");
    return ss.str();
}

class CoinOrNote {
private:
    const int _cents;
    const bool _is_coin;

public:
    CoinOrNote(int cents, bool is_coin) : _cents(cents), _is_coin(is_coin) {}

    std::string as_string() const {
        std::stringstream ss;
        ss << humanize_cents(_cents) << (_is_coin ? " (coin)" : " (note)");
        return ss.str();
    };
    int in_cents() const {
        return _cents;
    }
};

inline void calc(int eur, int cents) {
    // Greedy
    std::vector<CoinOrNote> amounts = {};
    for (int i=4; i>=0; i--) {
        for (int j : {5, 2, 1}) {
            int cents = j * std::pow(10, i);
            //std::cout << humanize_cents(cents) << "\n";
            amounts.emplace_back(CoinOrNote{cents, j<=200});
        }
    }

    float total = eur*100 + cents;
    float total_left = total;

    for (CoinOrNote change : amounts) {
        if (total_left > change.in_cents()) {
            int amount = (int)total_left/change.in_cents();
            int delta = amount*change.in_cents();
            total_left -= delta;
            std::cout << amount << "x " << change.as_string() << " (" << humanize_cents(delta) << ")" << "\n";
        }
    }
}

#endif //EUROS_H

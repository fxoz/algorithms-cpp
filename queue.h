//
// Created by Felix on 2025-08-15.
//

#ifndef QUEUE_H
#define QUEUE_H
#include <vector>

class Queue {
private:
    std::vector<int> _items;
public:
    void push(int i) {
        _items.emplace_back(i);
    }
    int pop() {
        int popped = _items.at(0);
        _items.erase(_items.begin());
        return popped;
    }
    int front() {
        return _items.back();
    }
    bool empty() {
        return _items.empty();
    }
    void print() {
        for (const auto& i : _items) {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }
};

#endif //QUEUE_H

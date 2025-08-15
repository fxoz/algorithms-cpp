#include <iostream>
#include <vector>

#include "queue.h"
#include "quicksort.h"

int main() {
    Queue q;
    q.push(1);
    q.push(2);
    std::cout << "[popped:" << q.pop() << "]";
    q.push(3);
    std::cout << "[popped:" << q.pop() << "]";
    q.push(4);

    q.print();
    return 0;
}

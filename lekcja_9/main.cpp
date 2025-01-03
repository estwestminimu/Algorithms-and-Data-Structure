#include <cassert>
#include "MyPriorityQueue.h"
#include <iostream>

int main() {
    MyPriorityQueue<int> test;

    test.push(1);
    test.push(2);
    assert(test.top() == 2);
    test.push(4);
    test.push(3);
    assert(test.top() == 4);

    test.display();

    test.pop();
    assert(test.top() == 3);
    test.push(10);
    test.push(9);
    assert(test.top() == 10);
    test.display();
    test.clear();
    assert(test.empty());

    std::cout << "Clear\n";
    test.display(); 

    return 0;
}

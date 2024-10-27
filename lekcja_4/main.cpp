#include <iostream>
#include <cassert>
#include "singlelist.h"

void test_push_front() {
    SingleList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    assert(list.front() == 3);
    std::cout << "Test push_front: OK" << std::endl;
}

void test_push_back() {
    SingleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    assert(list.back() == 3);
    std::cout << "Test push_back: OK" << std::endl;
}

void test_pop_front() {
    SingleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.pop_front();
    assert(list.front() == 2);
    std::cout << "Test pop_front: OK" << std::endl;
}

void test_pop_back() {
    SingleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.pop_back();
    assert(list.back() == 1);
    std::cout << "Test pop_back: OK" << std::endl;
}

void test_clear() {
    SingleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.clear();
    assert(list.size() == 0);
    std::cout << "Test clear: OK" << std::endl;
}

void test_reverse() {
    SingleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.reverse();
    assert(list.front() == 3 && list.back() == 1);
    std::cout << "Test reverse: OK" << std::endl;
}

void test_display() {
    SingleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    std::cout << "Test display: " << std::endl;
    list.display();

}

int main() {
    test_push_front();
    test_push_back();
    test_pop_front();
    test_pop_back();
    test_clear();
    test_reverse();
    test_display();

    return 0;
}
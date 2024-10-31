#include <iostream>
#include <cassert>
#include "doublelist.h"

void test_push_front()
{
    DoubleList<int> list;
    list.push_front(1);
    assert(list.front() == 1);
    list.push_front(2);
    assert(list.front() == 2);
    list.push_front(3);
    assert(list.front() == 3);
}

void test_push_back()
{
    DoubleList<int> list;
    list.push_back(1);
    assert(list.back() == 1);
    list.push_back(2);
    assert(list.back() == 2);
    list.push_back(3);
    assert(list.back() == 3);
}

void test_pop_front()
{
    DoubleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_front();
    assert(list.front() == 2);
    list.pop_front();
    assert(list.front() == 3);
    list.pop_front();
    assert(list.empty());
}

void test_pop_back()
{
    DoubleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_back();
    assert(list.back() == 2);
    list.pop_back();
    assert(list.back() == 1);
    list.pop_back();
    assert(list.empty());
}

void test_clear()
{
    DoubleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.clear();
    assert(list.empty());
}

void test_copy_constructor()
{
    DoubleList<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    DoubleList<int> list2(list1);
    assert(list1.size() == list2.size());
    assert(list1.front() == list2.front());
    assert(list1.back() == list2.back());
}

void test_copy_assignment_operator()
{
    DoubleList<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    DoubleList<int> list2;
    list2 = list1;
    assert(list1.size() == list2.size());
    assert(list1.front() == list2.front());
    assert(list1.back() == list2.back());
}

void test_display_reversed()
{
    DoubleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.display_reversed();
}

void test_display()
{
    DoubleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.display();
}
void test_size()
{
    DoubleList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    assert(list.size() == 3);
}


int main() {
    test_push_front();
    test_push_back();

    test_pop_front();
    test_pop_back();

    test_size();
    test_clear();

    test_copy_constructor();
    test_copy_assignment_operator();

    test_display_reversed();
    test_display();



    return 0;
}
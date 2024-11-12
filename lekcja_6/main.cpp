#include "mydeque.h"
#include <cassert>

int main() {
    MyDeque<int> deque(5);

    deque.push_back(1);
    deque.push_back(2);
    deque.push_front(3);
    deque.push_front(4);
    deque.push_back(5);
    deque.display();
    deque.pop_back();
    deque.pop_front();
    deque.display_reversed();
    deque.clear();
    assert(deque.empty());
    deque.display();


    return 0;
}

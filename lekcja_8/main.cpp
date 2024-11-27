 
#include <iostream>
#include <stack>





#include <iostream>
#include "MyQueue.h"

int main() {
    MyQueue<int> queue;

    queue.push(1);
    queue.push(2);
    queue.push(3);

    assert(queue.front() == 1);
    assert(queue.back() == 3);
    assert(queue.size() == 3);



    queue.pop();
    assert(queue.front() == 2);
    assert(queue.size() == 2);

    queue.pop();
    assert(queue.front() == 3);
    assert(queue.size() == 1);



    queue.clear();
    assert(queue.size() == 0);
    assert(queue.empty() == true);


    try {
        queue.pop();
    } catch (const std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout<<"X";
    return 0;
}
#include <iostream>
#include "onp.h"
#include <cassert>
#include <vector>

int main() {
    
    std::vector<std::string> input { "-6", "+2", "/" };
    assert( rpn(input) == -3 );
    std::vector<std::string> test2 { "5", "1", "2", "+", "4", "*", "+", "3", "-" };
    assert( rpn(test2) == 14 );
    std::vector<std::string> test3 { "2", "3", "+", "5", "*" };
    assert( rpn(test3) == 25 );
    std::vector<std::string> test4 {"11", "11", "-", "2", "*", "5", "+", "3", "2", "*", "-", "2", "-", "3", "/" };
    assert( rpn(test4) == -1 );
    std::cout<<"Wszystko ok"<<std::endl;
    return 0;
}

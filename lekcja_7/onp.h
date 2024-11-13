

#ifndef UNTITLED_ONP_H
#define UNTITLED_ONP_H

#include <vector>
#include <string>
#include <stack>
#include <iostream>

int rpn(const std::vector<std::string>& input)
{
    std::stack<int> stack;
  int a;
  int b;
    for (const auto& symbol : input) {
    if(symbol == "+")
    {
        a=stack.top();
        stack.pop();
        b=stack.top();
        stack.pop();
        stack.push(b+a);
    }
    else if(symbol == "-")
    {
            a=stack.top();
            stack.pop();
            b=stack.top();
            stack.pop();
          stack.push(b-a);
    }
    else if(symbol == "/")
    {
        a=stack.top();
        stack.pop();
        b=stack.top();
        stack.pop();
        stack.push(b/a);
    }
    else if(symbol == "*")
    {
        a=stack.top();
        stack.pop();
        b=stack.top();
        stack.pop();
        stack.push(b*a);
    }
    else
    {
            stack.push(std::stoi(symbol));
    }


    }
    return stack.top();



}

#endif

#ifndef UNTITLED_MYQUEUE_H
#define UNTITLED_MYQUEUE_H
#include <iostream>
#include <stack>
#include <cassert>
template <typename T>
class MyQueue {
private:
    std::stack<T> stack1;
    std::stack<T> stack2;
    void move( std::stack<T>& stackA, std::stack<T>& stackB) {
        while (!stackA.empty()) {
            stackB.push(stackA.top());
            stackA.pop();
        }
    }
public:
    MyQueue() {}
    ~MyQueue() {}
    MyQueue(const MyQueue& other) {
        stack1 = other.stack1;
        stack2 = other.stack2;
    }
    MyQueue(MyQueue&& other) noexcept {
        stack1 = std::move(other.stack1);
        stack2 = std::move(other.stack2);
    }
    MyQueue& operator=(const MyQueue& other) {
        if (this != &other) {
            stack1 = other.stack1;
            stack2 = other.stack2;
        }
        return *this;
    }
    MyQueue& operator=(MyQueue&& other) noexcept {
        if (this != &other) {
            stack1 = std::move(other.stack1);
            stack2 = std::move(other.stack2);
        }
        return *this;
    }
    bool empty() const {
        return stack1.empty();
    }
    std::size_t size() const {
        return stack1.size();
    }
    void push(const T& item) {
        stack1.push(item);
    }
    void push(T&& item) {
        stack1.push(std::move(item));
    }
    T& front() {
        if (!stack1.empty()) {
            move(stack1, stack2);
            T &tmp = stack2.top();
            move(stack2, stack1);
            return tmp;
        }else{
            throw std::out_of_range("Queue is empty!");
        }
    }
    T& back() {
        if (!stack1.empty()) {
            return stack1.top();
        } else{
            throw std::out_of_range("Queue is empty!");
        }
    }
    void pop() {
        if (!stack1.empty()) {
            move(stack1, stack2);
            stack2.pop();
            move(stack2, stack1);
        }
        else
        {
            throw std::out_of_range("Queue is empty!");
        }
    }
    void clear() {
        while (!stack1.empty()) {
            stack1.pop();
        }
    }
};
#endif
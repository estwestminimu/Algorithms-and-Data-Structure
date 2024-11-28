#ifndef MYPRIORITYQUEUE_H
#define MYPRIORITYQUEUE_H

#include <vector>
#include <algorithm>
#include <iostream>

template <typename T>
class MyPriorityQueue {
    std::vector<T> lst; 
public:
    
    MyPriorityQueue(std::size_t s = 10) { lst.reserve(s); }

    
    ~MyPriorityQueue()
    {
        lst.clear();
    }


    MyPriorityQueue(const MyPriorityQueue& other) : lst(other.lst)
    {

    }


    MyPriorityQueue(MyPriorityQueue&& other) noexcept : lst(std::move(other.lst))
    {

    }

    
    MyPriorityQueue& operator=(const MyPriorityQueue& other)
    {
        if (this != &other)
        {
            lst = other.lst;
        }
        return *this;
    }

    
    MyPriorityQueue& operator=(MyPriorityQueue&& other) noexcept
    {
        if (this != &other)
        {
            lst = std::move(other.lst);
        }
        return *this;
    }

    
    bool empty() const {
        return lst.empty();
    }

    
    std::size_t size() const {
        return lst.size();
    }

    
    void push(const T& item)
    {
        lst.push_back(item);               
        std::push_heap(lst.begin(), lst.end()); 
    }

    
    void push(T&& item)
    {
        lst.push_back(std::move(item));    
        std::push_heap(lst.begin(), lst.end()); 
    }

    
    T& top() {
        if (empty())
        {
            throw std::runtime_error("Empty!!!");
        }
        return lst.front();
    }

    
    void pop() {
        if (empty())
            {
            throw std::runtime_error("Empty!!!");
        }
        std::pop_heap(lst.begin(), lst.end()); 
        lst.pop_back();                        
    }

    
    void clear()
    {
        lst.clear();
    }

    
    void display() {
        if (empty())
        {
            std::cout<<"Empty";
        }
        else {
            std::vector<T> temp = lst;
            std::sort_heap(temp.begin(), temp.end());
            for (const auto& el : temp) {
                std::cout << el << " ";
            }
            std::cout << std::endl;

        }

    }
};


#endif 

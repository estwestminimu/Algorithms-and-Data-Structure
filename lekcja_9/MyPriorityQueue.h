#ifndef MyPriorityQueue_H
#define MyPriorityQueue_H

#include <forward_list>
#include <iostream>
#include <stdexcept>

template<typename T>
class MyPriorityQueue {
    std::forward_list<T> lst;
    std::size_t count;

public:
    MyPriorityQueue() : count(0) {}

    bool empty() const {
        return lst.empty();
    }

    std::size_t size() const {
        return count;
    }

    //O(n) bo petla po wszystkich elementach
    void push(const T& item) {

        auto set = lst.before_begin();//pozycja przed pierwszym elementem


        for (auto i = lst.begin(); i != lst.end(); ++i, ++set) {//i wskazuje na pierwszy element listy
            if (*i < item) {
                lst.insert_after(set, item);//wstawiamy element tam gdzie set poniewaz wskazuje on na element wczesniejszy
                ++count;
                return;
            }
        }
        lst.insert_after(set, item);//jesli jest najmniejszy to wstawiamy na sam koniec
        ++count;
    }

    //analogicznie do poprzedniego
    void push(T&& item) {
        auto set = lst.before_begin();

        for (auto i = lst.begin(); i != lst.end(); ++i, ++set) {
            if (*i < item) {
                lst.insert_after(set, std::move(item));
                ++count;
                return;
            }
        }

        lst.insert_after(set, std::move(item));
        ++count;
    }

    // Odczyt największego elementu
    //O(1)
    const T& top() const {
        if (empty()) {
            throw std::logic_error("Empty!!!");
        }
        return lst.front();
    }

    //O(1)
    void pop() {
        if (empty()) {
            throw std::logic_error("Empty!!!");
        }
        --count;
        lst.pop_front();

    }


    void clear() noexcept {
        count = 0;
        lst.clear();
    }

    void display() const {
        if (empty()) {
            std::cout << "[ Empty ]" << std::endl;
        }
        else {
            std::cout<< "[ ";
            for (const auto& item : lst) {
                std::cout << item << " ";
            }
            std::cout<< "]";

            std::cout << std::endl;
        }

    }
};

#endif

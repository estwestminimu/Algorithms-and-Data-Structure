#ifndef UNTITLED_MYDEQUE_H
#define UNTITLED_MYDEQUE_H


#include <cstdlib>
#include <iostream>
#include <cassert>

template<typename T>
class MyDeque {
    T *tab;
    std::size_t msize;
    std::size_t head;
    std::size_t tail;
public:
    MyDeque(std::size_t s = 10) : msize(s + 1), head(0), tail(0) {
        tab = new T[s + 1];
        assert(tab != nullptr);
    }
    ~MyDeque() { delete[] tab; }

    MyDeque(const MyDeque &other) {
        head = other.head;
        tail = other.tail;
        msize = other.msize;
        tab = new T[msize];
        for (std::size_t i = head; i != tail; i = (i + 1) % msize) {
            tab[i] = other.tab[i];
        }
    };
    MyDeque &operator=(const MyDeque &other) {
        if (this == &other) {
            return *this;
        }
        delete[] tab;
        head = other.head;
        tail = other.tail;
        msize = other.msize;
        tab = new T[msize];
        for (std::size_t i = 0; i < msize; i++) {
            tab[i] = other.tab[i];
        }
        return *this;
    };

    bool empty() const { return head == tail; }

    bool full() const { return (tail + 1) % msize == head; }

    std::size_t size() const { return (tail - head + msize) % msize; }

    std::size_t max_size() const { return msize - 1; }

    void push_front(const T &item) {
        if (full()) {
            return;
        }
        head = (head - 1 + msize) % msize;
        tab[head] = item;
    };

    void push_back(const T &item) {
        if (full()) {
            return;
        }
        tab[tail] = item;
        tail = (tail + 1) % msize;

    };

    T &front() { return tab[head]; }
    T &back() { return tab[(tail + msize - 1) % msize]; }
    void pop_front() {
        if(empty()) {
            return;
        }
        head = (head + 1) % msize;
    };
    void pop_back() {
        tail = (tail - 1 + msize) % msize;
        if(empty()) {
            return;
        }
    };
    void clear() {
        head = tail = 0;
    };
    void display()
    {
        for (std::size_t i = head; i != tail; i = (i + 1) % msize)
        {
            std::cout << tab[i] << ",";
        }
        std::cout << std::endl;
    };

    void display_reversed()
    {
        if (empty()) {
            std::cout << std::endl;
            return;
        }
        for (std::size_t i = (tail - 1 + msize) % msize; i != head; i = (i - 1 + msize) % msize) {
            std::cout << tab[i] << ",";
        }
        std::cout << tab[head] << std::endl; 
    }


};

#endif

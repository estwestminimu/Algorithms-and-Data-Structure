#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>
#include <cassert>

template<typename T>
struct DoubleNode {
    T value;
    DoubleNode *next, *prev;

    DoubleNode() : value(T()), next(nullptr), prev(nullptr) {}

    DoubleNode(const T &item, DoubleNode *nptr = nullptr, DoubleNode *pptr = nullptr)
            : value(item), next(nptr), prev(pptr) {}

    ~DoubleNode() {}
};

template<typename T>
class DoubleList {
    DoubleNode<T> *head, *tail;
public:
    DoubleList() : head(nullptr), tail(nullptr) {}

    ~DoubleList() {
        clear();
    };

    DoubleList(const DoubleList &other) {
        head = tail = nullptr;
        DoubleNode<T> *tmp = other.head;
        while (tmp != nullptr) {
            push_back(tmp->value);
            tmp = tmp->next;
        }
    };

    DoubleList &operator=(const DoubleList &other) {
        if (this == &other) return *this;
        clear();
        DoubleNode<T> *tmp = other.head;
        while (tmp != nullptr) {
            push_back(tmp->value);
            tmp = tmp->next;
        }
        return *this;
    };

    bool empty() const { return head == nullptr; }

    std::size_t size() const {
        std::size_t count = 0;
        DoubleNode<T> *tmp = head;
        while (tmp != nullptr) {
            count++;
            tmp = tmp->next;
        }
        return count;
    }

    void push_front(const T &item) {
        if (!empty()) {
            head = new DoubleNode<T>(item, head);
            head->next->prev = head;
        } else {
            head = tail = new DoubleNode<T>(item);
        }
    }

    void push_back(const T &item) {
        if (!empty()) {
            tail = new DoubleNode<T>(item, nullptr, tail);
            tail->prev->next = tail;
        } else {
            head = tail = new DoubleNode<T>(item);
        }
    }

    T &front() const { return head->value; }

    T &back() const { return tail->value; }

    void pop_front() {
        if (empty()) return;
        DoubleNode<T> *tmp = head;
        head = head->next;
        if (head != nullptr) head->prev = nullptr;
        delete tmp;
    }

    void pop_back() {
        if (empty()) return;
        DoubleNode<T> *tmp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete tmp;
    }

    void clear() {
        while (!empty()) pop_front();
    }

    void display() {
        DoubleNode<T> *tmp = head;
        while (tmp != nullptr) {
            std::cout << tmp->value << " ";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }

    void display_reversed() {
        DoubleNode<T> *tmp = tail;
        while (tmp != nullptr) {
            std::cout << tmp->value << " ";
            tmp = tmp->prev;
        }
        std::cout << std::endl;
    }
};

#endif
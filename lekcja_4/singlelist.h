#ifndef SINGLELIST_H
#define SINGLELIST_H

#include <iostream>  
#include <cassert>   

template <typename T>
struct SingleNode {
    T value;
    SingleNode *next;
    SingleNode() : value(T()), next(nullptr) {} // konstruktor domyslny
    SingleNode(const T& item, SingleNode *ptr=nullptr) : value(item), next(ptr) {}
    ~SingleNode() {} // destruktor
};

template <typename T>
class SingleList {
    SingleNode<T> *head, *tail;
    std::size_t length; // DLUGOSC
public:
    SingleList() : head(nullptr), tail(nullptr), length(0) {}
    ~SingleList() {
        while (!empty()) { pop_front(); }
    }

    SingleList(const SingleList& other) : head(nullptr), tail(nullptr), length(0) {
        SingleNode<T> *node = other.head;
        while (node != nullptr) {
            push_back(node->value);
            node = node->next;
        }
    }

    SingleList& operator=(const SingleList& other) {
        if (this == &other) {
            return *this;
        }
        clear();
        SingleNode<T> *node = other.head;
        while (node != nullptr) {
            push_back(node->value);
            node = node->next;
        }
        return *this;
    }

    bool empty() const { return head == nullptr; }
    std::size_t size() const { return length; } // O(1) bo uzylismy zmiennej length

    void push_front(const T& item) {
        if (!empty()) {
            head = new SingleNode<T>(item, head);
        } else {
            head = tail = new SingleNode<T>(item);
        }
        length++; // dlugosc
    }

    void push_back(const T& item) {
        if (!empty()) {
            tail->next = new SingleNode<T>(item);
            tail = tail->next;
        } else {
            head = tail = new SingleNode<T>(item);
        }
        length++;  // dlugosc
    }

    T& front() const { return head->value; }
    T& back() const { return tail->value; }

    void pop_front() {
        assert(!empty());
        SingleNode<T> *node = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
        }
        delete node;
        length--; //  dlugosc
    }

    void pop_back() {
        assert(!empty());
        SingleNode<T> *node = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            SingleNode<T> *before = head;
            while (before->next != tail) {
                before = before->next;
            }
            tail = before;
            tail->next = nullptr;
        }
        delete node;
        length--; // dlugosc
    }

    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    void display() {
        SingleNode<T> *node = head;
        while (node != nullptr) {
            std::cout << node->value << " ";
            node = node->next;
        }
        std::cout << std::endl;
    }

    void reverse() {
        SingleNode<T> *prev = nullptr;
        SingleNode<T> *current = head;
        SingleNode<T> *next = nullptr;
        tail = head;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};
/*
 template <typename T>
SingleList<T>::~SingleList() {
    // I sposob.
    for (SingleNode<T> *node; !empty(); ) {
        node = head->next; // zapamietujemy
        delete head;
        head = node; // kopiowanie wskaznika
    }
    // II sposob.
    // while (!empty()) { pop_front(); }
}

template <typename T>
void SingleList<T>::push_front(const T& item) {
    if (!empty()) {
        head = new SingleNode<T>(item, head);
    } else {
        head = tail = new SingleNode<T>(item);
    }
}

template <typename T>
void SingleList<T>::push_back(const T& item) {
    if (!empty()) {
        tail->next = new SingleNode<T>(item);
        tail = tail->next;
    } else {
        head = tail = new SingleNode<T>(item);
    }
}

template <typename T>
void SingleList<T>::display() {
    SingleNode<T> *node = head;
    while (node != nullptr){
        std::cout << node->value << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

template <typename T>
void SingleList<T>::pop_front() {
    assert(!empty());
    SingleNode<T> *node = head; // zapamietujemy
    if (head == tail) { // jeden wezel na liscie
        head = tail = nullptr;
    } else { // wiecej niz jeden wezel na liscie
        head = head->next;
    }
    delete node;
}

template <typename T>
void SingleList<T>::pop_back() {
    assert(!empty());
    SingleNode<T> *node = tail; // zapamietujemy
    if (head == tail) { // jeden wezel na liscie
        head = tail = nullptr;
    } else { // wiecej niz jeden wezel na liscie
        // Szukamy poprzednika ogona.
        SingleNode<T> *before=head;
        while (before->next != tail) {
            before = before->next;
        }
        tail = before;
        tail->next = nullptr;
    }
    delete node;
}
 */

#endif
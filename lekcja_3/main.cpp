#include <iostream>
#include "arraylist.h"


void push_back_test()
{
    ArrayList<int> lista;
    ArrayList<int> empty;
    lista.push_back(1);
    lista.push_back(2);
    std::cout << "Test push_back: " << (lista.back()== 2 ? "OK" : "FAIL") << std::endl;

}

void push_front_test()
{
    ArrayList<int> lista;
    lista.push_front(1);
    lista.push_front(2);
    std::cout << "Test push_front: " << (lista.front() == 2 ? "OK" : "FAIL") << std::endl;
}

void pop_front_test()
{
    ArrayList<int> lista(2);
    lista.push_back(0);
    lista.push_back(1);
    lista.pop_front();
    std::cout << "Test pop_front: " << (lista.front() == 1 ? "OK" : "FAIL") << std::endl;
}

void pop_back_test()
{
    ArrayList<int> lista;
    ArrayList<int> empty;
    lista.push_back(1);
    lista.push_back(2);
    lista.pop_back();
    std::cout << "Test pop_back: " << (lista.back() == 1 ? "OK" : "FAIL") << std::endl;
}
void clear_test()
{
    ArrayList<int> lista;
    lista.push_back(1);
    lista.push_back(2);
    lista.clear();
    std::cout << "Test clear: " << (lista.size() == 0 ? "OK" : "FAIL") << std::endl;
};

void display_test()
{
    std::cout<<"Display test: "<<std::endl;
    ArrayList<int> lista;
    ArrayList<int> empty;
    lista.push_back(1);
    lista.push_back(2);
    lista.display();


}

void front_test()
{
    ArrayList<int> lista;
    lista.push_back(1);
    lista.push_back(2);
    std::cout << "Test front: " << (lista.front() == 1 ? "OK" : "FAIL") << std::endl;
}

void back_test()
{
    ArrayList<int> lista;
    lista.push_back(1);
    lista.push_back(2);
    std::cout << "Test back: " << (lista.back() == 2 ? "OK" : "FAIL") << std::endl;
}

void reverse_test()
{
    ArrayList<int> lista;
    lista.push_back(1);
    lista.push_back(2);
    lista.push_back(3);
    lista.reverse();
    std::cout << "Test reverse: " << (lista.front() == 3 && lista.back() == 1 ? "OK" : "FAIL") << std::endl;
}


void sort_test()
{
    ArrayList<int> lista;
    lista.push_back(3);
    lista.push_back(1);
    lista.push_back(2);
    lista.sort();
    std::cout << "Test sort: " << (lista.front() == 1 && lista.back() == 3 ? "OK" : "FAIL") << std::endl;
}

void insert_test()
{
    ArrayList<int> lista;
    lista.push_back(1);
    lista.push_back(2);
    lista.insert(1, 3);
    std::cout << "Test insert: " << (lista.front() == 1 && lista.back() == 2 ? "OK" : "FAIL") << std::endl;
}

void index_test()
{
    ArrayList<int> lista;
    lista.push_back(1);
    lista.push_back(2);
    lista.push_back(3);
    std::cout << "Test index: " << (lista.index(2)==1 ? "OK" : "FAIL") << std::endl;
}


void erase_test()
{
    ArrayList<int> lista;
    lista.push_back(1);
    lista.push_back(2);
    lista.erase(0);
    std::cout << "Test erase: " << (lista.front() == 2 ? "OK" : "FAIL") << std::endl;
}

int main() {

   push_back_test();
    pop_front_test();
    pop_back_test();
    clear_test();
    push_front_test();
    front_test();
    back_test();;
    reverse_test();
    sort_test();
    insert_test();
    index_test();
    erase_test();


    display_test();





    return 0;
}
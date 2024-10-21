// arraylist.h

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>     // deklaracje strumieni cout, cin, cerr
#include <cassert>    // assert()

template <typename T>
class ArrayList {
    T* tab;
    int msize; // najwieksza mozliwa liczba elementow
    int last; // pierwsza wolna pozycja
public:
    ArrayList(int s=10) : msize(s), last(0) {
        assert( s > 0 );
        tab = new T[s];
        assert( tab != nullptr );
    } // default constructor
    ~ArrayList() { delete [] tab; } // destruktor

    ArrayList(const ArrayList& other)
    {
        msize = other.msize;
        last = other.last;
        tab = new T[msize];
        for (int i = 0; i < last; i++) {
            tab[i] = other.tab[i];
        }
    }; // copy constructor
    // usage:   ArrayList<int> list2(list1);



    ArrayList& operator=(const ArrayList& other)
    {
        if(this == &other)
        {
            return *this;
        }
        delete [] tab;
        msize = other.msize;
        last = other.last;
        tab = new T[msize];
        for (int i = 0; i < last; i++) {
            tab[i] = other.tab[i];
        }
        return *this;
    }; // copy assignment operator, return *this
    // usage:   list2 = list1;



    bool empty() const { return last == 0; } // checks if the container has no elements
    bool full() const { return last == msize; } // checks if the container is full
    int size() const { return last; } // liczba elementow na liscie
    int max_size() const { return msize; } // najwieksza mozliwa liczba elementow
    void push_front(const T& item)
    {
        if(full())
        {
            std::cerr<< "Error: pelna lista\n";
        }
        else
        {
            last++;
            for (int i = last; i > 0; i--) {
                tab[i]=tab[i-1];
            }
            tab[0] = item;

        }
    }; // dodanie na poczatek

    void push_back(const T& item)
    {
        if(full())
        {
            std::cerr<< "Error: pelna lista\n";
        }
        else
        {
            tab[last++] = item;
        }

    }; // dodanie na koniec
    T& front()
    {
        if (empty()) {
            std::cerr<< "Error: pusta lista\n";
            exit(1);
        }else
        {
            return tab[0];
        }
    }; // zwraca poczatek, nie usuwa, error dla pustej listy
    T& back()
    {
        if(empty())
        {
            std::cerr<< "Error: pusta lista\n";
            exit(1);
        }
        else
        {
           return tab[last-1];
        }
    }; // zwraca koniec, nie usuwa, error dla pustej listy

    void pop_front()
    {
        if(empty())
        {
            std::cerr<< "Error: pusta lista\n";
            exit(1);
        }
        else
        {
            for (int i = 0; i <last; i++) {

               tab[i]=tab[i+1];
            }
            last--;
        }
    }; // usuwa poczatek, error dla pustej listy
    void pop_back()
    {
        if(empty())
        {
            std::cerr<< "Error: pusta lista\n";
            exit(1);
        }
        else
        {
            last--;
        }
    }; // usuwa koniec, error dla pustej listy
    void clear()
    {
        last = 0;
    }; // czyszczenie listy z elementow
    void display(int z=-1)
    {
        for (int i = 0; i < last; i++)
        {std::cout << tab[i] << ' ';}
        std::cout << '\n';

        std::cout<<std::endl;
    }; // lepiej zdefiniowac operator<<
    void reverse()
    {
        for (int i = 0; i < last/2; i++) {
            T temp = tab[i];
            tab[i] = tab[last-i-1];
            tab[last-i-1] = temp;
        }
    }; // odwracanie kolejnosci
    void sort()
    {
        for (int i = 0; i < last; i++) {
            for (int j = 0; j < last-1; j++) {
                if(tab[j]>tab[j+1])
                {
                    T temp = tab[j];
                    tab[j] = tab[j+1];
                    tab[j+1] = temp;
                }
            }
        }
    }; // sortowanie listy

    T& operator[](int pos)
    {
        // podstawienie L[pos]=item, odczyt L[pos]


    };

    void erase(int pos){
        if(pos<0 || pos>=last)
        {
            std::cerr<< "Error: niepoprawny index\n";
            exit(1);
        }
        else
        {
            for (int i = pos; i < last; i++) {
                tab[i]=tab[i+1];
            }
            last--;
        }
    }; // usuniecie elementu na pozycji pos
    int index(const T& item)
    {
        for (int i = 0; i < last; i++) {
            if(tab[i]==item)
            {
                return i;
            }
        }
        return -1;
    }; // jaki index na liscie (-1 gdy nie ma)
    void insert(int pos, const T& item)
    {
        if(full())
        {
            std::cerr<< "Error: pelna lista\n";
        }
        else if(pos<0 || pos>last)
        {
            std::cerr<< "Error: niepoprawny index\n";
        }
        else
        {
            for (int i = last; i > pos; i--) {
                tab[i]=tab[i-1];
            }
            tab[pos] = item;
            last++;
        }
    }; // inserts item before pos
    void insert(int pos, T&& item){
        if(full())
        {
            std::cerr<< "Error: pelna lista\n";
        }
        else if(pos<0 || pos>last)
        {
            std::cerr<< "Error: niepoprawny index\n";
        }
        else
        {
            for (int i = last; i > pos; i--) {
                tab[i]=tab[i-1];
            }
            tab[pos] = std::move(item);
            last++;
        }
    }; // inserts item before pos
    // Jezeli pos=0, to wstawiamy na poczatek.
    // Jezeli pos=size(), to wstawiamy na koniec.

    friend std::ostream& operator<<(std::ostream& os, const ArrayList& L) {
        for (int i=0; i < L.last; ++i) { // odwolanie L.last
            os << L.tab[i] << " ";   // odwolanie L.tab
        }
        return os;
    } // usage:   std::cout << L << std::endl;
};

#endif

// EOF
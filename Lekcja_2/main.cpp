// Szymon Tomaszewski
#include <iostream>
#include <algorithm>
#include "Bubblesort.h"
#include "Mergesort.h"
#include <vector>
#include <cassert>

// DEBUGOWANIE
// Aby uzyc nalezy odkomentowac
/*
#define DEBUG
*/

int main()
{

    std::vector<double> arr = {6.4, 3.4, 2.5, 1.2, 2.2, 1.1, 3.0};
    std::vector<long> arr2 = {64, 34, 25, 12, 22, 11, 3000};

    // wybieramy poczatek i koniec
    mergesort(arr.begin() + 2, arr.end() - 1);
    bubblesort(arr2.begin() + 2, arr2.end() - 1);

// wyswietlanie postrtowanej tablicy
#ifdef DEBUG
    std::cout << "Bubble Sort\n";
    for (const auto &elem : arr)
    {
        std::cout << elem << " ";
    }
    std::cout << "\nMerge Sort\n";
    for (const auto &elem : arr2)
    {
        std::cout << elem << " ";
    }
#endif

    assert(std::is_sorted(arr.begin() + 2, arr.end() - 1));
    assert(std::is_sorted(arr2.begin() + 2, arr2.end() - 1));

    return 0;
}

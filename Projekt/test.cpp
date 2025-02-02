#include <iostream>
#include <vector>
#include <algorithm>
#include "Point.h"
#include "quickhull.h"

// Funkcja sprawdzająca, czy otoczka wypukła jest zgodna z oczekiwaną
bool testHull(const std::vector<Point>& expected, const std::vector<Point>& current) {
    //jesli dlugosc sie nie zgadza to otoczka nie powinna istniec
    if (expected.size() != current.size()) {
        return false;
    }
    //sprawdzamy czy kazdy punkt z oczekiwanej otoczki jest w obecnej otoczce
    for (const Point& p : expected) {
        if (std::find(current.begin(), current.end(), p) == current.end()) {
            return false;
        }
    }
    return true;
}

// Struktura do testowania
struct TestStruct {
    std::vector<Point> points;           // Input
    std::vector<Point> expectedHull;     // Poprawne
    int testNumber;                // Numer testu
};

// Tablica testów (każdy test to instancja TestStruct)
std::vector<TestStruct> testCases = {
    { { {0, 0}, {4, 0}, {4, 4}, {0, 4}, {2, 2} }, { {0, 0}, {4, 0}, {4, 4}, {0, 4} }, 1 },
    { { {0, 0}, {2, 4}, {4, 0}, {2, 2} }, { {0, 0}, {4, 0}, {2, 4} }, 2 },
    { { {0, 0}, {4, 0}, {4, 4}, {0, 4}, {2, 2}, {1, 3}, {5, 2} }, { {0, 0}, {4, 0}, {4, 4}, {0, 4}, {5, 2} }, 4 },
    { { {1, 1}, {2, 2}, {3, 1}, {4, 2}, {5, 1} }, { {1, 1}, {2, 2}, {4, 2}, {5, 1} }, 5 },
    { { {0, 0}, {1, 5}, {2, 2}, {3, 4}, {4, 1}, {5, 0} }, { {0, 0}, {1, 5}, {5, 0}, {3, 4},   }, 6 },
    { { {0, 0}, {0, 5}, {5, 5}, {5, 0}, {2, 2}, {3, 3} }, { {0, 0}, {0, 5}, {5, 5}, {5, 0},  }, 7 },
    { { {0, 0}, {3, 3}, {6, 0}, {3, -3} }, { {0, 0}, {6, 0}, {3, 3}, {3, -3} }, 8 },
    { { {0, 0}, {2, 4}, {4, 0}, {2, 2}, {1, 3}, {3, 3} }, { {0, 0}, {2, 4}, {4, 0}, {1, 3}, {3, 3}  }, 9 },
{ { {0, 0}, {2, 4}, {4, 0}, {2, 2}, {1, 3}, {3, 3}, {2, -3}, {1, -4}, {3,-5} }, { {0, 0}, {2, 4}, {4, 0}, {1, 3}, {3, 3},  {1, -4}, {3,-5}  }, 10 },

};

// Funkcja uruchamiająca wszystkie testy
void runTests() {

    // Przechodzimy przez wszystkie przypadki testowe
    for (const auto& test : testCases) {


        std::vector<Point> actualHull = quickHull(test.points);
        std::cout << "Test " << test.testNumber << ": "
                  << (testHull(test.expectedHull, actualHull) ? "OK" : "X")
                  << std::endl;

        std::cout<<"Otoczka: ";
        for (const Point& p : actualHull) {
            std::cout << "(" << p.x << ", " << p.y << "), ";
        }
        std::cout<<"\n====================\n";

    }
}

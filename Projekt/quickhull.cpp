#include "quickhull.h"
#include <cmath>
#include <algorithm>
#include <iostream>

// Oblicza odległość punktu P od linii AB
double distance(const Point& A, const Point& B, const Point& P) {
    //Pole rownloegloboku
    double numerator = std::abs((P.y - A.y) * (B.x - A.x) - (B.y - A.y) * (P.x - A.x));
    //Liczone z Pitagorasa
    double denominator = std::sqrt(std::pow(B.x - A.x, 2) + std::pow(B.y - A.y, 2));

    return numerator / denominator;
}

// Porównuje punkty według X, a w razie równości według Y
bool compare(const Point& p1, const Point& p2) {
    return (p1.x == p2.x) ? p1.y < p2.y : p1.x < p2.x;
}

// Iloczyn wektorowy
int cross(const Point& A, const Point& B, const Point& P) {
    return (B.x - A.x) * (P.y - A.y) - (B.y - A.y) * (P.x - A.x);
}

// Rozdziela punkty na lewej i prawej stronie linii AB
void getSides(const std::vector<Point>& points, const Point& A, const Point& B,
              std::vector<Point>& leftSide, std::vector<Point>& rightSide) {
    for (const Point& p : points) {
        int x = cross(A, B, p);
        if (x < 0) {
            rightSide.push_back(p);
        }
        if (x > 0) {
            leftSide.push_back(p);
        }

    }
}

// Znajduje najdalszy punkt od linii AB
Point findFarthestPoint(const std::vector<Point>& points, const Point& A, const Point& B) {
    double maxDistance = -1; //nadpisywany dystans
    Point f_Point(0, 0);//nadpisywana odleglosc
    for (const Point& p : points) {
        double dist = distance(A, B, p);
        if (dist > maxDistance) {
            maxDistance = dist;
            f_Point = p;
        }
    }
    return f_Point;
}

//Pomocnicza funkcja dla algorytmu QuickHull
void quickHullHelper(const std::vector<Point>& points, const Point& A, const Point& B, std::vector<Point>& hull) {
    if (points.empty()) {
        return;
    }

    //Okreslamy najdalszy punkty
    Point F = findFarthestPoint(points, A, B);
    hull.push_back(F);//Tutaj sa zapisywane punkty otoczki

    //lewe strony punktow dla linii AF i FB
    std::vector<Point> left_AF, left_FB;

    for (const Point& p : points) {
        //Z iloczynu wektorowego sprawdzamy czy punkt jest po dobrej stronie
        if (cross(A, F, p) > 0) {
            left_AF.push_back(p);
        } else if (cross(F, B, p) > 0) {
            left_FB.push_back(p);
        }
    }

    //Wykonujemy znowu dla nowych zbiorow
    quickHullHelper(left_AF, A, F, hull);
    quickHullHelper(left_FB, F, B, hull);
}

// Główna funkcja algorytmu QuickHull
std::vector<Point> quickHull(const std::vector<Point>& points) {

    //Punkty otoczki wypuklej
    std::vector<Point> hull;

    //3 lub mniej punktow zawsze stworza otoczke
    if (points.size() < 3) {
        std::cout << "Otoczka niemozliwa\n";
        return hull;
    }



    // Sortowanie punktów - w celu znalezienia najbardziej oddalonych punktów - os x
    std::vector<Point> sortedPoints = points;
    std::sort(sortedPoints.begin(), sortedPoints.end(), compare);

    //Znajdujemy najdalej odległe punkty - one na pewno naleza do otoczki
    Point A = sortedPoints.front();
    Point B = sortedPoints.back();
    hull.push_back(A);
    hull.push_back(B);



    //Rozdzielamy punkty na lewe i prawe wzgledem AB
    std::vector<Point> left, right;
    getSides(sortedPoints, A, B, left, right);

    quickHullHelper(left, A, B, hull);
    quickHullHelper(right, B, A, hull);

    // Usunięcie duplikatów
    std::sort(hull.begin(), hull.end(), compare);
    hull.erase(std::unique(hull.begin(), hull.end()), hull.end());

    return hull;
}
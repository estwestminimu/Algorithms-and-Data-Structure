
#ifndef POINT_H
#define POINT_H

struct Point {
    //wspolrzedne x i y
    int x;
    int y;


    //Wartosc przekaza do x zostanie przypisane do zmiennej x
    //Analogicznie dla y
    Point(int x, int y) : x(x) , y(y) {}

    //przeciążenie operatora porównania
    //other to referencja do innego obiektu typu Point ktory jest porownwny z obecnym obiektem
    //const zapewnia nam to ze obiekt other nie zostanie zmodyfikowany
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};


#endif

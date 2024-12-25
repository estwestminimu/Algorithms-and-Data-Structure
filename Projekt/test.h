#ifndef TEST_H
#define TEST_H

#include <vector>
#include "Point.h"

bool testHull(const std::vector<Point>& oczekiwana, const std::vector<Point>& aktualna);
void testSquare();
void testTriangle();
void testCollinear();
void testRandom();
void runTests();

#endif // TEST_H
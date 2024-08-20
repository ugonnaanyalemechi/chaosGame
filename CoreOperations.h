#pragma once
#include "Point.h"

class CoreOperations 
{
private:
	void turnCellOn(Point);
	void findMidpointBetweenTwoPoints(const int, Point[], Point&, Point, Point, int);
	void turnFirstTestInitialPointsOn(Point, Point, Point, Point);
	void runFirstTestIterations(Point, Point, Point, Point);
	void turnSecondTestInitialPointsOn(Point, Point, Point, Point, Point);
	void runSecondTestIterations(Point, Point, Point, Point, Point);
	void turnThirdTestInitialPointsOn(Point, Point, Point, Point, Point, Point);
	void runThirdTestIterations(Point, Point, Point, Point, Point, Point);
public:
	void performFirstTest(Point);
	void performSecondTest(Point);
	void performThirdTest(Point);
};
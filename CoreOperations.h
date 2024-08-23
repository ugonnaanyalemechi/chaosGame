#pragma once
#include <vector>
#include "Point.h"

using std::string;
using std::vector;

class CoreOperations 
{
private:
	void turnCellOn(Point);
	void turnCellOn(Point*);
	void findMidpointBetweenTwoPoints(const int, Point[], Point&, Point, Point, int);
	void turnFirstTestInitialPointsOn(Point, Point, Point, Point);
	void runFirstTestIterations(Point, Point, Point, Point);
	void turnSecondTestInitialPointsOn(Point, Point, Point, Point, Point);
	void runSecondTestIterations(Point, Point, Point, Point, Point);
	void turnThirdTestInitialPointsOn(Point, Point, Point, Point, Point, Point);
	void runThirdTestIterations(Point, Point, Point, Point, Point, Point);
	vector<Point*> chooseInitialPoints();
	void getLocationOfInitialPointsFromUser(vector<Point*>&, int);
	bool checkIntegerInputForPointPosition(string);
	bool checkIntegerInputForNumOfThings(string);
	void turnCustomTestInitialPointsOn(vector<Point*>, Point);
	void runCustomTestIterations(vector<Point*>, Point);
	void findMidpointBetweenTwoPoints(const int, vector<Point*>, Point&, Point*);
public:
	void performFirstTest();
	void performSecondTest();
	void performThirdTest();
	void performCustomTest();
	bool checkInputIsInteger(string);
	bool checkInputIsEmpty(string);
};
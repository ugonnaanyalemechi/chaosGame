#include <iostream>
#include <vector>
#include "CoreOperations.h"
#include "extern.h"

using namespace std;

void CoreOperations::performFirstTest() {
    Point p1 = { 100, 500 }, p2 = { 800, 100 }, p3 = { 800, 900 }, curPoint = {500, 500};
    turnFirstTestInitialPointsOn(p1, p2, p3, curPoint);
    runFirstTestIterations(p1, p2, p3, curPoint);
}

void CoreOperations::turnFirstTestInitialPointsOn(Point p1, Point p2, Point p3, Point curPoint) {
    turnCellOn(p1);
    turnCellOn(p2);
    turnCellOn(p3);
    turnCellOn(curPoint);
}

void CoreOperations::runFirstTestIterations(Point p1, Point p2, Point p3, Point curPoint) {
    const int NUM_POINTS_IN_FIRST_TEST = 3;
    Point firstTestPoints[NUM_POINTS_IN_FIRST_TEST] = { p1, p2, p3 };
    Point chosenPoint, midpoint;

    for (int i = 0; i < 1000000; i++) {
        chosenPoint = firstTestPoints[rand() % NUM_POINTS_IN_FIRST_TEST]; // a point is randomly selected from the initial defined points
        findMidpointBetweenTwoPoints(NUM_POINTS_IN_FIRST_TEST, firstTestPoints, curPoint, midpoint, chosenPoint, i);
    }
}

void CoreOperations::performSecondTest() {
    Point p1 = { 100, 100 }, p2 = { 100, 900 }, p3 = { 900, 100 }, p4 = { 900, 900 }, curPoint = {500, 500};
    turnSecondTestInitialPointsOn(p1, p2, p3, p4, curPoint);
    runSecondTestIterations(p1, p2, p3, p4, curPoint);
}

void CoreOperations::turnSecondTestInitialPointsOn(Point p1, Point p2, Point p3, Point p4, Point curPoint) {
    turnCellOn(p1);
    turnCellOn(p2);
    turnCellOn(p3);
    turnCellOn(p4);
    turnCellOn(curPoint);
}

void CoreOperations::runSecondTestIterations(Point p1, Point p2, Point p3, Point p4, Point curPoint) {
    const int NUM_POINTS_IN_SECOND_TEST = 4;

    Point secondTestPoints[] = { p1, p2, p3, p4 };
    Point chosenPoint, midpoint;

    for (int i = 0; i < 1000000; i++) {
        chosenPoint = secondTestPoints[rand() % NUM_POINTS_IN_SECOND_TEST]; // a point is randomly selected from the initial defined points
        findMidpointBetweenTwoPoints(NUM_POINTS_IN_SECOND_TEST, secondTestPoints, curPoint, midpoint, chosenPoint, i);
    }
}

void CoreOperations::performThirdTest() {
    Point p1 = { 200, 500 }, p2 = { 350, 210 }, p3 = { 350, 790 }, p4 = { 675, 300 }, p5 = { 675, 700 }, curPoint = {500, 500};
    turnThirdTestInitialPointsOn(p1, p2, p3, p4, p5, curPoint);
    runThirdTestIterations(p1, p2, p3, p4, p5, curPoint);
}

void CoreOperations::turnThirdTestInitialPointsOn(Point p1, Point p2, Point p3, Point p4, Point p5, Point curPoint) {
    turnCellOn(p1);
    turnCellOn(p2);
    turnCellOn(p3);
    turnCellOn(p4);
    turnCellOn(p4);
    turnCellOn(curPoint);
}

void CoreOperations::runThirdTestIterations(Point p1, Point p2, Point p3, Point p4, Point p5, Point curPoint) {
    const int NUM_POINTS_IN_THIRD_TEST = 5;

    Point thirdTestPoints[NUM_POINTS_IN_THIRD_TEST] = { p1, p2, p3, p4, p5};
    Point chosenPoint, midpoint;

    for (int i = 0; i < 5000000; i++) {
        chosenPoint = thirdTestPoints[rand() % NUM_POINTS_IN_THIRD_TEST]; // a point is randomly selected from the initial defined points
        findMidpointBetweenTwoPoints(NUM_POINTS_IN_THIRD_TEST, thirdTestPoints, curPoint, midpoint, chosenPoint, i);
    }
}

void CoreOperations::performCustomTest() {
    Point curPoint = { 537, 453 };
    vector<Point*> initialPoints = chooseInitialPoints();
    turnCustomTestInitialPointsOn(initialPoints, curPoint);
    runCustomTestIterations(initialPoints, curPoint);
}

vector<Point*> CoreOperations::chooseInitialPoints() {
    string numOfPointsString;
    int numOfPoints;
    bool numOfPointsValid = false;
    vector<Point*> initialPoints;

    while (!numOfPointsValid) {
        cout << "\nHow many points would you like? (Use numerical digits)\n";
        cout << "Enter here: "; getline(cin, numOfPointsString);
        numOfPointsValid = checkIntegerInputForNumOfThings(numOfPointsString);
    }

    numOfPoints = stoi(numOfPointsString);

    cout << "\nNOTE: The top leftmost point of the grid is (0,0) and the bottom rightmost point is (999, 999)\n";

    for (int i = 0; i < numOfPoints; i++)
        getLocationOfInitialPointsFromUser(initialPoints, i);
    return initialPoints;
}

void CoreOperations::getLocationOfInitialPointsFromUser(vector<Point*>& initialPoints, int i) {
    string xValueString, yValueString;
    int xValue, yValue;
    bool xValueInputValid = false;
    bool yValueInputValid = false;

    while (!xValueInputValid) {
        cout << "\nEnter the X value (row value) of point " << i + 1 << ": ";
        getline(cin, xValueString);
        xValueInputValid = checkIntegerInputForPointPosition(xValueString);
    }
    while (!yValueInputValid) {
        cout << "\nEnter the Y value (column value) of point " << i + 1 << ": ";
        getline(cin, yValueString);
        yValueInputValid = checkIntegerInputForPointPosition(yValueString);
    }

    xValue = stoi(xValueString);
    yValue = stoi(yValueString);
    Point* newPoint = new Point;
    newPoint->xValue = xValue;
    newPoint->yValue = yValue;
    initialPoints.push_back(newPoint);
}

void CoreOperations::turnCellOn(Point point) {
    grid[point.xValue][point.yValue] = "X "; // "X" represents a cell that is turned on/true
}

void CoreOperations::turnCellOn(Point* point) {
    grid[point->xValue][point->yValue] = "X "; // "X" represents a cell that is turned on/true
}

void CoreOperations::findMidpointBetweenTwoPoints(const int NUM_POINTS, Point testPoints[], Point& curPoint, Point midpoint, Point chosenPoint, int iterations) {
    int xValueMidpoint = (chosenPoint.xValue + curPoint.xValue) / 2;
    int yValueMidpoint = (chosenPoint.yValue + curPoint.yValue) / 2;
    midpoint = { xValueMidpoint, yValueMidpoint }; // the midpoint between one of the chosen points and current point
    turnCellOn(midpoint);
    curPoint = midpoint; // the midpoint becomes the new current point
}


bool CoreOperations::checkIntegerInputForPointPosition(string input) {
    if (!checkInputIsEmpty(input))
        return false;
    if (!checkInputIsInteger(input))
        return false;
    if (stoi(input) >= 1000) {
        cout << "\nInvalid input!\n";
        cout << "Choose a number between 0-999\n";
        return false;
    }
    return true;
}

bool CoreOperations::checkIntegerInputForNumOfThings(string input) {
    if (!checkInputIsEmpty(input))
        return false;
    if (!checkInputIsInteger(input))
        return false;
    if (stoi(input) == 0) {
        cout << "\nInvalid input!\n";
        cout << "Choose a number greater than 1!\n";
        return false;
    }
    return true;
}

bool CoreOperations::checkInputIsInteger(string input) {
    for (char c : input) {
        if (!isdigit(c)) {
            cout << "\nInvald input! Try again!\n";
            return false;
        }
    }
    return true;
}

bool CoreOperations::checkInputIsEmpty(string input) {
    if (input == "") {
        cout << "\nInvalid input!\n";
        return false;
    }
    return true;
}

void CoreOperations::turnCustomTestInitialPointsOn(vector<Point*> initialPoints, Point curPoint) {
    for (Point* point : initialPoints)
        turnCellOn(point);
}

void CoreOperations::runCustomTestIterations(vector<Point*> initialPoints, Point curPoint) {
    const int NUM_OF_POINTS = initialPoints.size();
    Point* chosenPoint;
    string numOfIterationsString;
    int numOfIterations;
    bool numOfIterationsValid = false;

    while (!numOfIterationsValid) {
        cout << "\nHow many test iterations would you like? (Use numerical digits)\n";
        cout << "Enter here: "; getline(cin, numOfIterationsString);
        numOfIterationsValid = checkIntegerInputForNumOfThings(numOfIterationsString);
    }
    numOfIterations = stoi(numOfIterationsString);

    for (int i = 0; i < numOfIterations; i++) {
        chosenPoint = initialPoints[rand() % NUM_OF_POINTS]; // a point is randomly selected from the initial defined points
        findMidpointBetweenTwoPoints(NUM_OF_POINTS, initialPoints, curPoint, chosenPoint);
    }
}

void CoreOperations::findMidpointBetweenTwoPoints(const int NUM_POINTS, vector<Point*> testPoints, Point& curPoint, Point* chosenPoint) {
    Point midpoint;
    int xValueMidpoint = (chosenPoint->xValue + curPoint.xValue) / 2;
    int yValueMidpoint = (chosenPoint->yValue + curPoint.yValue) / 2;
    midpoint = { xValueMidpoint, yValueMidpoint }; // the midpoint between one of the chosen points and current point
    turnCellOn(midpoint);
    curPoint = midpoint; // the midpoint becomes the new current point
}

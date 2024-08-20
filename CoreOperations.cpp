#include "CoreOperations.h"
#include "Debugging.h"
#include "extern.h"

Debugging debug2;

void CoreOperations::performFirstTest(Point curPoint) {
    Point p1 = { 700, 220 }, p2 = { 200,500 }, p3 = { 700,820 };
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
    int xValueMidpoint, yValueMidpoint;

    for (int i = 0; i < 1000000; i++) {
        chosenPoint = firstTestPoints[rand() % 3]; // a point is randomly selected from the initial defined points
        findMidpointBetweenTwoPoints(NUM_POINTS_IN_FIRST_TEST, firstTestPoints, curPoint, midpoint, chosenPoint, i);
    }
    debug2.show("First test iterations complete."); debug2.pause();
}

void CoreOperations::performSecondTest(Point curPoint) {
    Point p1 = { 0, 0 }, p2 = { 0,500 }, p3 = { 500,500 }, p4 = { 500, 0 };
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
    int xValueMidpoint, yValueMidpoint;

    for (int i = 0; i < 1000000; i++) {
        chosenPoint = secondTestPoints[rand() % 4]; // a point is randomly selected from the initial defined points
        findMidpointBetweenTwoPoints(NUM_POINTS_IN_SECOND_TEST, secondTestPoints, curPoint, midpoint, chosenPoint, i);
    }
    debug2.show("Second test iterations complete."); debug2.pause();
}

void CoreOperations::performThirdTest(Point curPoint) {
    Point p1 = { 200, 500 }, p2 = { 350,210 }, p3 = { 350,790 }, p4 = { 675, 300 }, p5 = { 675, 700 };
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
    Point thirdTestPoints[NUM_POINTS_IN_THIRD_TEST] = { p1, p2, p3, p4, p5 };
    Point chosenPoint, midpoint;
    int xValueMidpoint, yValueMidpoint;

    for (int i = 0; i < 5000000; i++) {
        chosenPoint = thirdTestPoints[rand() % 5]; // a point is randomly selected from the initial defined points
        findMidpointBetweenTwoPoints(NUM_POINTS_IN_THIRD_TEST, thirdTestPoints, curPoint, midpoint, chosenPoint, i);
    }
    debug2.show("Third test iterations complete."); debug2.pause();
}

void CoreOperations::turnCellOn(Point point) {
    grid[point.xValue][point.yValue] = "X "; // "X" represents a cell that is turned on/true
}

void CoreOperations::findMidpointBetweenTwoPoints(const int NUM_POINTS, Point testPoints[], Point& curPoint, Point midpoint, Point chosenPoint, int iterations) {
    int xValueMidpoint = (chosenPoint.xValue + curPoint.xValue) / 2;
    int yValueMidpoint = (chosenPoint.yValue + curPoint.yValue) / 2;
    midpoint = { xValueMidpoint, yValueMidpoint }; // the midpoint between one of the chosen points and current point
    turnCellOn(midpoint);
    curPoint = midpoint; // the midpoint becomes the new current point
    debug2.displayCellsToConsoleOutput(grid, iterations);
}

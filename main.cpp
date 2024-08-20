#include <iostream> 
#include <fstream>
#include "Debugging.h"
#include "Setup.h"
#include "PPMFileManager.h"
#include "extern.h"

const int MAX_ROWS = 1000;
const int MAX_COLS = 1000;
string grid[MAX_ROWS][MAX_COLS];

int main() {
    srand(time(0)); // Using a fresh seed value based on time is necesssary to provide a fresh new set of random numbers
    int randomXValue = rand() % 500;
    int randomYValue = rand() % 500;
    Point curPoint = { randomXValue, randomYValue };
    fstream outputFile;
    Setup setup;
    PPMFileManager fileManager;

    setup.startUpProcess(curPoint);
    fileManager.transferToFileProcess(outputFile);

    return 0;
}
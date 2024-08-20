#include <iostream>
#include <iomanip>
#include "Setup.h"
#include "Debugging.h"
#include "CoreOperations.h"
#include "extern.h"

using namespace std;

Debugging debug1;
CoreOperations coreOps;

void Setup::startUpProcess(Point curPoint) {
	cout << "Welcome to the Chaos Game!\n";
	initializeGrid();
	promptUserToSelectTestOptions(curPoint);
}

void Setup::initializeGrid() {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++)
            grid[i][j] = "  "; // all cells that are not "on" are set at this state by default
    }
    debug1.show("Grid initialized...");
}

void Setup::promptUserToSelectTestOptions(Point curPoint) {
    showUserTestOptions();
    string optionSelected = enterTestOption();
    processTestOptionsSelected(optionSelected, curPoint);
}

void Setup::showUserTestOptions() {
    cout << "\nPlease select the test you wish to process by typing '1', '2', '3', or type 'q' to quit: \n";
    cout << setw(3) << "" << "1. Equilateral Trianglen\n";
    cout << setw(3) << "" << "2. Square\n";
    cout << setw(3) << "" << "3. Pentagon\n";
}

string Setup::enterTestOption() {
    string optionSelected;
    cout << "\nEnter here: "; cin >> optionSelected;
    debug1.show("User entered", optionSelected);
    return optionSelected;
}

void Setup::processTestOptionsSelected(string optionSelected, Point curPoint) {
    if (optionSelected == "1")
        coreOps.performFirstTest(curPoint);
    else if (optionSelected == "2")
        coreOps.performSecondTest(curPoint);
    else if (optionSelected == "3")
        coreOps.performThirdTest(curPoint);
    else if (optionSelected == "q")
        exit(0);
    else {
        cout << "\nPlease enter a valid input!\n";
        promptUserToSelectTestOptions(curPoint);
    }
}



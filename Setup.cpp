#include <iostream>
#include <iomanip>
#include "Setup.h"
#include "CoreOperations.h"
#include "extern.h"

using namespace std;

CoreOperations coreOps;

void Setup::startUpProcess() {
	cout << "Welcome to the Chaos Game!\n";
	initializeGrid();
	promptUserToSelectTestOptions();
}

void Setup::initializeGrid() {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++)
            grid[i][j] = "  "; // all cells that are not "on" are set at this state by default
    }
}

void Setup::promptUserToSelectTestOptions() {
    showUserTestOptions();
    string optionSelected = enterTestOption();
    processTestOptionsSelected(optionSelected);
}

void Setup::showUserTestOptions() {
    cout << "\nPlease select the test you wish to process by typing '1', '2', '3', '4', or type 'q' to quit: \n";
    cout << setw(3) << "" << "1. Triangle\n";
    cout << setw(3) << "" << "2. Square\n";
    cout << setw(3) << "" << "3. Pentagon\n";
    cout << setw(3) << "" << "4. Custom Test\n";
}

string Setup::enterTestOption() {
    string optionSelected;
    cout << "\nEnter here: "; getline(cin, optionSelected);
    return optionSelected;
}

void Setup::processTestOptionsSelected(string optionSelected) {
    if (optionSelected == "1")
        coreOps.performFirstTest();
    else if (optionSelected == "2")
        coreOps.performSecondTest();
    else if (optionSelected == "3")
        coreOps.performThirdTest();
    else if (optionSelected == "4")
        coreOps.performCustomTest();
    else if (optionSelected == "q")
        exit(0);
    else {
        cout << "\nPlease enter a valid input!\n";
        promptUserToSelectTestOptions();
    }
}



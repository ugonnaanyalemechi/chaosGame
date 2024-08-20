#include "Debugging.h"
#include "extern.h"
#include <iostream>

using namespace std;

void Debugging::pause() {
    if (allowFlowPause)
        system("pause");
}

void Debugging::show(string msg1, string msg2) { // displays message
    if (showFlow)
        cout << "*** " << msg1 << ": " << msg2 << " ***" << endl;
}

void Debugging::show(string msg, int num) { // displays message and value
    if (showFlow)
        cout << "*** " << msg << ": " << num << " ***" << endl;
}

void Debugging::displayCellsToConsoleOutput(string grid[][1000], int iterations) {
    if (allowConsoleOutputDisplay) {
        if (iterations % 10 == 0) { // updates screen every 10th iteration in this loop
            for (int i = 0; i < MAX_ROWS; i++) {
                for (int j = 0; j < MAX_COLS; j++)
                    cout << grid[i][j];
            }
        }
    }
}
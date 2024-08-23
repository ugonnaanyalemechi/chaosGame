#include <fstream>
#include "Setup.h"
#include "PPMFileManager.h"
#include "extern.h"

const int MAX_ROWS = 1000;
const int MAX_COLS = 1000;
string grid[MAX_ROWS][MAX_COLS];

int main() {
    fstream outputFile;
    Setup setup;
    PPMFileManager fileManager;

    setup.startUpProcess();
    fileManager.transferToFileProcess(outputFile);

    return 0;
}
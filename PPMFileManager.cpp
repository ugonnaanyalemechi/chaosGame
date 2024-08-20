#include <iostream>
#include "PPMFileManager.h"
#include "Debugging.h"
#include "extern.h"

using namespace std;

Debugging debug3;

void PPMFileManager::transferToFileProcess(fstream& outputFile) {
    promptUserToEnterFileToSave(outputFile);
    createPPMHeader(outputFile);
    transferTestDataToFile(outputFile);

    outputFile.close();
}

void PPMFileManager::promptUserToEnterFileToSave(fstream& outputFile) {
    cout << "\nPlease enter the name for the PPM file you would like to save, or type 'q' to quit.\n";
    cout << "(Do not include the extension)\n\n";
    string fileName = enterOutputFileName();
    if (fileName == "q")
        exit(0);
    openOutputFile(outputFile, fileName);
}

string PPMFileManager::enterOutputFileName() {
    string fileName;
    cout << "Enter here: "; cin.ignore(); getline(cin, fileName);
    fileName = fileName + ".ppm";
    debug3.show("File name used", fileName);
    return fileName;
}

void PPMFileManager::openOutputFile(fstream& outputFile, string fileName) {
    outputFile.open(fileName, ios::out); // ios::out allows for a file to be created if the file user specified does not exist
    if (!outputFile) { // if file was not found/not created successfully
        declareFileOpenFail(fileName);
        promptUserToEnterFileToSave(outputFile);
    }
}

void PPMFileManager::declareFileOpenFail(string fileName) {
    cerr << "\nOops, can't open the specified file; no such file or directory.";
    cerr << "\nThe file name used was: " << fileName << "\n";
}

void PPMFileManager::ppmOutputColor(fstream& outputFile, int redValue, int greenValue, int blueValue) {
    outputFile << redValue << " ";
    outputFile << greenValue << " ";
    outputFile << blueValue << " ";
}

void PPMFileManager::createPPMHeader(fstream& outputFile) {
    outputFile << "P3\n";
    outputFile << MAX_ROWS << " " << MAX_COLS << "\n";
    outputFile << "255\n";
}

void PPMFileManager::transferTestDataToFile(fstream& outputFile) {
    cout << "\nProcessing...\n";
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (grid[i][j] == "X ")
                ppmOutputColor(outputFile, 0, 0, 0);
            else if (grid[i][j] == "  ")
                ppmOutputColor(outputFile, 255, 255, 255);
        }
    }
    cout << "\nAll done!\n";
}


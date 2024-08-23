#include <iostream>
#include <string>
#include "PPMFileManager.h"
#include "CoreOperations.h"
#include "extern.h"

using namespace std;

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
    cout << "Enter here: "; getline(cin, fileName);
    fileName = fileName + ".ppm";
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
    int onR, onG, onB, offR, offG, offB;

    getCellOnColorInputFromUser(onR, onG, onB);
    getCellOffColorInputFromUser(offR, offG, offB);
    cout << "\nProcessing...\n";
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (grid[i][j] == "X ")
                ppmOutputColor(outputFile, onR, onG, onB);
            else if (grid[i][j] == "  ")
                ppmOutputColor(outputFile, offR, offG, offB);
        }
    }
    cout << "\nAll done!\n";
}

void PPMFileManager::getCellOnColorInputFromUser(int& onR, int& onG, int& onB) {
    string onRString, onGString, onBString;

    cout << "\nWhat color would you like for the cells that are on to be displayed as? (RGB format)\n";

    for (int i = 0; i < 3; i++) {
        bool rgbInputIsValid = false;
        while (!rgbInputIsValid) {
            if (i == 0) {
                cout << "R: "; getline(cin, onRString);
                rgbInputIsValid = checkIntegerInputForRGB(onRString);
            }
            else if (i == 1) {
                cout << "G: "; getline(cin, onGString);
                rgbInputIsValid = checkIntegerInputForRGB(onGString);
            }
            else {
                cout << "B: "; getline(cin, onBString);
                rgbInputIsValid = checkIntegerInputForRGB(onBString);
            }
        }
    }
    onR = stoi(onRString); onG = stoi(onGString); onB = stoi(onBString);
}

void PPMFileManager::getCellOffColorInputFromUser(int& offR, int& offG, int& offB) {
    string offRString, offGString, offBString;

    cout << "\nWhat color would you like for the cells that are off to be displayed as? (RGB format)\n";

    for (int i = 0; i < 3; i++) {
        bool rgbInputIsValid = false;
        while (!rgbInputIsValid) {
            if (i == 0) {
                cout << "R: "; getline(cin, offRString);
                rgbInputIsValid = checkIntegerInputForRGB(offRString);
            }
            else if (i == 1) {
                cout << "G: "; getline(cin, offGString);
                rgbInputIsValid = checkIntegerInputForRGB(offGString);
            }
            else {
                cout << "B: "; getline(cin, offBString);
                rgbInputIsValid = checkIntegerInputForRGB(offBString);
            }
        }
    }
    offR = stoi(offRString); offG = stoi(offGString); offB = stoi(offBString);
}

bool PPMFileManager::checkIntegerInputForRGB(string input) {
    CoreOperations coreOps2;
    if (!coreOps2.checkInputIsEmpty(input))
        return false;
    if (!coreOps2.checkInputIsInteger(input))
        return false;
    if (stoi(input) > 255) {
        cout << "\nInvalid input!\n";
        cout << "Choose a number between 0-256\n";
        return false;
    }
    return true;
}

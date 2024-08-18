// -- HEADER FILES -- //
#include <iostream> // Used to display info and gather keyboard input
#include <iomanip> // Used to manipulate stream contents
#include <fstream> // Ussed for file-handling
#include <string> // Used to store messages in string objects

using namespace std;

// -- GLOBAL VARIABLES -- //
const int MAX_ROWS = 1000;
const int MAX_COLS = 1000;
string grid[MAX_ROWS][MAX_COLS];

// -- POINT STRUCTURE -- //
struct Point {
    int xValue = 0;
    int yValue = 0;
};

// -- DEBUGGING -- //
struct Debugging {
    bool showFlow = false;
    bool allowFlowPause = false;
    bool allowConsoleOutputDisplay = false; // use with caution

    void pause() {
        if (allowFlowPause)
            system("pause");
    }
    void show(string msg1, string msg2 = "") { // displays message
        if (showFlow)
            cout << "*** " << msg1 << ": " << msg2 << " ***" << endl;
    }
    void show(string msg, int num) { // displays message and value
        if (showFlow)
            cout << "*** " << msg << ": " << num << " ***" << endl;
    }
    void displayCellsToConsoleOutput(int iterations) {
        if (allowConsoleOutputDisplay) {
            if (iterations % 10 == 0) { // updates screen every 10th iteration in this loop
                for (int i = 0; i < MAX_ROWS; i++) {
                    for (int j = 0; j < MAX_COLS; j++)
                        cout << grid[i][j];
                }
            }
        }
    }
};
Debugging debug;

// -- FUNCTION PROTOTYPES -- //
void welcomeUser();
void initializeGrid();
void turnCellOn(Point);
void findMidpointBetweenTwoPoints(const int, Point[], Point&, Point, Point, int);
void turnFirstInitialPointsOn(Point, Point, Point, Point);
void runFirstTestIterations(Point, Point, Point, Point);
void performFirstTest(Point);
void turnSecondInitialPointsOn(Point, Point, Point, Point, Point);
void runSecondTestIterations(Point, Point, Point, Point, Point);
void performSecondTest(Point);
void turnThirdInitialPointsOn(Point, Point, Point, Point, Point, Point);
void runThirdTestIterations(Point, Point, Point, Point, Point, Point);
void performThirdTest(Point);
void showUserTestOptions();
string enterTestOption();
void processTestOptionsSelected(string, Point);
void promptUserToSelectTestOptions(Point);
string enterOutputFileName();
void openOutputFile(fstream&, string);
void declareFileOpenFail(string);
void promptUserToEnterFileToSave(fstream&);
void createPPMHeader(fstream&);
void transferTestDataToFile(fstream&);

// -- FUNCTION DEFINITIONS -- //
void welcomeUser() {
    cout << "Welcome to the Chaos Game!" << endl;
}
void initializeGrid() {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++)
            grid[i][j] = "  "; // all cells that are not "on" are set at this state by default
    }
    debug.show("Grid initialized");
}
void turnCellOn(Point point) {
    grid[point.xValue][point.yValue] = "X "; // "X" represents a cell that is turned on/true
}
void findMidpointBetweenTwoPoints(const int NUM_POINTS, Point testPoints[], Point& curPoint, Point midpoint, Point chosenPoint, int iterations) {
    int xValueMidpoint = (chosenPoint.xValue + curPoint.xValue) / 2;
    int yValueMidpoint = (chosenPoint.yValue + curPoint.yValue) / 2;
    midpoint = { xValueMidpoint, yValueMidpoint }; // the midpoint between one of the chosen points and current point
    turnCellOn(midpoint);
    curPoint = midpoint; // the midpoint becomes the new current point
    debug.displayCellsToConsoleOutput(iterations);
}
void turnFirstTestInitialPointsOn(Point p1, Point p2, Point p3, Point curPoint) {
    turnCellOn(p1);
    turnCellOn(p2);
    turnCellOn(p3);
    turnCellOn(curPoint);
}
void runFirstTestIterations(Point p1, Point p2, Point p3, Point curPoint) {
    const int NUM_POINTS_IN_FIRST_TEST = 3;
    Point firstTestPoints[NUM_POINTS_IN_FIRST_TEST] = { p1, p2, p3 };
    Point chosenPoint, midpoint;
    int xValueMidpoint, yValueMidpoint;

    for (int i = 0; i < 1000000; i++) {
        chosenPoint = firstTestPoints[rand() % 3]; // a point is randomly selected from the initial defined points
        findMidpointBetweenTwoPoints(NUM_POINTS_IN_FIRST_TEST, firstTestPoints, curPoint, midpoint, chosenPoint, i);
    }
    debug.show("First test iterations complete."); debug.pause();
}
void performFirstTest(Point curPoint) {
    Point p1 = { 700, 220 }, p2 = { 200,500 }, p3 = { 700,820 };
    turnFirstTestInitialPointsOn(p1, p2, p3, curPoint);
    runFirstTestIterations(p1, p2, p3, curPoint);
}
void turnSecondTestInitialPointsOn(Point p1, Point p2, Point p3, Point p4, Point curPoint) {
    turnCellOn(p1);
    turnCellOn(p2);
    turnCellOn(p3);
    turnCellOn(p4);
    turnCellOn(curPoint);
}
void runSecondTestIterations(Point p1, Point p2, Point p3, Point p4, Point curPoint) {
    const int NUM_POINTS_IN_SECOND_TEST = 4;
    Point secondTestPoints[] = { p1, p2, p3, p4 };
    Point chosenPoint, midpoint;
    int xValueMidpoint, yValueMidpoint;

    for (int i = 0; i < 1000000; i++) {
        chosenPoint = secondTestPoints[rand() % 4]; // a point is randomly selected from the initial defined points
        findMidpointBetweenTwoPoints(NUM_POINTS_IN_SECOND_TEST, secondTestPoints, curPoint, midpoint, chosenPoint, i);
    }
    debug.show("Second test iterations complete."); debug.pause();
}
void performSecondTest(Point curPoint) {
    Point p1 = { 0, 0 }, p2 = { 0,500 }, p3 = { 500,500 }, p4 = { 500, 0 };
    turnSecondTestInitialPointsOn(p1, p2, p3, p4, curPoint);
    runSecondTestIterations(p1, p2, p3, p4, curPoint);
}
void turnThirdTestInitialPointsOn(Point p1, Point p2, Point p3, Point p4, Point p5, Point curPoint) {
    turnCellOn(p1);
    turnCellOn(p2);
    turnCellOn(p3);
    turnCellOn(p4);
    turnCellOn(p4);
    turnCellOn(curPoint);
}
void runThirdTestIterations(Point p1, Point p2, Point p3, Point p4, Point p5, Point curPoint) {
    const int NUM_POINTS_IN_THIRD_TEST = 5;
    Point thirdTestPoints[NUM_POINTS_IN_THIRD_TEST] = { p1, p2, p3, p4, p5 };
    Point chosenPoint, midpoint;
    int xValueMidpoint, yValueMidpoint;

    for (int i = 0; i < 5000000; i++) {
        chosenPoint = thirdTestPoints[rand() % 5]; // a point is randomly selected from the initial defined points
        findMidpointBetweenTwoPoints(NUM_POINTS_IN_THIRD_TEST, thirdTestPoints, curPoint, midpoint, chosenPoint, i);
    }
    debug.show("Third test iterations complete."); debug.pause();
}
void performThirdTest(Point curPoint) {
    Point p1 = { 200, 500 }, p2 = { 350,210 }, p3 = { 350,790 }, p4 = { 675, 300 }, p5 = { 675, 700 };
    turnThirdTestInitialPointsOn(p1, p2, p3, p4, p5, curPoint);
    runThirdTestIterations(p1, p2, p3, p4, p5, curPoint);
}
void showUserTestOptions() {
    cout << "\nPlease select the test you wish to process by typing '1', '2', '3', or type 'q' to quit: " << endl;
    cout << setw(25) << "1. Equilateral Triangle" << endl;
    cout << setw(11) << "2. Square" << endl;
    cout << setw(13) << "3. Pentagon" << endl;
}
string enterTestOption() {
    string optionSelected;
    cout << "\nEnter here: "; cin >> optionSelected;
    debug.show("User entered", optionSelected);
    return optionSelected;
}
void processTestOptionsSelected(string optionSelected, Point curPoint) {
    if (optionSelected == "1")
        performFirstTest(curPoint);
    else if (optionSelected == "2")
        performSecondTest(curPoint);
    else if (optionSelected == "3")
        performThirdTest(curPoint);
    else if (optionSelected == "q")
        exit(0);
    else {
        cout << "\nPlease enter a valid input!" << endl;
        promptUserToSelectTestOptions(curPoint);
    }
}
void promptUserToSelectTestOptions(Point curPoint) {
    showUserTestOptions();
    string optionSelected = enterTestOption();
    processTestOptionsSelected(optionSelected, curPoint);
}
string enterOutputFileName() {
    string fileName;
    cout << "\nEnter here: "; cin.ignore(); getline(cin, fileName);
    debug.show("File name used", fileName);
    return fileName;
}
void openOutputFile(fstream& outputFile, string fileName) {
    outputFile.open(fileName, ios::out); // ios::out allows for a file to be created if the file user specified does not exist
    if (!outputFile) { // if file was not found/not created successfully
        declareFileOpenFail(fileName);
        promptUserToEnterFileToSave(outputFile);
    }
}
void declareFileOpenFail(string fileName) {
    cerr << "\nOops, can't open the specified file; no such file or directory.";
    cerr << "\nThe file name used was: " << fileName << endl;
}
void promptUserToEnterFileToSave(fstream& outputFile) {
    cout << "\nPlease enter the name for the PPM file you would like to save, or type 'q' to quit.";
    string fileName = enterOutputFileName();
    if (fileName == "q")
        exit(0);
    openOutputFile(outputFile, fileName);
}
void ppmOutputColor(fstream& outputFile, int redValue, int greenValue, int blueValue) {
    outputFile << redValue << " ";
    outputFile << greenValue << " ";
    outputFile << blueValue << " ";
}
void createPPMHeader(fstream& outputFile) {
    outputFile << "P3\n" << endl;
    outputFile << MAX_ROWS << " " << MAX_COLS << endl;
    outputFile << "255\n";
}
void transferTestDataToFile(fstream& outputFile) {
    cout << "\nProcessing..." << endl;
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (grid[i][j] == "X ")
                ppmOutputColor(outputFile, 0, 0, 0);
            else if (grid[i][j] == "  ")
                ppmOutputColor(outputFile, 255, 255, 255);
        }
    }
    cout << "\nAll done!" << endl;
}

// -- MAIN -- //
int main() {
    srand(time(0)); // Using a fresh seed value based on time is necesssary to provide a fresh new set of random numbers
    int randomXValue = rand() % 500;
    int randomYValue = rand() % 500;
    Point curPoint = { randomXValue, randomYValue };
    fstream outputFile;

    welcomeUser();
    initializeGrid();
    promptUserToSelectTestOptions(curPoint);
    promptUserToEnterFileToSave(outputFile);
    createPPMHeader(outputFile);
    transferTestDataToFile(outputFile);

    outputFile.close();

    return 0;
}
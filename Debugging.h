#pragma once
#include <string>

using std::string;

class Debugging
{
private:
    bool showFlow = false;
    bool allowFlowPause = false;
    bool allowConsoleOutputDisplay = false;
public:
    void pause();
    void show(string, string  = "");
    void show(string, int);
    void displayCellsToConsoleOutput(string[][1000], int);
};
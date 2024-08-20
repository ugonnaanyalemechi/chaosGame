#pragma once
#include <string>
#include "Point.h"

using std::string;

class Setup 
{
private:
	void initializeGrid();
	void promptUserToSelectTestOptions(Point);
	void showUserTestOptions();
	string enterTestOption();
	void processTestOptionsSelected(string, Point);
public:
	void startUpProcess(Point);
};
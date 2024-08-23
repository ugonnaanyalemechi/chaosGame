#pragma once
#include <string>

using std::string;

class Setup 
{
private:
	void initializeGrid();
	void promptUserToSelectTestOptions();
	void showUserTestOptions();
	string enterTestOption();
	void processTestOptionsSelected(string);
public:
	void startUpProcess();
};
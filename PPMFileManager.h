#pragma once
#include <fstream>

using std::string;
using std::fstream;

class PPMFileManager 
{
private:
	string enterOutputFileName();
	void openOutputFile(fstream&, string);
	void declareFileOpenFail(string);
	void promptUserToEnterFileToSave(fstream&);
	void ppmOutputColor(fstream&, int, int, int);
	void createPPMHeader(fstream&);
	void transferTestDataToFile(fstream&);
public:
	void transferToFileProcess(fstream&);
};
#include <fstream>
#include <wtypes.h>
#include <iostream>

#include "M_WriteDBToFileClass.h"

extern std::vector< std::pair<int, std::wstring>>vectorDB;
extern std::vector< std::pair<int, std::wstring>>CopyVector;
extern std::wstring  WndFolderWatcherDbPath;

int M_WriteDBToFileClass::WriteDBToFileVoid( bool emptyStartDBbool) {

	std::wofstream wfout1;
	wfout1.open(WndFolderWatcherDbPath);/// , std::ios::in);
	if (!wfout1.is_open()) {
		DWORD errorMessageID = ::GetLastError();
		std::cout << "File in not open";
	}

	for (int i = 0; i < 5; i++) {
		wfout1 << vectorDB[i].second;/////////   COMMIT C ÂÅÊÒÎÐÎÌ copyVector
		wfout1 << std::endl;	/////-------------------------------/////////	 
	}
	wfout1.close();
	emptyStartDBbool = true;
	return 0;
};
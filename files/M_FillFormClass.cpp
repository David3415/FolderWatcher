#include <vector>
#include <string>
#include <fstream>
#include <windows.h>

#include "M_FillFormClass.h"
#include "BrowseForFolderClass.h"
#include "M_FillStartFormClass.h"
#include "M_CopyVectorClass.h"


extern bool emptyDBbool;
extern bool emptyStartDBbool;
extern std::vector<std::wstring>newPathsVec;
extern HWND hWndTitleWhenEmpty;
extern std::vector < std::pair<int, std::wstring>>vectorDB;
extern std::wstring  WndFolderWatcherDbPath;
int M_FillFormClass::formLineNumber;

//===================================================================================================================
// ==================================
void M_FillFormClass::CommitChangesVoid() {
	std::wofstream wfout;
	std::wstring tempStr;
	int counter = 0;


	int iter = 5;
	for (int i = 0; i < 4; i++) {
		if (vectorDB[i].second != L"" && !M_CopyVectorClass::CopyVector[i].second.empty()) {
			vectorDB[i].second = M_CopyVectorClass::CopyVector[i].second;
		}
		else if (vectorDB[i].second == L"" && !M_CopyVectorClass::CopyVector[i].second.empty()) {
			vectorDB[i].second = M_CopyVectorClass::CopyVector[i].second;
		}

	}
	wfout.open(WndFolderWatcherDbPath, std::ios::out);
	for (int i = 0; i < 4; i++) {
		wfout << vectorDB[i].second;/////////   COMMIT C ВЕКТОРОМ copyVector
		wfout << std::endl;	/////-------------------------------/////////	 
	}
	counter++;

	emptyStartDBbool = false;
	wfout.close();
	return;
}


bool M_FillFormClass::FillFormVoid(bool isEmptyBool) {
	if (isEmptyBool == false) {
		int counter = 0;
		std::wstring returnStr;
		std::wfstream wfin;
		wfin.open(WndFolderWatcherDbPath);
		std::vector < std::pair<int, std::wstring>>vectorDB;

		while (!wfin.eof()) {
			getline(wfin, returnStr);
			////------------Номер строки Формы-----------------///////////////////
			vectorDB.push_back(make_pair(counter, returnStr));
			if (5 == counter) {
				wfin.close();
				return false;
			}
			counter++;
		}
	}
	ShowWindow(hWndTitleWhenEmpty, SW_SHOW);
	return true;
};


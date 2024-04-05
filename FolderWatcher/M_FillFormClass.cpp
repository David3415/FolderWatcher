#include <vector>
#include <string>
#include <fstream>
#include <windows.h>

#include "M_FillFormClass.h"


extern HWND hWndTitleWhenEmpty;
extern std::vector < std::pair<int, std::wstring>>vectorDB;
extern std::wstring  WndFolderWatcherDbPath;


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


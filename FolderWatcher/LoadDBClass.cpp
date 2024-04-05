#include <string>
#include <fstream>
#include "LoadDBClass.h"

extern std::wstring newPathsVec[];

std::vector<std::wstring>LoadDBClass::LoadDBFunc(std::wstring LoadDBPath) {
	std::vector< std::wstring>newPathsVec{};

	//if (L"%userprofile%\\AppData\\Local\\Temp\\LoadDBTemp.txt") {
	if (L"%userprofile%\\AppData\\Roaming\\NTech\\FolderWatcher\\LoadDBTemp.txt") {
		newPathsVec = {
			L"c:\\Users\\dgagi\\Desktop",
			 L"c:\\Users\\dgagi\\Desktop\\000",
			 L"c:\\Users\\dgagi\\Desktop\\111"
		};

		for (int i = 0; i < 3; i++) {
			newPathsVec[i] = newPathsVec[i];
		}
	}
	else {
		std::wfstream finout;
		std::wstring temp;
		finout.open(LoadDBPath, std::ios::in | std::ios::out);
		int j = 0;
		while (getline(finout, temp)) {
			newPathsVec[j] = temp;
		}
	}
	return newPathsVec;
};


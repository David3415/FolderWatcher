#include <string>
#include <fstream>
#include "LoadDBClass.h"

extern std::wstring newPathsVec[];

std::vector<std::wstring>LoadDBClass::LoadDBFunc(std::wstring LoadDBPath) {
	std::vector< std::wstring>newPathsVec{};

	if (L"%userprofile%\\AppData\\Local\\Temp\\LoadDBTemp.txt") {
		newPathsVec = {
			//L"\\\\FILESERVER-2\\Для всех\\ГРУППА ДИЗАЙНА",L"\\\\STOR1\\ingest hr\\ГРУППА ДИЗАЙНА",L"F:\\EFIR"
			 //L"c:\\Users\\dgagi\\Desktop",L"c:\\Users\\dgagi\\Desktop\\000",L"c:\\Users\\dgagi\\Desktop\\Адаптивная верстка"

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


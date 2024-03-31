#include <string>
#include <fstream>
#include <windows.h>
#include <vector>
#include "M_FillStartFormClass.h"

std::vector< std::pair<int, std::wstring>> M_FillStartFormClass::FillStartFormVoid(std::wstring path) {

	int counter = 0;

	std::wstring returnStr;
	std::wfstream wfin;
	wfin.open(path);

	std::vector < std::pair<int, std::wstring>>tempDB{ {0,L""}, {0,L""}, {0,L""}, {0,L""},{0,L""} };;
	for(int i=0; i<5; i++){
		getline(wfin, returnStr);
		if (5==counter) {
			wfin.close();
			return tempDB;
		}
		tempDB[i]=(make_pair(counter, returnStr));
		counter++;
	}
};

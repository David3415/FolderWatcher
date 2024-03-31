#define _CRT_SECURE_NO_WARNINGS
#include "M_CheckEmptyDBClass.h"
#include <iostream>

extern std::wstring WndFolderWatcherDbPath;


bool M_CheckEmptyDBClass::CheckEmptyDBVoid() {
	/*FILE* file;
	size_t size;
	wchar_t buf[100]{};
	file = _wfopen(&WndFolderWatcherDbPath[0], L"r");
	
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	if (size == 0) {
		return true;
	}*/
	return false;
};
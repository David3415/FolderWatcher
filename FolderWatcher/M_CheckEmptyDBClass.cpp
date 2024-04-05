#define _CRT_SECURE_NO_WARNINGS
#include "M_CheckEmptyDBClass.h"
#include <iostream>

extern std::wstring WndFolderWatcherDbPath;


bool M_CheckEmptyDBClass::CheckEmptyDBVoid() {
	FILE* file{};
	size_t size{};
	wchar_t buf[100]{};

	if (_wfopen_s(&file, &WndFolderWatcherDbPath[0], L"rb") != 0) {
		std::cout << "err opening file" << std::endl;
	}

	if (file) {
		fseek(file, 0, SEEK_END);
		size = ftell(file);
		fclose(file);
		return false;
	}
	if (size < 10) {
		fseek(file, 0, SEEK_SET);
		fclose(file);

		//// если файл пустой
		return false;
	}
	fclose(file);
	return true;
};
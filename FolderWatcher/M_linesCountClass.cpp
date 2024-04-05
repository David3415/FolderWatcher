#include <string>
#include <fstream>
#include "M_linesCountClass.h"
 
int M_linesCountClass::linesCount;

int M_linesCountClass::linesCountVoid(std::wstring path) {
	std::wfstream fin(path);
	M_linesCountClass::linesCount = std::count(std::istreambuf_iterator<wchar_t>(fin), std::istreambuf_iterator<wchar_t>(), '\n');
	fin.close();
	return M_linesCountClass::linesCount;
};

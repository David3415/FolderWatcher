#pragma once
#include <string>
#include <fstream>
#include <windows.h>
#include <vector>

class M_FillStartFormClass
{
public:
	static std::vector < std::pair<int, std::wstring>> FillStartFormVoid(std::wstring path);
		std::vector < std::pair<int, std::wstring>>tempDB;
	std::wstring returnStr;
	std::wfstream wfin;
	int counter;
};

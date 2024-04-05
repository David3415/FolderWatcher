#pragma once
#include <string>
#include <fstream>

class M_linesCountClass
{
public:
	static int linesCount;
	static int linesCountVoid(std::wstring path);
	std::wfstream fin(std::wstring path);
};


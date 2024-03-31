#pragma once
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <string>
#include <vector>


static class LoadDBClass
{
public:
	std::vector<std::wstring> newPathsVec;
	static std::vector<std::wstring>LoadDBFunc(std::wstring);
};

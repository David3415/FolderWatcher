#pragma once
#include <string>
#include <fstream>
#include "M_CopyVectorClass.h"
extern std::vector< std::pair<int, std::wstring>>vectorDB;

class M_CompareVectors
{
public:
	bool M_CheckExistStrInDBVoid(std::vector< std::pair<int, std::wstring>>CopyVector,
		std::vector< std::pair<int, std::wstring>>vectorDB);

};


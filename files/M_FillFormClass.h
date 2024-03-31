#pragma once
#include <string>
#include <fstream>
#include <windows.h>
#include <vector>

class M_FillFormClass
{
public:
	static bool FillFormVoid(bool isEmptyBool);
	static int  formLineNumber;
	static void CommitChangesVoid();

	static std::wstring path;
	//static inline const std::wstring WndFolderWatcherDbPath = L"WndFolderWatcherDbPath.txt";

	/*#define VECTORDB static std::vector < std::pair<int, std::wstring>>vectorDB;
	#define VECTORDBVOID std::vector < std::pair<int, std::wstring>>CopyVectorVoid();*/
};


#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <thread>
#include <map>
#include <windows.h>
#include <vector>
#include "DisplayPathInfoClass.h"
#include "NewSmallWndClass.h"

class DetectNewFileClass
{
public:
	// bool mainThreadLoopBool;
	static void DetectNewFileVoid();
	HINSTANCE hInst;
	HINSTANCE hPrevInstance;
	LPSTR lpCmdLine;
	int nShowCmd;
	std::wstring LoadDBPath;
	LPCTSTR p_sound;
	HWND hWnd;
	std::wstring directory_path;

};

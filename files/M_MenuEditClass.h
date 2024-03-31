#pragma once
#include <vector>
#include <windows.h>
#include <Tlhelp32.h>
#include <windowsx.h>
#include <algorithm>
#include <shobjidl.h> 
#include <shlobj.h>
#include <sys/types.h>
#include <sys/stat.h>

class M_MenuEditClass
{
public:
	static LRESULT CALLBACK MenuEditCallBackVoid(HWND hWndSet, UINT uMsgSet, WPARAM wParam, LPARAM lParam);
	static bool mainThreadLoopBool;
	
};
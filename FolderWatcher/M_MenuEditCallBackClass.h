#pragma once
#include <windows.h>


class M_MenuEditCallBackClass
{
public:
	static LRESULT CALLBACK MenuEditCallBackVoid(HWND hWndSet, UINT uMsgSet, WPARAM wParam, LPARAM lParam);
	static bool mainThreadLoopBool;
	
};
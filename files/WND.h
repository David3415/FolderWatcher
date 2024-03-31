#pragma once
#include <string>
#include <windows.h>

class WND
{
public:
	class wnd {
	public:
		static LRESULT CALLBACK wndCallbackVoid(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
		PAINTSTRUCT ps;
		HDC hdc;
		RECT rect;
		HWND hwnd;


		wnd(HINSTANCE hInst, wchar_t* winname, bool _mainwindow, int nShowCmd);
		WNDCLASS wc;
	};
};

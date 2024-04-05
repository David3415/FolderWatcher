#include <vector>
#include <iostream>

#include "NewSmallWndClass.h"
#include "M_MenuEditCallBackClass.h"
#include "thread"


std::vector<HWND>formsVec;
extern HWND hwnd;
extern std::wstring ws;

int NewSmallWndClass::NewSmallWndVoid()// HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd
{
	std::wstring ws = L"First";
	wchar_t* ws_t = &ws[0];
	WND::wnd w(NULL, NULL, NULL, NULL);
	formsVec.push_back(w.hwnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

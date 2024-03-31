#include "NewSmallWndClass.h"
#include <vector>
#include "M_MenuEditClass.h"
#include "thread"
#include <iostream>

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

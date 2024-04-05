#include "WND.h"
#include <vector>
#include <iostream>
#include <thread>

#define WMAIN_CLASSNAME L"MyClassName"
#define WMAIN_CAPTION L"Test Window"

extern std::vector<HWND>formsVec;

std::vector<std::wstring>newPathsVec;
int j{};
int resPos;
unsigned int WNDSEX_COUNT = 0;

std::wstring wstringForTg;

LRESULT CALLBACK WND::wnd::wndCallbackVoid(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps;
	HDC hdc;
	SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE);
	switch (message)
	{
	case WM_CREATE:
		break;
	case WM_LBUTTONDOWN:
	{

		auto pos = std::find(formsVec.begin(), formsVec.end(), hWnd);
		resPos = pos - formsVec.begin();
		formsVec.erase(pos - 1);
		DestroyWindow(hWnd);

		for (size_t wnd_count_new = resPos; wnd_count_new < formsVec.size(); wnd_count_new++) {
			MoveWindow(formsVec[wnd_count_new], 1670, 900 - 93 * wnd_count_new, 250, 90, 0);
		}
		if (formsVec.size() > 0) {
			WNDSEX_COUNT = formsVec.size() - 1;
		}
		else {
			WNDSEX_COUNT = 0;
		}
	}
	break;
	case WM_RBUTTONDOWN:
	{
		ShellExecuteW(hWnd, L"Open", &newPathsVec[j][0], 0, 0, 1);
		WNDSEX_COUNT = formsVec.size();
	}
	break;
	case WM_SIZE:
		InvalidateRect(hWnd, NULL, true);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		RECT rect;
		GetClientRect(hWnd, &rect);
		SetBkMode(hdc, OPAQUE);
		wstringForTg = newPathsVec[j];
		DrawText(hdc, &newPathsVec[j][0], -1, &rect, DT_SINGLELINE | DT_VCENTER);
		EndPaint(hWnd, &ps);
		break;
	case WM_CLOSE:
		PostQuitMessage(0);

		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}


WND::wnd::wnd(HINSTANCE hInst, wchar_t* winname, bool _mainwindow, int nShowCmd) {
	HWND hwnd;
	WNDCLASS wc = { 0 };
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hInstance = hInst;
	wc.lpfnWndProc = &WND::wnd::wndCallbackVoid;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpszClassName = WMAIN_CLASSNAME;
	wc.lpszMenuName = NULL;
	RegisterClass(&wc);
	hwnd = CreateWindowEx(WS_EX_TOPMOST | WS_EX_TRANSPARENT, WMAIN_CLASSNAME, winname,
		WS_POPUP | WS_VISIBLE | WS_EX_TOPMOST,
		1670, 900 - 93 * WNDSEX_COUNT, 250, 90, HWND_DESKTOP, NULL, hInst, 0);
};



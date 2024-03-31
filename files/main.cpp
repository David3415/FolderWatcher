#include <windows.h>
#include "M_MenuEditClass.h"
#include <thread>
#include <mutex>
#include "M_FillFormClass.h"

#define WMAIN_CLASSNAME L"MyClassName"
#define WMAIN_CAPTION L"Test Window"

const int width = 800;
const int height = 350;

NOTIFYICONDATA pnid;



int WinMain1(HINSTANCE hInstance, HINSTANCE hInstance1, LPSTR cmdLine, int cmdShow)
{

	HWND hMainWnd;

	const  char* text = { "Text for tooltip" };

	WNDCLASSEX wc;

	memset(&wc, 0, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hbrBackground = (HBRUSH)GetStockObject(0);
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = &M_MenuEditClass::MenuEditCallBackVoid;
	wc.lpszClassName = L"trayer";

	RegisterClassEx(&wc);

	hMainWnd = CreateWindow(L"trayer", L"Trayer", WS_OVERLAPPEDWINDOW,
		(GetSystemMetrics(SM_CXSCREEN) - width) / 2, (GetSystemMetrics(SM_CYSCREEN) - height) / 2,
		width, height, 0, 0, hInstance, 0);

	ShowWindow(hMainWnd, SW_SHOW);

	pnid.cbSize = sizeof(pnid);
	pnid.hWnd = hMainWnd;
	pnid.hIcon = LoadIcon(0, IDI_APPLICATION);
	pnid.uID = 15;
	pnid.uFlags = NIF_ICON | NIF_TIP | NIF_MESSAGE;
	pnid.uCallbackMessage = 15666;
	memcpy(pnid.szTip, text, 17);

	MSG uMsg;
	while (GetMessage(&uMsg, 0, 0, 0))
	{
		TranslateMessage(&uMsg);
		DispatchMessage(&uMsg);
	}
	return uMsg.wParam;
}

int main() {//

	system("FWLoader.exe"); //"E:\\VS\\FWLoader\\x64\\Release\\FWLoader.exe");

	HINSTANCE hInstance{};
	HINSTANCE hInstance1{};
	LPSTR cmdLine{};
	int cmdShow{};
	WinMain1(hInstance, NULL, cmdLine, 0);
}




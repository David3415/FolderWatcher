#include <vector>
#include <windows.h>
#include <string>

#include "M_FillFormClass.h"
#include "M_FillStartFormClass.h"
#include "M_CheckEmptyDBClass.h"
#include "M_CopyVectorClass.h"

#include "M_MenuEditCallBackClass.h"
#include "TgClass.h"
#include "DetectNewFileClass.h"
#include "BrowseForFolderClass.h"
#include "M_CompareVectors.h"
#include "WND.h"
#include "M_WriteDBToFileClass.h"


///----------------------------------------------------------------------------------------------------------- <summary>
///----------------------------------------		ГЛОБАЛЬНЫЕ	----------------------------------------

bool dataChandgeBool = false;
bool emptyDBbool = false;	//Если форма была  пуста на момент нажатия ОК
bool emptyStartDBbool = true;	//Если форма была  пуста на момент запуска приложения
std::vector< std::pair<int, std::wstring>>vectorDB{ {0,L""}, {0,L""}, {0,L""}, {0,L""},{0,L""} };
std::vector < std::pair<int, std::wstring>>CopyVector{ {0,L""}, {0,L""}, {0,L""}, {0,L""},{0,L""} };
POINT pt{};

HWND hWndUser[5]{};
HWND hWndOK{};
HWND hWndEditButt{};
HWND hWndCheckBox{};
HWND hWndTitleWhenEmpty{};
extern NOTIFYICONDATA pnid;
extern  std::vector<HWND>formsVec;
std::wstring  WndFolderWatcherDbPath = L"e:\\VS\\FolderWatcher\\FolderWatcher\\FolderWatcherDb.txt";



///----------------------------------------   СТАТИЧЕСКИЕ  ---------------------------------------------
bool M_MenuEditCallBackClass::mainThreadLoopBool;
///------------------------------------------------------------------------------------------------------


constexpr auto hOK = 1010;
constexpr auto hCancellButt = 1009;
constexpr auto CHECKBOX = 1011;


LRESULT CALLBACK M_MenuEditCallBackClass::MenuEditCallBackVoid(HWND hWndSet, UINT uMsgSet, WPARAM wParam, LPARAM lParam) {

	std::mutex _mutex;
	char* buffer1{};
	constexpr auto LOGINSIZE = 10;
	int lineNumber{};
	HDC hdc{};
	HBRUSH  hbrBkgnd{};


	//+++++++++++++++++++++++++++++++++++++++++++ switch (wParam) ++++++++++++++++++++++++++++++++++++++++


	switch (wParam) {
		//-----------------------  ЗАПУСКАЕМ ПРОЦЕСС ДЛЯ TELEGRAMM----------------------------- 
	case 1011:
	{
		if (0 == BN_CLICKED) {
			std::thread th_TgThread(&TgClass::TgVoid);
			th_TgThread.detach();
		}
		return 0;
	}

	case hCancellButt:
	{
		dataChandgeBool = false;
		return 0;
	}
	////-----------------------------------------------------------------------------------

	case hOK:
	{
		M_CompareVectors  M_CompareVectors;
		if (M_CompareVectors.M_CheckDBChandgeVoid(emptyStartDBbool || emptyDBbool == false)) {
			{
				emptyDBbool = false;										//Проверяем наличие изменений
				M_WriteDBToFileClass::WriteDBToFileVoid(emptyStartDBbool); //Если изменения есть, то записываем в файл
			}

			/////----------------------------------------------Запускаем поток маленьких окон--------------------------------------
			if (mainThreadLoopBool == false) {
				std::thread MainThread(&DetectNewFileClass::DetectNewFileVoid);
				MainThread.detach();
				mainThreadLoopBool = true;
			}
			////-------------------------------------------------------------------------------
			
			emptyStartDBbool = false;
			Shell_NotifyIcon(NIM_ADD, &pnid);
			ShowWindow(pnid.hWnd, SW_HIDE);

			return 0;
		};
	}
	}


	/////========================================  ОбРАбОТКА СООбЩЕНИЙ ФОРМ  ================================

	switch (uMsgSet)
	{
	case WM_CREATE:
	{
		hWndTitleWhenEmpty = CreateWindowExW(0, L"EDIT", L"DB is empty, choose at least one folder", // Заголовок 
			WS_CHILD | WS_DISABLED | BS_FLAT,
			30, 10, 300, 30, hWndSet, reinterpret_cast<HMENU>(1012), NULL, NULL);

		////=========================================ЗАПОЛНЯЕМ ВЕКТОР vectorDB С БД ЕСЛИ ОНА НЕ ПУСТАЯ====================

		auto tempDB = M_FillStartFormClass::FillStartFormVoid(WndFolderWatcherDbPath);
		for (int i = 0; i < 5; i++) {
			vectorDB[i] = tempDB[i];
		}


		//++++++++++++++++++++++++++++++++++++++++++++++++РИСУЕМ ФОРМЫ ДЛЯ КАТАЛОГОВ +++++++++++++++++++++
		for (lineNumber = 0; lineNumber < 5; lineNumber++) {
			hWndUser[lineNumber] = CreateWindowExW(0, L"EDIT", L"",
				WS_CHILD | WS_VISIBLE | WS_BORDER | WS_DISABLED,
				30, 40 + lineNumber * 40, 720, 30, hWndSet, reinterpret_cast<HMENU>(1002), NULL, NULL);
		}

		////++++++++++++++++++++++++++++++++++++++++++++++++ЗАПОЛНЯЕМ ФОРМЫ ЕСЛИ DB НЕ ПУСТАЯ++++++++++++++++++++++++++++++++++++
		auto res = M_CheckEmptyDBClass::CheckEmptyDBVoid();
		if (res != 0) {
			for (lineNumber = 0; lineNumber < 5; lineNumber++) {
				hWndUser[lineNumber] = CreateWindowExW(0, L"EDIT", &vectorDB[lineNumber].second[0],
					WS_CHILD | WS_VISIBLE | WS_BORDER | WS_DISABLED,
					30, 40 + lineNumber * 40, 720, 30, hWndSet, reinterpret_cast<HMENU>(1002), NULL, NULL);
			}
		}
		else {
			ShowWindow(hWndTitleWhenEmpty, SW_SHOW);//<<<<<<<<<<<<<<<<<<<<<<<<<<<<-------ЕСЛИ БД ПУСТАЯ
			emptyDBbool = true;
			emptyStartDBbool = true;
		}


		//++++++++++++++++++++++++++++++++++++++++++++++++РИСУЕМ ОСТАЛЬНЫЕ КОНТРОЛЫ++++++++++++++++++++++++++++++++++

		hWndEditButt = CreateWindowExW(0, L"BUTTON", L"EDIT ", // 
			WS_CHILD | WS_VISIBLE | BS_FLAT,
			550, 240, 90, 30, hWndSet, reinterpret_cast<HMENU>(1009), NULL, NULL);
		hWndOK = CreateWindowExW(0, L"BUTTON", L"OK ", // 
			WS_CHILD | WS_VISIBLE | BS_FLAT,
			660, 240, 90, 30, hWndSet, reinterpret_cast<HMENU>(1010), NULL, NULL);
		hWndCheckBox = CreateWindowExW(0, L"BUTTON", L"Telegram notify", // 
			WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX | BS_FLAT | WS_BORDER,
			380, 240, 150, 30, hWndSet, reinterpret_cast<HMENU>(1011), NULL, NULL);

	}
	return 0;


	///////+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	/*case WM_CTLCOLORSTATIC:
	{
		return (LRESULT)CreateSolidBrush(RGB(255, 255, 255));
	}
	break;*/

	/*case WM_CTLCOLORSTATIC:
	{
		hdc = (HDC)wParam;
		SetTextColor(hdc, RGB(0,0,0));
		SetBkColor(hdc, RGB(255,255,255));

		return (INT_PTR)hbrBkgnd;
	}*/

	static HBRUSH hBrush = CreateSolidBrush(RGB(55, 255, 255));

	////++++++++++++++++++++++++++++++++++++++++++++++++ИСПРАВИТЬ++++++++++++++++++++++++++++++++++++++++++++++++++++
	case WM_CTLCOLORSTATIC:
	{/*
		if (hWndOK == (HWND)lParam)
		{*/
		auto CtrlID = GetDlgCtrlID((HWND)lParam);
		if (CtrlID == 1011) //If desired control
		{
			HDC hdcStatic = (HDC)wParam;
			//SetTextColor(hdcStatic, RGB(0, 0, 0));
			SetBkColor(hdcStatic, RGB(255, 255, 255));

		}
		return (INT_PTR)hBrush;
	}


	case WM_CLOSE:
	{
		DestroyWindow(hWndSet);
		PostQuitMessage(0);
	}
	break;
	case 15666:
		if (lParam == WM_LBUTTONDOWN)
		{
			_mutex.lock();
			Shell_NotifyIcon(NIM_DELETE, &pnid);
			ShowWindow(hWndSet, SW_SHOW);
			//MenuEditClass::MenuEditVoid();
			//DestroyWindows(); //Сообщение закрытия всех маленьких окон
			_mutex.unlock();
		}
		break;

	case WM_COMMAND:
	{

	case WM_LBUTTONDOWN:
	{
		//////+++++++++++++++++++++++++++++++++++++  ОБКАБОТКА НАЖАТИЯ НА ПОЛЕ ВЫБОРА КАТАЛОГОВ   ++++++++++++++++++++++++ 

		pt.x = GET_X_LPARAM(lParam);
		pt.y = GET_Y_LPARAM(lParam);

		if (pt.x > 70 && pt.x < 680) {
			if (pt.y > 40 && pt.y < 70) {
				lineNumber = 0;
			}
			else if (pt.y > 80 && pt.y < 110) {
				lineNumber = 1;
			}
			else if (pt.y > 120 && pt.y < 150) {
				lineNumber = 2;
			}
			else if (pt.y > 160 && pt.y < 190) {
				lineNumber = 3;
			}
			else if (pt.y > 200 && pt.y < 230) {
				lineNumber = 4;
			}
			else break;


			HWND hwnd{};
			std::wstring title;
			std::wstring folder;

			std::wstring temp = BrowseForFolderClass::BrowseForFolderVoid(hwnd, title, folder);
			size_t sz_temp = wcslen(&temp[0]) + 2;
			//////++++++++++++++++++++++++++++++++  КОПИРОВАНИЕ СТРОК ВО ВРЕМЕННЫЙ ВЕКТОР CopyVector ++++++++++++++++++++++++
			int returnVal = M_CopyVectorClass::CopyVectorVoid(lineNumber, &temp[0]);
			//////+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			if (returnVal == 0) {
				buffer1 = (char*)malloc(sz_temp + 1);
				size_t* dummy{};
				wcstombs_s(dummy, buffer1, sz_temp, &temp[0], _TRUNCATE);
				SetWindowTextA(hWndUser[lineNumber], buffer1);
				dataChandgeBool = true;
				emptyDBbool = false;
			}
			else { SetWindowTextW(hWndTitleWhenEmpty, L"String whith the same name already exists in DB"); }
		}
	};
	break;
	}
	}
	return DefWindowProc(hWndSet, uMsgSet, wParam, lParam);
};

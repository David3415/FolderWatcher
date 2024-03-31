#include <thread>
#include <windows.h>
#include <vector>
#include <fstream>

#include "DisplayPathInfoClass.h"
#include "TgClass.h"
#include "DetectNewFileClass.h"
#include "NewSmallWndClass.h"
#include "M_MenuEditClass.h"

#define WMAIN_CLASSNAME L"MyClassName"
#define WMAIN_CAPTION L"Test Window"


extern vector<HWND>formsVec;
extern int j;
int G = 400;

bool start = false;
int childsIndsex{};
int wnd_counter{};

extern std::vector<std::wstring>newPathsVec; // здесь база с путят
extern std::wstring WndFolderWatcherDbPath;

HWND hwndOwner{};
HINSTANCE hinst{};
extern unsigned int WNDSEX_COUNT;

void DetectNewFileClass::DetectNewFileVoid() {
	LPCTSTR p_sound = L"c:\\Users\\dgagi\\Desktop";					//грузим звук

	int strCount{};

	this_thread::sleep_for(5000ms);
	HWND hWnd = GetForegroundWindow();///-------------Прячем консоль
	ShowWindow(hWnd, SW_HIDE);//------------------------------------------------------

	//L"\\\\fileserver-2\\Для всех\\группа дизайна", L"\\\\Stor1\\ingest hr\\ГРУППА ДИЗАЙНА", L"F:\EFIR";

	std::wfstream finout(WndFolderWatcherDbPath);
	std::wstring temp;
	while (!finout.eof()) {
		std::getline(finout, temp);
		if (temp.size() != 0) {
			strCount++;
		}
	}
	finout.close();

	std::wfstream finout2(WndFolderWatcherDbPath);
	
	newPathsVec.clear();
	while (newPathsVec.size() != strCount) {
		getline(finout2, temp);
		newPathsVec.push_back(temp);
	}
	finout2.close();

	////----------------------------------количество файлов в папке----------------
	DisplayPathInfoClass displayPathInfoClass{};
	vector<int> oldValVec{};
	oldValVec.clear();
	for (int i = 0; i < strCount; i++) {//newPathsVec.size() - 1
		oldValVec.push_back(displayPathInfoClass.DisplayPathVoid(newPathsVec[i]));
	};
	unsigned int newVal{};// новое количество файлов в папке
	bool yep = false;

	try
	{
		while (M_MenuEditClass::mainThreadLoopBool)
		{
			for (j = 0; j < strCount; j++) {
				std::this_thread::sleep_for(chrono::milliseconds(500));
				newVal = displayPathInfoClass.DisplayPathVoid(newPathsVec[j]);
				if (newVal > oldValVec[j]) {

					G = 11024;
					if (start == false) { start = true; };
					childsIndsex += j;
					oldValVec[j] = newVal;

					std::thread th_MainDialog(NewSmallWndClass::NewSmallWndVoid);
					th_MainDialog.detach();

					Beep(700, 300);
					Beep(700, 300);
					wnd_counter++;
					yep = true;
					WNDSEX_COUNT++;
				}
			}
		}
	}
	catch (...) { std::cout << "Error!" << std::endl; }
};

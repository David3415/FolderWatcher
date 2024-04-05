#include <windows.h>
#include <vector>
#include <fstream>
#include <chrono>
#include <iostream>
#include <thread>

#include "TgClass.h"
#include "DetectNewFileClass.h"
#include "NewSmallWndClass.h"
#include "M_MenuEditCallBackClass.h"

#define WMAIN_CLASSNAME L"MyClassName"
#define WMAIN_CAPTION L"Test Window"


extern std::vector<HWND>formsVec;
extern int j;

int GFunc = 400;

bool start = false;
int childsIndsex{};
int wnd_counter{};

extern std::vector<std::wstring>newPathsVec; // здесь база с путями
extern std::wstring WndFolderWatcherDbPath;

HWND hwndOwner{};
HINSTANCE hinst{};
extern unsigned int WNDSEX_COUNT;

void DetectNewFileClass::DetectNewFileVoid() {
	LPCTSTR p_sound = L"c:\\Users\\dgagi\\Desktop";					//грузим звук

	int strCount{};

	//std::this_thread::sleep_for(5000);
	
	
	////-------------------------------------------------------------------------------------------
	////		Считываем Файл с путями WndFolderWatcherDbPath в вектор newPathsVec 
	////-------------------------------------------------------------------------------------------

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

		
	////-------------------------------------------------------------------------------------------
	////				Цикл подсчёта количество файлов в папке.
	//					Алгоритм: 
	//					Сначала в цикле считаем количество файлов в каталогах взятых из файла WndFolderWatcherDbPath и
	//					помещаем в Вектор oldValVec
	//							
	//					Затем запускаем Непрерывный цикл, с паузами, и опять считаем по очереди количество файлов  
	//					в каталогах из файла WndFolderWatcherDbPath и количество записываем в переменную NewVal.
	//					
	//					Каждое полученное значение newTempVal(Новое кол-во файлов в каталоге) сравниваем с соответствующим
	//					значением oldValVec[i].
	//					Если значения не равны, значит появился новый файл. Запускается процесс th_MainDialog с
	//					NewSmallWndVoid и создаёт маленькое окно 
    ////-------------------------------------------------------------------------------------------
	
	FilesInDirCountClass FilesInDirCountClass{};

	std::vector<int> oldValVec{};	//количество файлов в каталогах
	unsigned int newTempVal{};		// новое количество файлов в папке newPathsVec[j]
	oldValVec.clear();              

	for (int i = 0; i < strCount; i++) {
		oldValVec.push_back(FilesInDirCountClass.FilesInDirCountVoid(newPathsVec[i]));
	};
	
	bool yep = false;



	////--------------------------	Основной цикл  -----------------------------------|
	try
	{
		while (M_MenuEditCallBackClass::mainThreadLoopBool)
		{
			for (j = 0; j < strCount; j++) {
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
				
				newTempVal = FilesInDirCountClass.FilesInDirCountVoid(newPathsVec[j]);
				
				if (newTempVal > oldValVec[j]) {///////  Триггер изменений кол-ва файлов к каталог 

					GFunc = 11024;
					if (start == false) { start = true; };
					childsIndsex += j;
					oldValVec[j] = newTempVal;

					std::thread th_MainDialog(NewSmallWndClass::NewSmallWndVoid);  /// Запускмем процесс маленького окна
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

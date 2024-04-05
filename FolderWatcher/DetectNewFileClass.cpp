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

extern std::vector<std::wstring>newPathsVec; // ����� ���� � ������
extern std::wstring WndFolderWatcherDbPath;

HWND hwndOwner{};
HINSTANCE hinst{};
extern unsigned int WNDSEX_COUNT;

void DetectNewFileClass::DetectNewFileVoid() {
	LPCTSTR p_sound = L"c:\\Users\\dgagi\\Desktop";					//������ ����

	int strCount{};

	//std::this_thread::sleep_for(5000);
	
	
	////-------------------------------------------------------------------------------------------
	////		��������� ���� � ������ WndFolderWatcherDbPath � ������ newPathsVec 
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
	////				���� �������� ���������� ������ � �����.
	//					��������: 
	//					������� � ����� ������� ���������� ������ � ��������� ������ �� ����� WndFolderWatcherDbPath �
	//					�������� � ������ oldValVec
	//							
	//					����� ��������� ����������� ����, � �������, � ����� ������� �� ������� ���������� ������  
	//					� ��������� �� ����� WndFolderWatcherDbPath � ���������� ���������� � ���������� NewVal.
	//					
	//					������ ���������� �������� newTempVal(����� ���-�� ������ � ��������) ���������� � ���������������
	//					��������� oldValVec[i].
	//					���� �������� �� �����, ������ �������� ����� ����. ����������� ������� th_MainDialog �
	//					NewSmallWndVoid � ������ ��������� ���� 
    ////-------------------------------------------------------------------------------------------
	
	FilesInDirCountClass FilesInDirCountClass{};

	std::vector<int> oldValVec{};	//���������� ������ � ���������
	unsigned int newTempVal{};		// ����� ���������� ������ � ����� newPathsVec[j]
	oldValVec.clear();              

	for (int i = 0; i < strCount; i++) {
		oldValVec.push_back(FilesInDirCountClass.FilesInDirCountVoid(newPathsVec[i]));
	};
	
	bool yep = false;



	////--------------------------	�������� ����  -----------------------------------|
	try
	{
		while (M_MenuEditCallBackClass::mainThreadLoopBool)
		{
			for (j = 0; j < strCount; j++) {
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
				
				newTempVal = FilesInDirCountClass.FilesInDirCountVoid(newPathsVec[j]);
				
				if (newTempVal > oldValVec[j]) {///////  ������� ��������� ���-�� ������ � ������� 

					GFunc = 11024;
					if (start == false) { start = true; };
					childsIndsex += j;
					oldValVec[j] = newTempVal;

					std::thread th_MainDialog(NewSmallWndClass::NewSmallWndVoid);  /// ��������� ������� ���������� ����
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

#include <string>
#include <fstream>
#include <windows.h>
#include <vector>
#include "M_FillStartFormClass.h"
#include <iostream>

////////---------------------------------------------------------------------------------------------
/////					«десь заполн€ем форму меню, если изнача															    
/////					«десь вызываем приложение UpdateLoader.exe дл€ проверки наличи€ обновлений
/////					если обновление есть, то это приложение закрываетс€и обновл€етс€, затем запускаетс€ заново
//						
//						≈сли обновл. нет,пр€чем консоль, и запускаем функцию MenuEditVoid(),
//						рисующее форму меню
//////// -------------------------------------------------------------------------------------------   


std::vector< std::pair<int, std::wstring>> M_FillStartFormClass::FillStartFormVoid(std::wstring path) {

	int counter = 0;

	std::wstring returnStr;
	std::wfstream wfin;
	wfin.open(path);

	std::vector < std::pair<int, std::wstring>>tempDB{ {0,L""}, {0,L""}, {0,L""}, {0,L""},{0,L""} };;
	for (int i = 0; i < 5; i++) {
		getline(wfin, returnStr);
		if (5 == counter) {
			wfin.close();
			std::wcout << tempDB[0].first;
			return tempDB;
		}
		tempDB[i] = (make_pair(counter, returnStr));

		counter++;
	}
	wfin.close();
	return tempDB;
};

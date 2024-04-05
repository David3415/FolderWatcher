#include "M_CompareVectors.h"
#include <iostream>
#include <fstream>
#include <wtypes.h>

extern std::vector< std::pair<int, std::wstring>>vectorDB;
extern std::vector< std::pair<int, std::wstring>>CopyVector;
extern std::wstring  WndFolderWatcherDbPath;

/////-----------------------------------------------------------------------------------------------
/////	Если в CopyVector нет изменений  то выход - return false;	
/////	Если в CopyVector изменения есть и Файл изначально пуст(vectorDB пуст), просто копируем значения из CopyVector в vectorDB
/////	 
////	Если в CopyVector изменения есть и в файле изначально есть данные(vectorDB не пуст), ищем новые данные		
/////
/////-----------------------------------------------------------------------------------------------


bool  M_CompareVectors::M_CheckDBChandgeVoid(bool emptyStartDBbool) {
	
	///  Проверка на новые данные, если нет - return false;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			auto result = std::find_if(CopyVector.begin(), CopyVector.end(), [i](std::pair<int, std::wstring>_pair) {
				return _pair.second == vectorDB[i].second;
				});
			if (result == end(CopyVector)) {
				return false;
			}
		}
	}


	//Если Файл изначально пуст(vectorDB пуст) и изменения есть, просто копируем значения из CopyVector в vectorDB
	if (emptyStartDBbool) {
		for (int i = 0; i < 5; i++) {
			vectorDB[i].second = CopyVector[i].second;
		}
		return true;
	}

	//Если Файл изначально не пустой и есть изменения
	else {
		for (int i = 0; i < 5; i++) {
			int countIterJ = 0;
			for (int j = 0; j < 5; j++) {
				if (vectorDB[i].second == CopyVector[j].second) {
					vectorDB[i].second = CopyVector[j].second;

					countIterJ++;
					continue;
					/////          итерируем "j" и сравниваем vectorDB[i].second 	
				}					/////		   cо всеми вариантами CopyVector[j].second
			}
			if (countIterJ == 0) {	/////          если по результатам одного цикла "j" число совпадений равно 0,
				vectorDB[i].second = CopyVector[i].second;

				/////          значит есть хотя бы два разных значения, значит изменения есть
			}
		}
	}
	return true;
};
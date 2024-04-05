#include "M_CompareVectors.h"
#include <iostream>
#include <fstream>
#include <wtypes.h>

extern std::vector< std::pair<int, std::wstring>>vectorDB;
extern std::vector< std::pair<int, std::wstring>>CopyVector;
extern std::wstring  WndFolderWatcherDbPath;

/////-----------------------------------------------------------------------------------------------
/////	���� � CopyVector ��� ���������  �� ����� - return false;	
/////	���� � CopyVector ��������� ���� � ���� ���������� ����(vectorDB ����), ������ �������� �������� �� CopyVector � vectorDB
/////	 
////	���� � CopyVector ��������� ���� � � ����� ���������� ���� ������(vectorDB �� ����), ���� ����� ������		
/////
/////-----------------------------------------------------------------------------------------------


bool  M_CompareVectors::M_CheckDBChandgeVoid(bool emptyStartDBbool) {
	
	///  �������� �� ����� ������, ���� ��� - return false;
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


	//���� ���� ���������� ����(vectorDB ����) � ��������� ����, ������ �������� �������� �� CopyVector � vectorDB
	if (emptyStartDBbool) {
		for (int i = 0; i < 5; i++) {
			vectorDB[i].second = CopyVector[i].second;
		}
		return true;
	}

	//���� ���� ���������� �� ������ � ���� ���������
	else {
		for (int i = 0; i < 5; i++) {
			int countIterJ = 0;
			for (int j = 0; j < 5; j++) {
				if (vectorDB[i].second == CopyVector[j].second) {
					vectorDB[i].second = CopyVector[j].second;

					countIterJ++;
					continue;
					/////          ��������� "j" � ���������� vectorDB[i].second 	
				}					/////		   c� ����� ���������� CopyVector[j].second
			}
			if (countIterJ == 0) {	/////          ���� �� ����������� ������ ����� "j" ����� ���������� ����� 0,
				vectorDB[i].second = CopyVector[i].second;

				/////          ������ ���� ���� �� ��� ������ ��������, ������ ��������� ����
			}
		}
	}
	return true;
};
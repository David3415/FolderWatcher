#include <vector>
#include <string>
#include "M_CopyVectorClass.h"
#include "M_CompareVectors.h"

///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ <summary>
///---------------------- ������� ����������� VECTOR DB � CopyVector ����� ���������� VECTOR DB
///---------------------- ���������� ������ ����� � ��������� � CopyVector, �� ������� ���������,
///---------------------- 
///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ </summary>

extern bool emptyDBbool;
extern bool dataChandgeBool;
extern bool emptyStartDBbool;
std::vector < std::pair<int, std::wstring>>M_CopyVectorClass::CopyVector{ {0,L""}, {0,L""}, {0,L""}, {0,L""},{0,L""} };
extern std::vector< std::pair<int, std::wstring>>vectorDB;

int M_CopyVectorClass::CopyVectorVoid(int lineNumber, std::wstring strFromForm) {
	for (int i = 0; i < 5; i++) {
		if (CopyVector[i].second == strFromForm) {
			return 1;
		}
	}
	CopyVector[lineNumber].second = strFromForm;
	return 0;
};


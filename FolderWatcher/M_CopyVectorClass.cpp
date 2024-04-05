#include <vector>
#include <string>
#include "M_CopyVectorClass.h"
#include "M_CompareVectors.h"

///--------------------------------------------------------------------------------------------------------- <summary>
///---------------------- тсмйжхъ йнохпнбюмхъ VECTOR DB б CopyVector оепед хглемемхел VECTOR DB
///---------------------- дюкэмеиьюъ пюанрю асдер я опнундхрэ я CopyVector, дн йнллхрю хглемемхи
///---------------------- 
///--------------------------------------------------------------------------------------------------------- </summary>

extern bool emptyDBbool;
extern bool dataChandgeBool;
extern bool emptyStartDBbool;
extern std::vector < std::pair<int, std::wstring>>CopyVector;
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


#include "M_CompareVectors.h"
extern std::wstring  WndFolderWatcherDbPath;

bool  M_CompareVectors::M_CheckExistStrInDBVoid(std::vector< std::pair<int, std::wstring>>CopyVector,
	std::vector< std::pair<int, std::wstring>>vectorDB) {

	for (int i = 0; i < 5; i++) {
		int count = 0;
		for (int j = 0; j < 5; j++) {
			if (vectorDB[i].second == CopyVector[j].second) {
				count++;
			}
			if (count == 0) {
				return false;
			}
		}
	}
	return true;
}
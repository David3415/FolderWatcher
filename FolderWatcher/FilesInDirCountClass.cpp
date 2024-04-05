#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

#include "FilesInDirCountClass.h"

using namespace std::experimental::filesystem;

int FilesInDirCountClass::FilesInDirCountVoid(path directory_path)
{
	int count = 0;
	for (const auto& file : directory_iterator(directory_path)) {
		count++;
	}
	return count;
};
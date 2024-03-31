#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <string>
#include <vector>
#include <fstream>
#include <experimental/filesystem>
#include <windows.h>
#include "DisplayPathInfoClass.h"

using namespace std;
using namespace std::experimental::filesystem;

int DisplayPathInfoClass::DisplayPathVoid(path directory_path)
{
	int count = 0;
	for (const auto& file : directory_iterator(directory_path)) {
		count++;
	}
	return count;
};
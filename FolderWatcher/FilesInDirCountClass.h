#pragma once
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

#include <experimental/filesystem>
#include <conio.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <windows.h>
#include <tlhelp32.h>
#include <windowsx.h>
#include <algorithm>
#include <shobjidl.h> 
#include <shlobj.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <filesystem>

using namespace std::experimental::filesystem;

class FilesInDirCountClass
{
public:

	int FilesInDirCountVoid(path directory_path);
};
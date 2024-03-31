#pragma once
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
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


using namespace std;
using namespace std::experimental::filesystem;

class DisplayPathInfoClass
{
public:

	int DisplayPathVoid(path directory_path);
	int count;

};
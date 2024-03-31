#include <iostream>
#include <stdlib.h>
#include <vector>
#include <windows.h>
#include <Tlhelp32.h>
#include <windowsx.h>
#include <algorithm>
#include <shobjidl.h> 
#include <shlobj.h>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;
class M_SelectFileClass
{
public:
	LPWSTR SelectFileVoid(

	);

	LPWSTR szSelectedFile;
	wchar_t szFile[260];
	OPENFILENAME ofn;
};

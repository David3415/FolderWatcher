#pragma once
#include <windows.h>
#include <ShlObj_core.h>


class BrowseForFolderClass
{
public:
	static INT CALLBACK BrowseCallbackVoid(HWND hwnd, UINT uMsg, LPARAM lp, LPARAM pData);
	static std::wstring BrowseForFolderVoid(HWND hwnd, std::wstring title, std::wstring folder);
	std::wstring folder;
	BROWSEINFO br;
	LPITEMIDLIST pidl;
	wchar_t buffer[MAX_PATH];
};

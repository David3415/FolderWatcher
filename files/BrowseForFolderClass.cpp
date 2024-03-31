#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <ShlObj_core.h>
#include <iostream>
#include <string>
#include "BrowseForFolderClass.h"
#include "M_FillFormClass.h"


INT CALLBACK BrowseForFolderClass::BrowseCallbackVoid(HWND hwnd, UINT uMsg, LPARAM lp, LPARAM pData)
{
	if (uMsg == BFFM_INITIALIZED) SendMessage(hwnd, BFFM_SETSELECTION, TRUE, pData);
	return 0;
}


std::wstring BrowseForFolderClass::BrowseForFolderVoid(HWND hwnd, std::wstring title, std::wstring folder)
{
	//std::wstring ret;

	BROWSEINFO br;
	ZeroMemory(&br, sizeof(BROWSEINFO));
	br.lpfn = BrowseForFolderClass::BrowseCallbackVoid;
	br.ulFlags = BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE;
	br.hwndOwner = hwnd;
	br.lpszTitle = &title[0];

	//br.lParam = folder[0];

	LPITEMIDLIST pidl = NULL;
	if ((pidl = SHBrowseForFolder(&br)) != NULL)
	{
		wchar_t buffer[MAX_PATH];
		if (SHGetPathFromIDList(pidl, buffer)) folder = buffer;
	}

	return folder;
}

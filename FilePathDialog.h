#pragma once
#include <shobjidl_core.h>
#include <Windows.h>
#include <iostream>
#include <string>
#pragma warning(disable:4996)

using namespace std;

string getFilePathWithDialog() { //Getting the path and the name of the exe file (later used as the name of the reg key value), THIS CODE WAS COPY PASTED LMAO
	
	string path = "";
	HRESULT hr = CoInitializeEx(NULL, COINITBASE_MULTITHREADED |
		COINIT_DISABLE_OLE1DDE);
	if (SUCCEEDED(hr))
	{
		IFileOpenDialog* pFileOpen;

		// Create the FileOpenDialog object.
		hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL,
			IID_IFileOpenDialog, reinterpret_cast<void**>(&pFileOpen));

		if (SUCCEEDED(hr))
		{
			// Show the Open dialog box.
			hr = pFileOpen->Show(NULL);

			// Get the file name from the dialog box.
			if (SUCCEEDED(hr))
			{
				IShellItem* pItem;
				hr = pFileOpen->GetResult(&pItem);
				if (SUCCEEDED(hr))
				{
					PWSTR pszFilePath;
					hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);
					// Display the file name to the user.
					if (SUCCEEDED(hr))
					{
						//MessageBox(NULL, pszFilePath, L"File Path", MB_OK);
						char buffer[500];
						wcstombs(buffer, pszFilePath, 500);
						path = buffer;
						CoTaskMemFree(pszFilePath);
					}
					pItem->Release();
				}
			}
			pFileOpen->Release();
		}
		CoUninitialize();
	}
	return path;
}
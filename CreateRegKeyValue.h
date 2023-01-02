#pragma once
#include <iostream>
#include <string>
#include <codecvt>
#include <locale>

using namespace std;

void CreateR() {   //Creating the Registry key needed for disabling Fullscreen Optimizations

	string subPath = getFilePathWithDialog(); //path for the exe file which ends up as the name of the reg key value
	string path = "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags\\Layers";  //path to the place where the key needs to be created
	wstring WSTRsubPath = wstring_convert<codecvt_utf8<wchar_t>>().from_bytes(subPath);  //converting our path string to wstring, otherwise our value name will be gibberish
	LPCSTR LPCSTRpath = (LPCSTR)path.c_str(); //converting our path to LPCSTR
	LPCWSTR FsubPath = (LPCWSTR)WSTRsubPath.c_str();  //converting our subpath to LPCWSTR
	wstring data = L"~ DISABLEDXMAXIMIZEDWINDOWEDMODE";  //this is our value data, can be modified to change other settings, currently only disables Full Screen Optimizations
	const BYTE* Fdata = (BYTE*)data.c_str();  //converting our string data to BYTE data
	HKEY key;
	LONG read = RegOpenKeyExA(HKEY_CURRENT_USER, LPCSTRpath, 0, KEY_ALL_ACCESS, &key);  //opening the path so we can acquire the needed HKEY
	if (read == ERROR_SUCCESS)
		cout << "Read Success.\n\n";
	else cout << "Error: " << read << endl;  //Look up any errors that might be given here: https://docs.microsoft.com/en-us/windows/win32/debug/system-error-codes--0-499-

	LONG write = RegSetValueExW(key, FsubPath, 0, REG_SZ, Fdata, (data.size() + 1) * (sizeof(wchar_t)));
	if (write == ERROR_SUCCESS)
		cout << "Write Success.\n\n";
	else cout << "Error: " << write << endl;   //Look up any errors that might be given here: https://docs.microsoft.com/en-us/windows/win32/debug/system-error-codes--0-499-
}

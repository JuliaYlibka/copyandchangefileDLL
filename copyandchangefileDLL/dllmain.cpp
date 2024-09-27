// dllmain.cpp : Определяет точку входа для приложения DLL.
//copyandchangefileDLL
#include "pch.h"
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "windows.h"
#include <string>
using namespace std;
BOOL WINAPI DllMain(HINSTANCE hDll,
	DWORD  dwReason,
	LPVOID lpReserved
)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		MessageBox(NULL, "The DLL is loaded", "DLL Skeleton", MB_OK);
		break;
	case DLL_THREAD_ATTACH:
		MessageBox(NULL, "A thread is created in this process", "DLL Skeleton", MB_OK);
		break;
	case DLL_THREAD_DETACH:
		MessageBox(NULL, "A thread is destroyed in this process", "DLL Skeleton", MB_OK);
		break;
	case DLL_PROCESS_DETACH:
		MessageBox(NULL, "The DLL is unloaded", "DLL Skeleton", MB_OK);
		break;
	}
	return TRUE;
}

extern "C" int CountSymbolInFile(string& filename, char c)
{
    int total = 0;
    string fullPath = "C:\\Users\\217041\\Desktop\\" + filename + ".txt";
    FILE* hdl = nullptr;

    errno_t err = fopen_s(&hdl, fullPath.c_str(), "rt");
    char message[80] = { 0 };

    if (err == 0 && hdl != nullptr) {
        int ch;
        while ((ch = fgetc(hdl)) != EOF) {
            if (ch == c) total++;
        }
        printf("(Server): file: %s, symbols = %d\n", fullPath.c_str(), total);
        fclose(hdl);
        return 0;
    }
    else {
        sprintf_s(message, sizeof(message), "(Server): Cannot open %s!", fullPath.c_str());
        printf("%s\n", message);
        return -1; 
    }
}

// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"

extern "C" __declspec(dllexport) bool search_function(const char* str, const char* chars) {
    bool yes = true;

    for (int i = 0; chars[i] != '\0' && yes; ++i) {
        yes = false;

        for (int j = 0; str[j] != '\0'; ++j) {
            if (chars[i] == str[j]) {
                yes = true;
                break;
            }
        }
    }

    return yes;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


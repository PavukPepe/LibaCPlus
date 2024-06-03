
#include <windows.h>
#include <string>﻿
#include <iostream>


using namespace std;
typedef bool (*search_function)(const char*, const char*);

int main()
{
    setlocale(LC_ALL, "Rus");

    HINSTANCE lib = LoadLibrary(TEXT("LibaCPlus.dll"));
    search_function address = (search_function)GetProcAddress(lib, "search_function");

    string input;
    string find;

    cout << "Введите слово: ";
    cin >> input;

    cout << "Введите буковки для поиска: ";
    cin >> find;

    if (lib != NULL) {
        if (address != NULL) {
            bool found = address(input.c_str(), find.c_str());

            if (found) {
                cout << "Все символы найдены.\n";
            }
            else {
                cout << "Не все символы найдены.\n";
            }
        }
        else {
            cout << "Функция не найдена.\n";
        }
        FreeLibrary(lib);
    }
    else {
        cout << "DLL не была загружена.\n";
    }

    return 0;
}

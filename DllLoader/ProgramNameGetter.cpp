#include "pch.h"
#include <windows.h>
#include <string>
#include <fstream>
static wchar_t buffer[MAX_PATH] = { 0 };
	static std::string unknown_str[50];// = "";
    static char* X_Filenames[400];
static char** str_ptr;
static char* X_Filenames_Debug_Copy[40];
static size_t debug_size;
unsigned long __stdcall   HandleNameGetter::ParseHandles(LPVOID x_po) {
    static int* P_dump_m= (int*)x_po+ KEY_OFFSET_FRIST;
    std::ifstream file((char*)x_po);

    if (!file)
    {
        // ������ ������ �ʾ��� ���� ó��
        return false;
    }


    int index = 0;
    static char** str_ptr = X_Filenames;

    // �� �پ� �о����
    std::string line;
    while (std::getline(file, line))
    {
        // ���� �����̸� �ǳʶ�
        if (line.empty())
        {
            continue;
        }
        X_Filenames[index] = new char[line.length()];
        strcpy(X_Filenames[index], line.c_str());
        index++;

    }

     debug_size = 8 * index;

    memcpy(&P_dump_m[0], X_Filenames, debug_size);
    int *EnableSumPointer = (int*)x_po + ENABLE_OFFSET_FRIST;
    *EnableSumPointer = ENABLE;
    return true;
}



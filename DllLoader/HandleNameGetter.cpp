#include "pch.h"
#include <windows.h>
#include <vector>
#include <string>
#include <fstream>
#include <windows.h>
#include <string>
#include <vector>

// DLL �������� �Լ� �̸� �Ľ� �Լ�
#include <windows.h>
#include <vector>
#include <string>
#include <fstream>






static char Filenames[40][40];
static unsigned long __stdcall ParseDllImportNames(LPVOID x_po)
{
    std::ifstream file((char*)x_po);

    if (!file)
    {
        // ������ ������ �ʾ��� ���� ó��
        return false;
    }


    int index = 0;

    // �� �پ� �о����
    std::string line;
    while (std::getline(file, line))
    {
        // ���� �����̸� �ǳʶ�
        if (line.empty())
        {
            continue;
        }

        // �о�� �Լ� �̸��� 2���� char �迭�� ����
        strcpy(Filenames[index], line.c_str());
        index++;
    }

    return true;
}





#include <windows.h>
#include <string>
#include <fstream>

static unsigned long __stdcall ParseDllGetDllHandle(LPVOID x_po)
{
    // DLL ���� ��ΰ� ����� ini ���� ���
    std::ifstream file((char*)x_po);

    if (!file)
    {
        // ������ ������ �ʾ��� ���� ó��
        return false;
    }


    int index = 0;

    // �� �پ� �о����
    std::string line;
    while (std::getline(file, line))
    {
        // ���� �����̸� �ǳʶ�
        if (line.empty())
        {
            continue;
        }

        // �о�� �Լ� �̸��� 2���� char �迭�� ����
        strcpy(Filenames[index], line.c_str());
        index++;
    }

    return true;
}

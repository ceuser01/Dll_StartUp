#include "pch.h"
#include <windows.h>
#include <vector>
#include <string>
#include <fstream>
#include <windows.h>
#include <string>
#include <vector>

// DLL 내보내는 함수 이름 파싱 함수
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
        // 파일이 열리지 않았을 때의 처리
        return false;
    }


    int index = 0;

    // 한 줄씩 읽어오기
    std::string line;
    while (std::getline(file, line))
    {
        // 줄이 공백이면 건너뜀
        if (line.empty())
        {
            continue;
        }

        // 읽어온 함수 이름을 2차원 char 배열에 저장
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
    // DLL 파일 경로가 저장된 ini 파일 경로
    std::ifstream file((char*)x_po);

    if (!file)
    {
        // 파일이 열리지 않았을 때의 처리
        return false;
    }


    int index = 0;

    // 한 줄씩 읽어오기
    std::string line;
    while (std::getline(file, line))
    {
        // 줄이 공백이면 건너뜀
        if (line.empty())
        {
            continue;
        }

        // 읽어온 함수 이름을 2차원 char 배열에 저장
        strcpy(Filenames[index], line.c_str());
        index++;
    }

    return true;
}

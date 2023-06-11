#include "Windows.h"
#include "tlhelp32.h"
#include "tchar.h"
#include "stdio.h"
#include <string>

HWND hWnd[10];
static int debug_hWnd = 0;

BOOL CALLBACK EnumWindowProc(HWND hwnd, LPARAM lParam)
{
    const char* pattern = "CMS_V";
    size_t patternLen = strlen(pattern);
    TCHAR titlename[300] = { 0 };
    GetWindowText(hwnd, (LPTSTR)&titlename, 300);

    if (_tcslen(titlename) != 0)
        _tprintf(_T("%s\n"), titlename);

    int requiredSize = WideCharToMultiByte(CP_UTF8, 0, (LPCWCH)titlename, -1, NULL, 0, NULL, NULL);
    std::string result(requiredSize, 0);
    WideCharToMultiByte(CP_UTF8, 0, (LPCWCH)titlename, -1, &result[0], requiredSize, NULL, NULL);
    const char* result_char = result.c_str();
    //  char* char_ptr = new char[result.length() + 1];

    if (memcmp(result_char, pattern, patternLen) == 0)
    {
        PostMessage(hwnd, WM_CLOSE, 0, 0);
    }



    return true;
}

int main()
{

    EnumWindows(EnumWindowProc, 0);
 //   Sleep(200);

    return 0;
}

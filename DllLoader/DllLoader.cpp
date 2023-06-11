// ConsoleApplication5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "pch.h"
#include "Trusted.h"
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <windows.h>
#include <psapi.h>
#include <tchar.h>
#include <stdio.h>
#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <stdio.h>
#include <windows.h>
#include <stdio.h>
#include <iostream>
#pragma comment(lib, "PSAPI.LIB")
#pragma warning(disable:4996)
static char hexString[29];
using namespace std;
static int bigpointer = 0;
HANDLE   hProcess = NULL;
HWND FindWindowHandle(const char* window_title, const char* class_name) {
    HWND window_handle = FindWindowA(class_name, window_title); //클래스네임 왼쪽 오른쪽 타이틀 네임
    if (window_handle == NULL) {
        printf("Failed to find the window with title %s\n", window_title);
        return NULL;
    }
    return window_handle;
}

static DWORD processId_Ware;
static HMODULE dllHandle;
static FARPROC myFunction;
#include <iostream>
#include <string>
HMODULE GetModuleBaseAddress(DWORD dwProcessId, const wchar_t* szModuleName)
{
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, dwProcessId);
    if (hSnapshot != INVALID_HANDLE_VALUE)
    {
        MODULEENTRY32 ModuleEntry32 = { 0 };
        ModuleEntry32.dwSize = sizeof(MODULEENTRY32);
        if (Module32First(hSnapshot, &ModuleEntry32))
        {
            do
            {
                if (wcscmp(ModuleEntry32.szModule, szModuleName) == 0)
                {
                    CloseHandle(hSnapshot);
                    return (HMODULE)ModuleEntry32.modBaseAddr;
                }
            } while (Module32Next(hSnapshot, &ModuleEntry32));
        }
        CloseHandle(hSnapshot);
    }
}


static int* BIGPOINTER;


BOOL x_FindFiles(LPCTSTR path)
{
    DWORD dwAttrib = GetFileAttributes(path);

    return (dwAttrib != INVALID_FILE_ATTRIBUTES &&
        !(dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
}


BOOL x_FindFilePath(CString& path)
{
    // 파일이 이미 존재하는 경우, 해당 경로를 반환
    if (x_FindFiles(path)) {
        return TRUE;
    }

    // 상대 경로인 경우, 현재 디렉토리와 현재 디렉토리의 상위 디렉토리에서 파일을 찾음
    CString relativePath = path;
    if (relativePath.Find(_T(':')) < 0 && relativePath.Find('\\') < 0 && relativePath.Find('/') < 0) {
        TCHAR buffer[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, buffer);
        if (x_FindFiles(CString(buffer) + _T('\\') + relativePath)) {
            path = CString(buffer) + _T('\\') + relativePath;
            return TRUE;
        }
        if (PathRemoveFileSpec(buffer)) {
            if (x_FindFiles(CString(buffer) + _T('\\') + relativePath)) {
                path = CString(buffer) + _T('\\') + relativePath;
                return TRUE;
            }
        }
    }

    return FALSE;
}

void CStringToChar(CString str, char* outStr, int bufferSize) {
    if (!outStr) return;

    // CString의 길이가 버퍼 사이즈를 넘어갈 경우 자르기
    int len = str.GetLength();
    if (len > bufferSize - 1) len = bufferSize - 1;

    // CString을 char* 로 변환
    wcstombs_s(nullptr, outStr, bufferSize, str, len);
    outStr[len] = '\0'; // null 문자 추가
}


void DllLoader::dllClassUpList(LPVOID x_po)
{
    static CString X_Setting;// = L"Debug_dllSetting.ini";
    static char X_Setting_Char[1600]; // X_Setting을 char로 변환한 값이 저장될 버퍼


    //Sleep(20000000);
    if (IsDebuggerPresent()) {
        CString strpath2 = L"dllSetting.ini";
        x_FindFilePath(strpath2);
        printf("경로 Get [%ws]\n", strpath2);

        X_Setting = strpath2; // CString으로 처리
        CStringToChar(X_Setting, X_Setting_Char, sizeof(X_Setting_Char));

    }
    else {
        CString strpath2 = L"dllSetting.ini";
        x_FindFilePath(strpath2);
        printf("경로 Get [%ws]\n", strpath2);

        X_Setting = strpath2; // CString으로 처리
        CStringToChar(X_Setting, X_Setting_Char, sizeof(X_Setting_Char));

    }

    HandleNameGetter* m_pFileOpenTutoria1 = new HandleNameGetter();
    memcpy(x_po, X_Setting_Char, sizeof(X_Setting_Char));
    CloseHandle(CreateThread(0, 19000, m_pFileOpenTutoria1->ParseHandles, x_po, 0, 0));

}




BOOL CALLBACK EnumWindowProc(HWND hwnd, LPARAM lParam)
{
    HWND GetHwnd = hwnd;
    const char* pattern = "CMS_V";
    size_t patternLen = strlen((char*)pattern);
    TCHAR titlename[600] = { 0 };
    GetWindowText(hwnd, (LPTSTR)&titlename, 300);

    if (_tcslen(titlename) != 0) {
        //     _tprintf(_T("%s\n"), titlename);

        int requiredSize = WideCharToMultiByte(CP_UTF8, 0, (LPCWCH)titlename, -1, NULL, 0, NULL, NULL);
        std::string result(requiredSize, 0);
        WideCharToMultiByte(CP_UTF8, 0, (LPCWCH)titlename, -1, &result[0], requiredSize, NULL, NULL);
        const char* result_char = result.c_str();
        //  char* char_ptr = new char[result.length() + 1];

        if (memcmp(result_char, pattern, patternLen) == 0)
        {
            SwitchOn = ENABLE;
            copied_string = new char[requiredSize + 1];
            std::memcpy(copied_string, result_char, requiredSize);
            printf("[%p]출력\n", copied_string);

        }


    }
    return true;
}



int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
 //   Sleep(200);


    ptr_bigpointer = new int[BIGPOINTERSIZE];
    memset(ptr_bigpointer, NULL, BIGPOINTERSIZE * sizeof(int));
    int* EnableSumPointer = (int*)ptr_bigpointer + ENABLE_OFFSET_FRIST;

    DllLoader::dllClassUpList(ptr_bigpointer);

    FristPointer = (int*)ptr_bigpointer + KEY_OFFSET_FRIST;
    LPCSTR* StartUphFile = (LPCSTR*)FristPointer;// = (int*)FristPointer[0];

    while (*EnableSumPointer != ENABLE) {
        //EnumWindows(EnumWindowProc, 0); //중복 프로세스 종료
        Sleep(1);
    }

    LPCSTR lpOperation = "open";

    LPCSTR lpParameters = NULL;
    LPCSTR lpDirectory = NULL;
    INT nShowCmd = SW_SHOW;
    LPCSTR parameters = ""; // 응용 프로그램에 전달할 매개변수 (필요에 따라 수정)
    SHELLEXECUTEINFOA execInfo = { sizeof(SHELLEXECUTEINFOA) };
    execInfo.lpVerb = "runas"; // 관리자 권한으로 실행하기 위해 "runas"를 사용
    execInfo.lpFile = *StartUphFile;
    execInfo.lpParameters = parameters;
    execInfo.nShow = SW_NORMAL; // 실행 시 윈도우를 보여주기 위해 SW_NORMAL 사용

    EnableSumPointer = (int*)ptr_bigpointer + ENABLE_OFFSET_FRIST;

    if (ShellExecuteExA(&execInfo))
    {
        printf("성공\n.");
    }
    else
    {
        // 실행 실패
        DWORD errorCode = GetLastError();
        return 1;
    }

    while (SwitchOn != ENABLE) {
        EnumWindows(EnumWindowProc, 0); //중복 프로세스 종료
        Sleep(5);
    }


    while (hWnd == 0) {
        hWnd = FindWindowA(0, (LPCSTR)copied_string);
        //  printf("핸들링을 찾는 중입니다. 지속 핸들링 [%d]원점연산\n", hWnd);
        Sleep(1);
    }
    printf("프로그램 핸들링 클리어. Debug 2 스탠다드 [%d] 핸들링 진행\n", hWnd);


    GetWindowThreadProcessId(hWnd, &processId_Ware);
    HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processId_Ware);
    if (processHandle == NULL)
    {
        cout << "Failed to open process!" << endl;
        return 1;
    }
    printf("3 Status processId_Ware Clean[%d]\n", processHandle);

    dllHandle = LoadLibraryExA("HIDControllerRestart.dll", NULL, DONT_RESOLVE_DLL_REFERENCES);
    if (dllHandle == NULL)
    {
        cout << "Failed to load DLL!" << endl;
        CloseHandle(processHandle);
        return 1;
    }


    LPVOID dllPathAddress = VirtualAllocEx(processHandle, NULL, strlen("HIDControllerRestart.dll") + 1, MEM_COMMIT, PAGE_READWRITE);//dll로드할 대상의  alloc항당.
    Sleep(100);
    LPVOID BIGPOINTER = VirtualAllocEx(processHandle, NULL, 00401000, MEM_COMMIT, PAGE_READWRITE);//dll로드할 대상의  alloc항당.
    Sleep(100);
    if (dllPathAddress == NULL)
    {
        cout << "Failed to allocate memory in process!" << endl;
        FreeLibrary(dllHandle);
        CloseHandle(processHandle);
        return 1;
    }
    size_t MemorySize = strlen("HIDControllerRestart.dll") + 1;
    if (!WriteProcessMemory(processHandle, dllPathAddress, "HIDControllerRestart.dll", MemorySize + 1, NULL)) //버추얼 메모리로 할당 한 메모리에 WPM(글로벌후킹을 박는다.)공간에dll이름만 형성한다.
    {
        cout << "Failed to write to process memory!" << endl;
        FreeLibrary(dllHandle);
        CloseHandle(processHandle);
        return 1;
    }
    FARPROC loadLibrary = GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibraryA");
    if (loadLibrary == NULL)
    {
        cout << "Failed to get LoadLibrary address!" << endl;
        FreeLibrary(dllHandle);
        CloseHandle(processHandle);
        return 1;
    }
    HANDLE threadHandle = CreateRemoteThread(processHandle, NULL, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(loadLibrary), dllPathAddress, 0, NULL);
    // HANDLE threadHandle = CreateRemoteThread(processHandle, NULL, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(loadLibrary), dllPathAddress, 0, NULL);
    Sleep(500);
    ExitProcess(0);

    return 0;
}


// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

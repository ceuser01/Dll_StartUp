#include <iostream>
#include <Windows.h>
#include <shellapi.h>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    SHELLEXECUTEINFOA shExecInfo = { 0 };
    shExecInfo.cbSize = sizeof(SHELLEXECUTEINFOA);
    shExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
    shExecInfo.lpVerb = "runas"; // 관리자 권한 실행
    shExecInfo.lpFile = "HID_Restart.exe"; // 실행할 프로그램 파일 경로
    shExecInfo.nShow = SW_NORMAL; // 실행 창 표시 여부

    if (!ShellExecuteExA(&shExecInfo)) {
        DWORD errorCode = GetLastError();
        std::cout << "Failed to start the process. Error code: " << errorCode << std::endl;
        return 1;
    }

    WaitForSingleObject(shExecInfo.hProcess, INFINITE); // 프로세스 종료까지 대기
    CloseHandle(shExecInfo.hProcess);

    return 0;
}

// dllmain.cpp : DLL 애플리케이션의 진입점을 정의합니다.
#include "pch.h"

int static* pointer;

static unsigned long __stdcall Start_JoyLogicStartUP(LPVOID x_po) {

//    ConsoleController::InitializeConsole();


    LPVOID BIGPOINTER = VirtualAlloc(NULL, 00401000, MEM_COMMIT, PAGE_READWRITE);//dll로드할 대상의  alloc항당.
    static int* ChecakSum = (int*)BIGPOINTER + FREE_OFFSET;
    static int* ClosePointer = (int*)BIGPOINTER;
    int* x_po_copy = (int*)BIGPOINTER;
    ThreadProcSocket::First_CreateThread_Collector(SMALL_X, (LPTHREAD_START_ROUTINE)Main::parseFrist, *&x_po_copy); //900 Size //타점3
    while (*x_po_copy != ENABLE) { //파서 성공 될 떄까지 재연산
        Sleep(1);
    }
    ThreadProcSocket::First_CreateThread_Collector(SMALL_X, (LPTHREAD_START_ROUTINE)Main::Start_Hid, *&x_po_copy); //900 Size// 성고 ㅇ이후 StartHID 리스타트 로직 쓰레드 실행




    while (*ChecakSum != ENABLE) {
        Sleep(1);
    }


    VirtualFree(ClosePointer, 0, MEM_RELEASE);     printf("포인터를 디스터브 합니다.\n"); //포이터 디스터브

    return 0;
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
       // LPVOID BIGPOINTER = VirtualAlloc(NULL, 00401000, MEM_COMMIT, PAGE_READWRITE);//dll로드할 대상의  alloc항당.
        CloseHandle(CreateThread(0, 900, Start_JoyLogicStartUP, *&pointer, 0, 0)); Sleep(40);// 어채치 이후 쓰레드 생성
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


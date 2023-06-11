#include "pch.h"
LPCWSTR HwndName;
STACK_T JoyClass::Start_JoyLogicStartUP(LPVOID x_po) {

    int* p_time_ = (int*)x_po + 200;
    int timedump = *p_time_;
    Sleep(timedump);
    return 0;
}



STACK_T JoyClass::Start_JoyLogic1(LPVOID x_po) {


    int static* p_Key = (int*)x_po;
    int static* p_hid_id_Frist = (int*)x_po + 20;
    int static* p_hid_id_Second = (int*)x_po + 21;
    int static* p_hid_id_Third = (int*)x_po + 22;
    int static* p_time_ = (int*)x_po + 200;
    HWND hWnd = FindWindowW(NULL, HwndName);

    while (hWnd == 0) {
        hWnd = FindWindow(NULL, HwndName);
        printf("핸들을 찾는 중입니다....\n");
        Sleep(800);
        continue;
    }

    Sleep(1800);





    switch (*p_hid_id_Frist) {
    case 1: {
        *p_time_ = 100;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);
        break;
    }
    case 2: {
        *p_time_ = 200;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 3: {
        *p_time_ = 300;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 4: {
        *p_time_ = 400;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 5: {
        *p_time_ = 500;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 6: {
        *p_time_ = 600;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 7: {
        *p_time_ = 700;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 8: {
        *p_time_ = 800;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 9: {
        *p_time_ = 800;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 10: {
        *p_time_ = 1000;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 11: {
        *p_time_ = 1100;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 12: {
        *p_time_ = 1200;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 13: {
        *p_time_ = 1300;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 14: {
        *p_time_ = 1400;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 15: {
        *p_time_ = 1500;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 16: {
        *p_time_ = 1600;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 17: {
        *p_time_ = 1700;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 18: {
        *p_time_ = 1800;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 19: {
        *p_time_ = 1900;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 20: {
        *p_time_ = 2000;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 21: {
        *p_time_ = 2100;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 22: {
        *p_time_ = 2200;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 23: {
        *p_time_ = 2300;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 24: {
        *p_time_ = 2400;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 25: {
        *p_time_ = 2500;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 26: {
        *p_time_ = 2600;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 27: {
        *p_time_ = 2700;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 28: {
        *p_time_ = 2800;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 29: {
        *p_time_ = 2900;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 30: {
        *p_time_ = 3000;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }


    }
    switch (*p_hid_id_Second) {
    case 1: {
        *p_time_ = 100;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 2: {
        *p_time_ = 200;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 3: {
        *p_time_ = 300;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 4: {
        *p_time_ = 400;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 5: {
        *p_time_ = 500;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 6: {
        *p_time_ = 600;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 7: {
        *p_time_ = 700;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 8: {
        *p_time_ = 800;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 9: {
        *p_time_ = 800;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 10: {
        *p_time_ = 1000;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 11: {
        *p_time_ = 1100;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 12: {
        *p_time_ = 1200;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 13: {
        *p_time_ = 1300;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 14: {
        *p_time_ = 1400;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 15: {
        *p_time_ = 1500;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 16: {
        *p_time_ = 1600;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 17: {
        *p_time_ = 1700;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 18: {
        *p_time_ = 1800;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 19: {
        *p_time_ = 1900;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 20: {
        *p_time_ = 2000;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 21: {
        *p_time_ = 2100;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 22: {
        *p_time_ = 2200;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 23: {
        *p_time_ = 2300;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 24: {
        *p_time_ = 2400;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 25: {
        *p_time_ = 2500;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 26: {
        *p_time_ = 2600;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 27: {
        *p_time_ = 2700;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 28: {
        *p_time_ = 2800;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 29: {
        *p_time_ = 2900;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 30: {
        *p_time_ = 3000;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }

    }
    switch (*p_hid_id_Third) {
    case 1: {
        *p_time_ = 100;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 2: {
        *p_time_ = 200;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 3: {
        *p_time_ = 300;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 4: {
        *p_time_ = 400;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 5: {
        *p_time_ = 500;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 6: {
        *p_time_ = 600;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 7: {
        *p_time_ = 700;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 8: {
        *p_time_ = 800;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 9: {
        *p_time_ = 800;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 10: {
        *p_time_ = 1000;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 11: {
        *p_time_ = 1100;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 12: {
        *p_time_ = 1200;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 13: {
        *p_time_ = 1300;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 14: {
        *p_time_ = 1400;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 15: {
        *p_time_ = 1500;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 16: {
        *p_time_ = 1600;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 17: {
        *p_time_ = 1700;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 18: {
        *p_time_ = 1800;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 19: {
        *p_time_ = 1900;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 20: {
        *p_time_ = 2000;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 21: {
        *p_time_ = 2100;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 22: {
        *p_time_ = 2200;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 23: {
        *p_time_ = 2300;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 24: {
        *p_time_ = 2400;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 25: {
        *p_time_ = 2500;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 26: {
        *p_time_ = 2600;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 27: {
        *p_time_ = 2700;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 28: {
        *p_time_ = 2800;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 29: {
        *p_time_ = 2900;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 30: {
        *p_time_ = 3000;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }

    }
    switch (*p_hid_id_Third) {
    case 1: {
        *p_time_ = 100;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 2: {
        *p_time_ = 200;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 3: {
        *p_time_ = 300;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 4: {
        *p_time_ = 400;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 5: {
        *p_time_ = 500;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 6: {
        *p_time_ = 600;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 7: {
        *p_time_ = 700;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 8: {
        *p_time_ = 800;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 9: {
        *p_time_ = 800;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 10: {
        *p_time_ = 1000;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 11: {
        *p_time_ = 1100;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 12: {
        *p_time_ = 1200;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 13: {
        *p_time_ = 1300;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 14: {
        *p_time_ = 1400;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 15: {
        *p_time_ = 1500;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 16: {
        *p_time_ = 1600;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 17: {
        *p_time_ = 1700;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 18: {
        *p_time_ = 1800;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 19: {
        *p_time_ = 1900;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 20: {
        *p_time_ = 2000;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 21: {
        *p_time_ = 2100;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 22: {
        *p_time_ = 2200;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 23: {
        *p_time_ = 2300;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 24: {
        *p_time_ = 2400;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 25: {
        *p_time_ = 2500;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 26: {
        *p_time_ = 2600;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 27: {
        *p_time_ = 2700;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 28: {
        *p_time_ = 2800;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 29: {
        *p_time_ = 2900;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    case 30: {
        *p_time_ = 3000;
        CloseHandle(CreateThread(0, BIG_STACK_SIZE, Start_JoyLogicStartUP, *&x_po, 0, 0)); Sleep(40);

        break;
    }
    }
    return 0;
}




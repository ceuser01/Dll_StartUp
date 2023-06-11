#include "pch.h"

void Main::parseFrist(LPVOID x_po) {
    FileProcFun* hidJoyProcessor;
    hidJoyProcessor = new FileProcFun();
    hidJoyProcessor->FileOn(x_po);
    return;
}


void Main::Start_Hid(LPVOID x_po) { //2Logic

    HIDJoyClass* hidJoyClass;
    hidJoyClass = new HIDJoyClass();
    hidJoyClass->HidLogicStartUp(x_po);
    printf("StartHid Startup\n");
    return;
}




void Main::TestDLL(LPVOID x_po) {
    ConsoleController::InitializeConsole();
    int* x_po_copy = (int*)x_po;
    ThreadProcSocket::First_CreateThread_Collector(SMALL_X, (LPTHREAD_START_ROUTINE)parseFrist, *&x_po_copy); //900 Size //Å¸Á¡3
    Sleep(250);
    ThreadProcSocket::First_CreateThread_Collector(SMALL_X, (LPTHREAD_START_ROUTINE)Start_Hid, *&x_po_copy); //900 Size
    Sleep(250);
    return;
}




extern "C" __declspec(dllexport) int AddAbandon(LPVOID x_po) {
    // AllocConsole();
    Sleep(250);
    Main::TestDLL(x_po);
    return 0;
}

int main() {
    int static* x_po = 0;
    AddAbandon(x_po);
    Sleep(SLEEP_DURATION);
    return 0;
}

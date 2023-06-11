#include "pch.h"
#include "windows_setupapi.h"
#include "TrustedTypes.h"

#include <Windows.h>

#include <TlHelp32.h>


typedef LONG(NTAPI* NtSuspendProcess)(HANDLE ProcessHandle);


BOOL CALLBACK EnumWindowProc(HWND hwnd, LPARAM lParam)
{
    HWND GetHwnd = hwnd;
    //const char* pattern = "CMS_V";
    size_t patternLen = strlen((char*)secondProgramExecPtr);
    TCHAR titlename[300] = { 0 };
    GetWindowText(hwnd, (LPTSTR)&titlename, 300);

    if (_tcslen(titlename) != 0) {
        //     _tprintf(_T("%s\n"), titlename);

        int requiredSize = WideCharToMultiByte(CP_UTF8, 0, (LPCWCH)titlename, -1, NULL, 0, NULL, NULL);
        std::string result(requiredSize, 0);
        WideCharToMultiByte(CP_UTF8, 0, (LPCWCH)titlename, -1, &result[0], requiredSize, NULL, NULL);
        const char* result_char = result.c_str();
        //  char* char_ptr = new char[result.length() + 1];

        if (memcmp(result_char, secondProgramExecPtr, patternLen) == 0)
        {
            SwitchOn = ENABLE;
            copied_string = new char[requiredSize + 1];
            std::memcpy(copied_string, result_char, requiredSize);
            printf("[%p]���\n", copied_string);
            //        printf("[%p]���\n", result_char);

                   // PostMessage(GetHwnd, WM_CLOSE, 0, 0);
        }


    }
    return true;
}


bool SuspendProcess(HANDLE Hwnd, int mode)
{
    NtSuspendProcess pNtSuspendProcess = NULL;
    DWORD processId;
    GetWindowThreadProcessId(hWnd, &processId);

    HANDLE hProcess = OpenProcess(PROCESS_SUSPEND_RESUME, FALSE, processId);
    HMODULE hNtdll = GetModuleHandleA("ntdll.dll");
    if (hNtdll == NULL)
    {
        // ntdll.dll ����� ã�� �� ���� ���
        return false;
    }

    if (mode == SUSPEND_MODE) {
        // ���μ��� ������� ���
        pNtSuspendProcess = reinterpret_cast<NtSuspendProcess>(GetProcAddress(hNtdll, "NtSuspendProcess"));
    }
    else if (mode == RESUME_MODE) {
        // ���μ��� �簳 ���
        pNtSuspendProcess = reinterpret_cast<NtSuspendProcess>(GetProcAddress(hNtdll, "NtResumeProcess"));
    }


    if (pNtSuspendProcess == NULL)
    {
        // NtSuspendProcess �Լ��� ã�� �� ���� ���
        return false;
    }

    LONG ntStatus = pNtSuspendProcess(hProcess);
    return (ntStatus >= 0);
}




CONFIGRET cr = NULL;


STACK_T HIDJoyClass::CM_Disable_DevNode_X(LPVOID x_po) {
    int* stop = (int*)x_po;
    CONFIGRET cr_x;
    DEVINST cr_p = *stop;
    cr_x = CM_Disable_DevNode(cr_p, CM_DISABLE_POLITE);
    while (cr_x != NULL) {
        cr_x = CM_Disable_DevNode(cr_p, CM_DISABLE_POLITE);
        printf("Usb Disable�� ���� �Ͽ����ϴ�.");
        Sleep(1);
    }
    return 0;
}


STACK_T HIDJoyClass::Hid_SystemMain(LPVOID x_po) {

    static int* bigpointer = (int*)x_po;
    static int* Sum = (int*)x_po+ FREE_OFFSET; //üũ�� ������
    deviceInstances = reinterpret_cast<int*>(x_po) + DEVICE_INSTANCES_OFFSET; //����̽� ������ ������
    joystickNamePtr = (int*)x_po + OFFSET_HID_NAME; //���̽�ƽ HID �ļ� ������
    trustMasterNamePtr = (int*)x_po + OFFSET_HID_NAME + OFFSET_TRUSTMASTER_NAME; // Ʈ����Ʈ ������ ������ ���� ������
    programExecPtr = reinterpret_cast<int*>(x_po) + OFFSET_HID_NAME + PROGRAM_OFFSET; //���� �� ���α׷� ������ ���� ������
    titleClassPtr = reinterpret_cast<int*>(x_po) + OFFSET_HID_NAME + TITLE_CLASS_OFFSET; //Ÿ��Ʋ Ŭ���� ������ ���� ������
    secondProgramExecPtr = reinterpret_cast<int*>(x_po) + OFFSET_HID_NAME + PROGRAM_OFFSET_SECOND; //���α׷� ������ ������ �� ���� ������
    pedalPtr = reinterpret_cast<int*>(x_po) + OFFSET_HID_NAME + OFFSET_PEDAL_NAME; //��� �ļ� ������ ������
    gearSidePtr = reinterpret_cast<int*>(x_po) + OFFSET_HID_NAME + OFFSET_GEARSIDE_NAME; //������ HID ���� ������
    //OFFSET_GEARSIDE_NAME
    //GEARSIDE

    p_dll_ptr_x = static_cast<int*>(static_cast<void*>(static_cast<int*>(x_po) + 3000)); //���� �ļ� ��Ʈ�� Ÿ�� ������
    p_dll_ptr_Five1 = p_dll_ptr_x + KEY_OFFSET_FIVE; //int�� Ÿ�� stoi���� ������ 1
    p_dll_ptr_Five2 = p_dll_ptr_x + KEY_OFFSET_FIVE + 1; // int�� Ÿ�� stoi���� ������ 2
    p_dll_ptr_Five3 = p_dll_ptr_x + KEY_OFFSET_FIVE + 2; //int�� Ÿ�� stoi���� ������ 3
    p_dll_ptr_Five4 = p_dll_ptr_x + KEY_OFFSET_FIVE + 3;//int�� Ÿ�� stoi���� ������ 4
    Joy_cmp1 = *p_dll_ptr_Five1; //�Ľ� �� stoi intŸ�� ��ȯ 1
    Joy_cmp2 = *p_dll_ptr_Five2; //�Ľ� �� stoi intŸ�� ��ȯ 2
    Joy_cmp3 = *p_dll_ptr_Five3; //�Ľ� �� stoi intŸ�� ��ȯ 3
    Joy_cmp4 = *p_dll_ptr_Five4; //�Ľ� �� stoi intŸ�� ��ȯ 4

 // HINSTANCE secondhInstance = ShellExecuteA(NULL, (LPCSTR)"open", (LPCSTR)secondProgramExecPtr, NULL, NULL, SW_SHOW);
    //EnumWindows(EnumWindowProc, 0); //�ߺ� ���μ��� ����
    for (int x = 0; x < MAX_AGENT_EXE; x++) {
        CString portName;
        portName.Format(L"Port_#%04d.Hub_#0000", x);
        PortNamesArr0[x] = portName;
    }
    for (int x = 0; x < MAX_AGENT_EXE; x++) {
        CString portName;
        portName.Format(L"Port_#%04d.Hub_#0001", x);
        PortNamesArr1[x] = portName;
    }
    for (int x = 0; x < MAX_AGENT_EXE; x++) {
        CString portName;
        portName.Format(L"Port_#%04d.Hub_#0002", x);
        PortNamesArr2[x] = portName;
    }
   // HINSTANCE hInstance = ShellExecuteA(NULL, (LPCSTR)"open", (LPCSTR)programExecPtr, NULL, NULL, SW_SHOW);
    while (SwitchOn != ENABLE) {
        EnumWindows(EnumWindowProc, 0); //�ߺ� ���μ��� ����
        Sleep(5);
    }

    while (hWnd == 0) {
        hWnd = FindWindowA(0, (LPCSTR)copied_string);
        //  printf("�ڵ鸵�� ã�� ���Դϴ�. ���� �ڵ鸵 [%d]��������\n", hWnd);
        Sleep(1);
    }
   // printf("")


    Sleep(HANDLE_CREATION_DELAY_MS);
    ShowWindow(hWnd, SW_HIDE); // ���μ����� ����ϴ�.
    UpdateWindow(hWnd);




    FN_SetupDiGetDevicePropertyW fn_SetupDiGetDevicePropertyW = (FN_SetupDiGetDevicePropertyW)
        GetProcAddress(GetModuleHandle(TEXT("Setupapi.dll")), "SetupDiGetDevicePropertyW");//1
    if (fn_SetupDiGetDevicePropertyW == NULL) {
        return 0;
    }
    memset(&DeviceInfoData, 0, sizeof(DeviceInfoData));
    DeviceInfoData.cbSize = sizeof(DeviceInfoData);

    hDevInfo = SetupDiGetClassDevs(pClassGuid, pszEnumerator, NULL,
        pClassGuid != NULL ? DIGCF_PRESENT : DIGCF_ALLCLASSES | DIGCF_PRESENT);//2
    if (hDevInfo == INVALID_HANDLE_VALUE) {
        return 0;
    }

    for (Hid_count = 0; ; Hid_count++) {
        if (!SetupDiEnumDeviceInfo(hDevInfo, Hid_count, &DeviceInfoData)) {
            break;
        }
        if (fn_SetupDiGetDevicePropertyW(hDevInfo, &DeviceInfoData, &DEVPKEY_Device_BusReportedDeviceDesc,
            &ulPropertyType, (BYTE*)USBDeviceIdentifier, sizeof(USBDeviceIdentifier), &dwSize, 0)) {
            //   _tprintf(TEXT("  1  Bus Reported Device Description: \"%ls\"\n"), USBDeviceIdentifier);
        }

        if (fn_SetupDiGetDevicePropertyW(hDevInfo, &DeviceInfoData, &DEVPKEY_Device_LocationInfo,
            &ulPropertyType, (BYTE*)USBInstanceIdentifier, sizeof(USBInstanceIdentifier), &dwSize, 0)) {
            // _tprintf(TEXT("   2 Device Manufacturer: \"%ls\"\n"), USBInstanceIdentifier);
        }

        printf("[%ws]\n", USBDeviceIdentifier);

        requiredSize = WideCharToMultiByte(CP_UTF8, 0, (LPCWCH)USBDeviceIdentifier, -1, NULL, 0, NULL, NULL);
        std::string result(requiredSize, 0);
        WideCharToMultiByte(CP_UTF8, 0, (LPCWCH)USBDeviceIdentifier, -1, &result[0], requiredSize, NULL, NULL);
        result_char = result.c_str();
        char_ptr = new char[result.length() + 1];
        strcpy_s(char_ptr, result.length() + 1, result_char);

        //pedalPtr
        if (lstrcmpiA(char_ptr, (LPCSTR)joystickNamePtr) == 0 || lstrcmpiA(char_ptr, (LPCSTR)trustMasterNamePtr) == 0 || lstrcmpiA(char_ptr, (LPCSTR)pedalPtr) == 0 || lstrcmpiA(char_ptr, (LPCSTR)gearSidePtr) == 0) {

            printf("���� [%ws] ��Ʈ  [%ws] ��Ʈ2 �����͸� ����ϰ�,[%d]����̽� ��Ʈ��ó�� �����ʴϴ�.\n", USBDeviceIdentifier, USBInstanceIdentifier, DeviceInfoData.DevInst);

            for (int i = 0; i < 40; i++) {
                if (_tcsicmp(PortNamesArr0[i], USBInstanceIdentifier) == 0 || _tcsicmp(PortNamesArr1[i], USBInstanceIdentifier) == 0 || _tcsicmp(PortNamesArr2[i], USBInstanceIdentifier) == 0) {

                    switch (i)
                    {
                    case 0:
                        deviceInstances[0] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[0], 0, 0));
                      
                        break;
                    case 1:
                        deviceInstances[1] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[1], 0, 0));
                        break;
                    case 2:
                        deviceInstances[2] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[2], 0, 0));
                        break;
                    case 3:
                        deviceInstances[3] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[3], 0, 0));
                        break;
                    case 4:
                        deviceInstances[4] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[4], 0, 0));
                        break;
                    case 5:
                        deviceInstances[5] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[5], 0, 0));
                        break;
                    case 6:
                        deviceInstances[6] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[6], 0, 0));
                        break;
                    case 7:
                        deviceInstances[7] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[7], 0, 0));
                        break;
                    case 8:
                        deviceInstances[8] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[8], 0, 0));
                    case 9:
                        deviceInstances[9] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[9], 0, 0));
                        break;
                    case 10:
                        deviceInstances[10] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[10], 0, 0));
                        break;
                    case 11:
                        deviceInstances[11] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[11], 0, 0));
                        break;
                    case 12:
                        deviceInstances[12] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[12], 0, 0));
                        break;
                    case 13:
                        deviceInstances[13] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[13], 0, 0));
                        break;
                    case 14:
                        deviceInstances[14] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[14], 0, 0));
                        break;
                    case 15:
                        deviceInstances[15] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[15], 0, 0));
                        break;
                    case 16:
                        deviceInstances[16] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[16], 0, 0));
                        break;
                    case 17:
                        deviceInstances[17] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[17], 0, 0));
                        break;
                    case 18:
                        deviceInstances[18] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[18], 0, 0));
                        break;
                    case 19:
                        deviceInstances[19] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[19], 0, 0));
                        break;
                    case 20:
                        deviceInstances[20] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[20], 0, 0));
                        break;
                    case 21:
                        deviceInstances[21] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[21], 0, 0));
                        break;
                    case 22:
                        deviceInstances[22] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[22], 0, 0));
                        break;
                    case 23:
                        deviceInstances[23] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[23], 0, 0));
                        break;
                    case 24:
                        deviceInstances[24] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[24], 0, 0));
                        break;
                    case 25:
                        deviceInstances[25] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[25], 0, 0));
                        break;
                    case 26:
                        deviceInstances[26] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[26], 0, 0));
                        break;
                    case 27:
                        deviceInstances[27] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[27], 0, 0));
                        break;
                    case 28:
                        deviceInstances[28] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[28], 0, 0));
                        break;
                    case 29:
                        deviceInstances[29] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[29], 0, 0));
                        break;
                    case 30:
                        deviceInstances[30] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[30], 0, 0));
                        break;
                    case 31:
                        deviceInstances[31] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[31], 0, 0));
                        break;
                    case 32:
                        deviceInstances[32] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[32], 0, 0));
                        break;
                    case 33:
                        deviceInstances[33] = DeviceInfoData.DevInst;
                        cr = CM_Disable_DevNode(deviceInstances[33], CM_DISABLE_POLITE);
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[33], 0, 0));
                        break;
                    case 34:
                        deviceInstances[34] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[34], 0, 0));
                        break;
                    case 35:
                        deviceInstances[35] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[35], 0, 0));
                        break;
                    case 36:
                        deviceInstances[36] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[36], 0, 0));
                        break;
                    case 37:
                        deviceInstances[37] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[37], 0, 0));
                        break;
                    case 38:
                        deviceInstances[38] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[38], 0, 0));
                        break;
                    case 39:
                        deviceInstances[39] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[39], 0, 0));
                        break;
                    case 40:
                        deviceInstances[40] = DeviceInfoData.DevInst;
                        CloseHandle(CreateThread(0, SMALL_T, CM_Disable_DevNode_X, &deviceInstances[40], 0, 0));
                        break;
                    default:
                        printf("Debug Error default CM_Disable_DevNode \n");
                        break;
                    }


                }
            }
        }
        // ������ ��� �� �޸� ����
        //delete[] char_ptr;
        delete[] char_ptr;
    }
    static int t_i = 0;


    Sleep(Joy_cmp1); 


    while (t_i <= 40) {
        t_i++;
        //  printf("Test [%d] \n", deviceInstances[t_i]);
        if (deviceInstances[t_i] != NULL) {
            cr = CM_Enable_DevNode(deviceInstances[t_i], CM_DISABLE_POLITE);         //Ȱ�� ��ȯ.
            Sleep(Joy_cmp2); //1000 //�Ľ� �� �����͸� ������ usb�� Ų��.
            while (cr != NULL) { //usb Ȱ�� ���н� �� ������ �翬��
                cr = CM_Enable_DevNode(deviceInstances[t_i], CM_DISABLE_POLITE);
                printf("Usb Disable�� ���� �Ͽ����ϴ�.");
                Sleep(1);
            }
        }



    }
    //UsbTreeView.exe
  //  HINSTANCE secondhInstance = ShellExecuteA(NULL, (LPCSTR)"open", "UsbTreeView.exe", NULL, NULL, SW_SHOW);
    printf("\n ��� ���ν��� Ŭ����. End [%p] \n", x_po);
    ShowWindow(hWnd, SW_SHOW); // ���μ����� �÷ΰ��� �� �ϴ�.
    UpdateWindow(hWnd);
    *Sum = ENABLE;
  //  delete[] bigpointer;//�������� ����
 //   VirtualFree(bigpointer, 0, MEM_RELEASE);

    return 0;
}




void HIDJoyClass::HidLogicStartUp(LPVOID x_po) {
    int* x_pocopy = (int*)x_po;
    printf("HIDJoyClass::HidLogicStartUp���̽�ƽ Ŭ������ �Ѱ� �޴� ���� ���� �Ͽ����ϴ�.\n");
    ThreadProcSocket::First_CreateThread_Collector(SMALL_X, (LPTHREAD_START_ROUTINE)Hid_SystemMain, *&x_pocopy);
}


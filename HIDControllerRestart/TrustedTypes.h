#pragma once
#include "windows_setupapi.h"
#include "pch.h"

#define MAX_AGENT_EXE 41

static CString PortNamesArr0[MAX_AGENT_EXE];
static CString PortNamesArr1[MAX_AGENT_EXE];
static CString PortNamesArr2[MAX_AGENT_EXE];

int* address1 = NULL;
int* address2 = NULL;

int HidCount = 0;
int m_Stop_ORG[30] = { 0 };
int* p_Stop_ORG = m_Stop_ORG;
int m_Stop_COUT = 0;

static int count_xx;

static int debug_x_Tic = NULL;

HDEVINFO hDevInfo = NULL;
GUID* pClassGuid = NULL;
LPCTSTR pszEnumerator = L"USB";

unsigned int Hid_count = 0;
static SP_DEVINFO_DATA DeviceInfoData = { 0 };
DEVPROPTYPE ulPropertyType = 0;
DWORD dwSize = 0;

WCHAR USBInstanceIdentifier[4096] = { 0 };
WCHAR USBDeviceIdentifier[4096] = { 0 };

int* deviceInstances;
int* joystickNamePtr;
int* trustMasterNamePtr;
int* programExecPtr;
int* secondProgramExecPtr;
int* titleClassPtr;
int* pedalPtr;
int* gearSidePtr;
int* p_dll_ptr_x;
int* p_dll_ptr_Five1 = nullptr;
int* p_dll_ptr_Five2 = nullptr;
int* p_dll_ptr_Five3 = nullptr;
int* p_dll_ptr_Five4 = nullptr;
int* p_dll_ptr_Fourth = nullptr;

HWND hWnd;

int requiredSize;
const char* result_char;
char* char_ptr;

static int Joy_cmp1;
static int Joy_cmp2;
static int Joy_cmp3;
static int Joy_cmp4;

static int SwitchOn;
static char* copied_string;
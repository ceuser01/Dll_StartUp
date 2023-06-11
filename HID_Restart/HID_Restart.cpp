#include "pch.h"

static int* p_tPointer;

static void* LibHandle_x2 = nullptr;

static int (*StartFromDLL3)(LPVOID x_p);

STACK_X debug_main_Start(LPVOID x_po) {
	return StartFromDLL3(x_po); //착탄
}

int main()
{

	p_tPointer = new int[ELEMENT_COUNT];
	memset(p_tPointer, 0x00, (ELEMENT_COUNT) * sizeof(int));
	HMODULE hModule = LoadLibrary(L"HIDControllerRestart.dll");
	if (hModule == nullptr) {
		std::cerr << "Failed to load HIDControllerRestart.dll" << std::endl;
		return 1;
	}
	printf("핸들링1[%p]\n", hModule);



	FARPROC FunAddress = GetProcAddress(hModule, "AddAbandon");
	if (FunAddress == nullptr) {
		std::cerr << "Failed to get function address" << std::endl;
		FreeLibrary(hModule);
		return 1;
	}


	printf("핸들링1[%p]\n", FunAddress);
	printf("핸들링1[%p]\n", FunAddress);

	memcpy(&StartFromDLL3, &FunAddress, 8);
	//CloseHandle(CreateThread(nullptr, SMALL_STACK_SIZE, debug_main_Start, &*p_tPointer, 0, nullptr));
	CloseHandle(CreateThread(nullptr, SMALL_STACK_SIZE, debug_main_Start, reinterpret_cast<LPVOID>(&*p_tPointer), 0, nullptr));

	LPCSTR lpOperation = "open";

	LPCSTR lpParameters = NULL;
	LPCSTR lpDirectory = NULL;
	INT nShowCmd = SW_SHOW;
	LPCSTR parameters = ""; // 응용 프로그램에 전달할 매개변수 (필요에 따라 수정)
	SHELLEXECUTEINFOA execInfo = { sizeof(SHELLEXECUTEINFOA) };
	execInfo.lpVerb = "runas"; // 관리자 권한으로 실행하기 위해 "runas"를 사용
	execInfo.lpFile = "voxelTEST-Win64-Shipping.exe";
	execInfo.lpParameters = parameters;
	execInfo.nShow = SW_NORMAL; // 실행 시 윈도우를 보여주기 위해 SW_NORMAL 사용

//	EnableSumPointer = (int*)ptr_bigpointer + ENABLE_OFFSET_FRIST;

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
	Sleep(SLEEP_DURATION);
	return 0;
}



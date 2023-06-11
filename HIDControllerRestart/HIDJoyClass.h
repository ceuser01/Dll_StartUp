#pragma once




#include "pch.h"
#pragma warning(disable:4996)
#include <iostream>
using namespace std;

class HIDJoyClass {
public:
	void static HidLogicStartUp(LPVOID x_po);
	static unsigned long __stdcall Hid_SystemMain(LPVOID x_po);
	static unsigned long __stdcall CM_Disable_DevNode_X(LPVOID x_po);
//	static unsigned long __stdcall CallMyFunctionMultipleTimes(LPVOID x_po, LPCWSTR psz);
	//CallMyFunctionMultipleTimes
	///CM_Disable_DevNode_X
};

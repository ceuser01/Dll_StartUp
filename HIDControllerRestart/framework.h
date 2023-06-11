#pragma once

//#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <cstringt.h>
#include <stdio.h>
#include <atlstr.h>



#include <mmsystem.h>
#include <stdio.h>

#pragma comment(lib, "winmm.lib")


//스타트헤더
#include "Main.h"
#include "ThreadProcSocket.h"
#include "InTerrupt.h"
#include  "FileProcFun.h"
#include  "ConversionLib.h"
#include "HIDJoyClass.h"
#include "JoyClass.h"
#include "ConsoleController.h"
//ConversionLib
#pragma warning(disable:4996)
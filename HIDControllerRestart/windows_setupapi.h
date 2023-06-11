#pragma once



#include <windows.h>
#include <devguid.h>
#include <setupapi.h>
#include <cfgmgr32.h>
#include <tchar.h>
#define INITGUID
#include <tchar.h>
#include <stdio.h>



// PortNamesArr0
// Port_#0007.Hub_#0002


#ifdef DEFINE_DEVPROPKEY
#undef DEFINE_DEVPROPKEY
#endif

#ifdef INITGUID
#define DEFINE_DEVPROPKEY(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8, pid) \
    EXTERN_C const DEVPROPKEY DECLSPEC_SELECTANY name = { \
        { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }, \
        pid \
    }
#else
#define DEFINE_DEVPROPKEY(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8, pid) \
    EXTERN_C const DEVPROPKEY name
#endif

DEFINE_DEVPROPKEY(DEVPKEY_Device_BusReportedDeviceDesc, 0x540b947e, 0x8b40, 0x45bc, 0xa8, 0xa2, 0x6a, 0x0b, 0x89, 0x4c, 0xbd, 0xa2, 4);     // DEVPROP_TYPE_STRING
DEFINE_DEVPROPKEY(DEVPKEY_Device_ContainerId, 0x8c7ed206, 0x3f8a, 0x4827, 0xb3, 0xab, 0xae, 0x9e, 0x1f, 0xae, 0xfc, 0x6c, 2);     // DEVPROP_TYPE_GUID
DEFINE_DEVPROPKEY(DEVPKEY_Device_FriendlyName, 0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 14);    // DEVPROP_TYPE_STRING
DEFINE_DEVPROPKEY(DEVPKEY_DeviceDisplay_Category, 0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x5a);  // DEVPROP_TYPE_STRING_LIST
DEFINE_DEVPROPKEY(DEVPKEY_Device_LocationInfo, 0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 15);    // DEVPROP_TYPE_STRING
DEFINE_DEVPROPKEY(DEVPKEY_Device_Manufacturer, 0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 13);    // DEVPROP_TYPE_STRING
DEFINE_DEVPROPKEY(DEVPKEY_Device_SecuritySDS, 0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 26);    // DEVPROP_TYPE_SECURITY_DESCRIPTOR_STRING
DEFINE_DEVPROPKEY(DEVPKEY_Device_PDOName, 0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 16);    // DEVPROP_TYPE_STRING

//DEVPKEY_Device_InstanceId
DEFINE_DEVPROPKEY(DEVPKEY_Device_InstanceId, 0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 256);   // DEVPROP_TYPE_STRING
DEFINE_DEVPROPKEY(DEVPKEY_Device_TransportRelations, 0x4340a6c5, 0x93fa, 0x4706, 0x97, 0x2c, 0x7b, 0x64, 0x80, 0x08, 0xa5, 0xa7, 11);
#define ARRAY_SIZE(arr)     (sizeof(arr)/sizeof(arr[0]))

#pragma comment (lib, "setupapi.lib")

typedef BOOL(WINAPI* FN_SetupDiGetDevicePropertyW)(
    __in       HDEVINFO DeviceInfoSet,
    __in       PSP_DEVINFO_DATA DeviceInfoData,
    __in       const DEVPROPKEY* PropertyKey,
    __out      DEVPROPTYPE* PropertyType,
    __out_opt  PBYTE PropertyBuffer,
    __in       DWORD PropertyBufferSize,
    __out_opt  PDWORD RequiredSize,
    __in       DWORD Flags
    );




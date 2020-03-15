#include "dllmain.h"
#include"ReflectiveDll.h"

DWORD WINAPI MyThreadFunction() {
    OnProcessAttach();
    test();
    return 0;
}

BOOL WINAPI DllMain(
    HINSTANCE _hinstDLL,  // handle to DLL module
    DWORD _fdwReason,     // reason for calling function
    LPVOID _lpReserved)   // reserved
{
    switch (_fdwReason) {
	case DLL_PROCESS_ATTACH:
        {
        MyThreadFunction();

        }
        break;
    case DLL_PROCESS_DETACH:
        // Perform any necessary cleanup.
        break;
    case DLL_THREAD_DETACH:
        // Do thread-specific cleanup.
        break;
    case DLL_THREAD_ATTACH:
		// Do thread-specific initialization.
        break;
    }
    return TRUE; // Successful.
}
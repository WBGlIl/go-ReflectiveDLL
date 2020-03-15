#include "dllmain.h"
#include<Windows.h>

DWORD WINAPI MyThreadFunction() {
OnProcessAttach();
    return 0;
}

BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpReserved)   // reserved
{
    switch (_fdwReason) {
	case DLL_PROCESS_ATTACH:
        {
        OnProcessAttach();
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
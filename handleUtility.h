// I am tired of writing the same function repeatedly so I'm creating a header file!
// https://docs.microsoft.com/en-us/cpp/cpp/header-files-cpp?view=msvc-160

// REVISIT HEADER GUARD

#include<iostream>
#include<windows.h>



HANDLE returnProcessHandleByProcessID(DWORD pID) {
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, pID);

    if (hProcess == NULL)
    {
        std::cout << "OpenProcess failed to set handle." << std::endl;
        std::cout << "GetLastError() = " << GetLastError() << std::endl;
        getchar();
        return NULL;
    }
    
    return hProcess;
}

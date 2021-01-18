// attacker file - target program is dumb.exe

#include<iostream>
#include<windows.h>
#include<string>

#include<tlhelp32.h>
#include<cstdio>

using namespace std;

int main(int, char *[]) {

    DWORD dumbPid = 0;
    int intRead;

    SIZE_T bytesRead;
    uintptr_t targetAddress;
    
    cout << "Provide target processID: " << endl;
    cin >> dec >> dumbPid;

    // dumbPid = getProcessIdByProcessName("dumb.exe");

    // attempts to fetch handle based on current process id
    // if process handle returns null, throw error
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, dumbPid);
    if(hProcess == NULL) {
        cout << "OpenProcess failed to set handle." << endl;
        cout << "GetLastError() = " << GetLastError() << endl;
        getchar();
        return EXIT_FAILURE;
    }

    cout << "Provide memory address of target variable: " << endl;
    cin >> hex >> targetAddress;

    // A "buffer" simply means a place in memory.
    BOOL rpmReturn = ReadProcessMemory(hProcess, (LPCVOID)targetAddress, &intRead, sizeof(int), &bytesRead);
    if(rpmReturn == FALSE) {
        cout << "ReadProcessMemory failed to read value at " << hex << uppercase << (uintptr_t)targetAddress << endl;
        getchar();
        return EXIT_FAILURE;
    }

    cout << "Value at target address = " << dec << intRead << endl;
    getchar();

    CloseHandle(hProcess);

    return EXIT_SUCCESS;

}


// https://stackoverflow.com/questions/865152/how-can-i-get-a-process-handle-by-its-name-in-c
// attempt at building a function that returns processId by process name

// DWORD getProcessIdByProcessName(const char * processName) {
//     PROCESSENTRY32 entry;
//     entry.dwSize = sizeof(PROCESSENTRY32);

//     HANDLE processSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

//     if(Process32First(processSnapshot, &entry) == true) {
//         while(Process32Next(processSnapshot, &entry) == true) {
//             if(stricmp(entry.szExeFile, processName) == 0) {
//                 return entry.th32ProcessID;
//             }
//         }
//     }

//     CloseHandle(processSnapshot);

//     return 1;
// }

// HANDLE getProcessHandleByTargetProcessIdAndDesiredAccess(DWORD processId, DWORD desiredAccess) {

// }
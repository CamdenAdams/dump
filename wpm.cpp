// Use of WriteProcessMemory
// https://docs.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-writeprocessmemory

#include<iostream>
#include<windows.h>

#include "handleUtility.h"

using namespace std;

int main(int, char *[]) {

    DWORD pID;
    uintptr_t intAddress;

    int intWrite = 545454;
    int intRead;

    int *ptr2Int;

    cout << "Provide target processID: " << endl;
    cin >> dec >> pID;

    HANDLE hProcess = returnProcessHandleByProcessID(pID);
    if (hProcess == NULL) { return EXIT_FAILURE; }

    cout << "Provide memory address of target variable: " << endl;
    cin >> uppercase >> hex >> intAddress;

    BOOL wpm = WriteProcessMemory(hProcess, (LPVOID)intAddress, &intWrite, sizeof(int), NULL);
    if (wpm == false) { cout << GetLastError << endl; }
    
    BOOL rpm = ReadProcessMemory(hProcess, (LPVOID)intAddress, &intRead, sizeof(int), NULL);
    if (rpm == false) { cout << GetLastError() << endl; }
    
    cout << "Value of intRead: " << intRead << endl;
    getchar();

    return EXIT_SUCCESS;
}
// hello

#include<windows.h>
#include<iostream>
#include<string>

using namespace std;

int main() {

    // dumb.exe pid
    DWORD dumbPid = 0;    // https://stackoverflow.com/questions/865152/how-can-i-get-a-process-handle-by-its-name-in-c
    int intRead;

    SIZE_T bytesRead;
    LPCVOID targetAddress;
    
    cout << "Provide target processID: " << endl;
    cin >> dumbPid;

    // attempts to fetch handle based on current process id
    // if process handle returns null, throw error
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, dumbPid);
    if(hProcess == NULL) {
        cout << "OpenProcess failed to set handle." << endl;
        cout << "GetLastError() = " << GetLastError() << endl;
        getchar();
        return EXIT_FAILURE;
    };

    cout << "Provide memory address of target variable: " << endl;
    // istream >> targetAddress;

    // A "buffer" simply means a place in memory.
    BOOL rpmReturn = ReadProcessMemory(hProcess, targetAddress, &intRead, sizeof(int), &bytesRead);
    if(rpmReturn == FALSE) {
        cout << "ReadProcessMemory failed to read value at " << hex << uppercase << (uintptr_t)targetAddress << endl;
        getchar();
        return EXIT_FAILURE;
    };

    cout << "Value at target address = " << dec << rpmReturn << endl;

}
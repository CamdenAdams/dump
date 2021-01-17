// hello

#include<windows.h>
#include<iostream>
#include<string>

using namespace std;

int main() {

    // dumb.exe pid
    int dumbPid = 0;    // https://stackoverflow.com/questions/865152/how-can-i-get-a-process-handle-by-its-name-in-c

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, dumbPid);
    if(hProcess == NULL) {
        cout << "OpenProcess failed to set handle." << endl;
        cout << "GetLastError() = " << GetLastError() << endl;
        getchar();
        return EXIT_FAILURE;
    };
    
    // BOOL WINAPI ReadProcessMemory(
    //     _In_ HANDLE hProcess,
    //     _In_ LPCVOID 
    // )

}
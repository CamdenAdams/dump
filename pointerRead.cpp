// this program is designed to return the value of ptr2int (address of variable) and the value at that address

// instructions:
// Reading a pointer
// You are going to read the value of the pointer "ptr2int" in our dummy program, then you will read the int at the address pointed by this pointer, which will be our integer equal to 123456
// Important thing to remember when dealing with pointers: x86 pointers are 4 bytes long (32 bits) and x64 pointers are 8 bytes long (64 bits) so adapt the parameter "nSize" or ReadProcessMemory depending on the architecture of your target program.


// 

#include<iostream>
#include<windows.h>

using namespace std;

int main(int, char*[]) {

    // target application variables
    DWORD targetPid;
    SIZE_T nSize;

    
    // attacker application variables
    int readInt;
    uintptr_t ptr2ptrAddress;
    uintptr_t ptr2IntAddress;

    // provided from task manager or dumb application output
    cout << "Provide target processID: " << endl;
    cin >> dec >> targetPid;

    // attempts to fetch handle based on current process id
    // if process handle returns null, throw error
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, targetPid);
    if(hProcess == NULL) {
        cout << "OpenProcess failed to set handle." << endl;
        cout << "GetLastError() = " << GetLastError() << endl;
        getchar();
        return EXIT_FAILURE;
    }

    // provided from output of dumb application output
    cout << "Provide memory address of target variable (ptr2int): " << endl;
    cin >> hex >> ptr2IntAddress;

    // A "buffer" simply means a place in memory.
    // SIZE_T is the size of an object in bytes

    // Read Process Memory
        // At given handle (HANDLE hProcess)
        // Here's the memory address of the variable that I would like to read (LPCVOID lpBaseAddress) - Is this a constant because the memory space has already been allocated?
        // Here's the memory address in which I want to store the value read at the memory address provided in parameter two (LPVOID lpBuffer) - Is this not a constanct because the memory space has NOT been alocated?
        // The size, in bytes, of the target value specified at address provided in parameter two
        // 
        // DOCUMENTATION: 


    /**
     * Read Process Memory (https://docs.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-readprocessmemory)
     * 
     * Function used to read value from target processID and specified memory location INTO specified memory location within acting process
     * 
     * @param hProcess - given handle, initialized with OpenProcess, handle must have PROCESS_VM_READ privilages at a minimum to read successfully
     * @param ptr2IntAddress - the memory address of the variable that is to be read. Cast to LPCVOID to prevent errors since this value is provided through console input, I want to mess with this variable declaration
     * @param &intRead - the memory address where we will store the value read at memory address ptr2IntAddress
     * @param sizeof(LPCVOID/unitptr_t) - the amount of bytes to be read from the target location specified by ptr2IntAddress
     * @param lpNumberOfBytesRead - recommended for debugging, pointer to variables that receives the number of bytes transfered into intRead
     * 
     * @return if successful, returns nonzero, otherwise zero
     */
    BOOL rpmReturn = ReadProcessMemory(hProcess, (LPCVOID)ptr2IntAddress, &readInt, sizeof(LPCVOID), NULL);
    if(rpmReturn == FALSE) {
        cout << "ReadProcessMemory failed to read value at " << hex << uppercase << ptr2IntAddress << endl;
        getchar();
        return EXIT_FAILURE;
    }

}
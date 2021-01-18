// dumb program
// simply following instructions and learning/relearning syntax

// dumb and atk need to be different files, build getPidByName

#include<iostream>
#include<windows.h>
#include<string>

#define CHAR_ARRAY_SIZE 128

using namespace std;

int main() {

    const int oneTwoEight = 128;
    bool loop = true;

    // DWORD unsigned integer
    // WORD is the most natural size of a memory pointer
    // DWORD (double word) 32 bit
    // other random notes:
        // BYTE 8 bit
        // WORD 16 bit
        // QWORD (quad word) 64 bit
    DWORD dumbPid = GetCurrentProcessId(); 
    SIZE_T bytesRead = 0;

    // target variables
    int varInt = 123456;
    string varString = "DefaultString";
    char arrChar[CHAR_ARRAY_SIZE] = "Long char array right there ->";

    // target pointers
    int *ptr2int = &varInt;
    int **ptr2ptr = &ptr2int;
    int ***ptr2ptr2 = &ptr2ptr;

    // atk variables
    int intRead = 0;

    do {

        string input;

        cout << "Process ID: " << GetCurrentProcessId() << endl;
        cout << endl;

        cout << "varint        (0x" << hex << uppercase << (uintptr_t)&varInt << ") = " << dec << varInt << endl;
        cout << "varstring     (0x" << hex << uppercase << (uintptr_t)&varString << ") = " << varString << endl;
        cout << "arrChar[128]  (0x" << hex << uppercase << (uintptr_t)&arrChar << ") = " << arrChar << endl;
        cout << endl;
        cout << "ptr2int       (0x" << hex << uppercase << (uintptr_t)&ptr2int << ") = " << ptr2int << endl;
        cout << "ptr2ptr       (0x" << hex << uppercase << (uintptr_t)&ptr2ptr << ") = " << ptr2ptr << endl;
        cout << "ptr2ptr2      (0x" << hex << uppercase << (uintptr_t)&ptr2ptr2 << ") = " << ptr2ptr2 << endl;
        cout << endl;

        // Press ENTER to print again.
        cout << "Enter \"y\" or \"yes\" to exit loop." << endl;
        // getchar();
        cin >> input;
        // cout << "input: " << input << endl;
        // cout << "input == \"y\" >> " << (input == "y") << endl;
        cout << endl << "--------------------------------------------------" << endl << endl;

        if(input == "y" || input == "yes") {
            loop = false;
        };


    } while(loop == true);

    // this logic needs to be added to external file

    // attempts to fetch handle based on current process id
    // if process handle returns null, throw error
    // HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, dumbPid);
    // if(hProcess == NULL) {
    //     cout << "OpenProcess failed to set handle." << endl;
    //     cout << "GetLastError() = " << GetLastError() << endl;
    //     getchar();
    //     return EXIT_FAILURE;
    // };

    // // A "buffer" simply means a place in memory.
    // BOOL rpmReturn = ReadProcessMemory(hProcess, (LPCVOID)&varInt, &intRead, sizeof(int), &bytesRead);
    // if(rpmReturn == FALSE) {
    //     cout << "ReadProcessMemory failed to read value at " << hex << uppercase << (uintptr_t)&varInt << endl;
    //     getchar();
    //     return EXIT_FAILURE;
    // };

    // cout << "intRead = " << dec << intRead << endl;
    // cout << "Press any key to exit" << endl;
    // getchar();

    return 0;
}
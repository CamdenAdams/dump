// dumb program
// simply following instructions and learning/relearning syntax

#include<iostream>
#include<windows.h>
#include<string>

#define CHAR_ARRAY_SIZE 128

using namespace std;

int main() {

    const int oneTwoEight = 128;
    bool loop = true;

    // Variables
    int varInt = 123456;
    string varString = "DefaultString";
    char arrChar[CHAR_ARRAY_SIZE] = "Long char array right there ->";

    // Pointers
    int *ptr2int = &varInt;
    int **ptr2ptr = &ptr2int;
    int ***ptr2ptr2 = &ptr2ptr;



    while(loop = true) {

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
        cout << "Press ENTER to print again.";
        getchar();
        cout << endl << "--------------------------------------------------" << endl << endl;

    }

    return 0;
}
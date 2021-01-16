// Hi, I'm pointing

// vcpkg package manager

#include<iostream>

using namespace std;

int main() {
    // pointers contain memory addresses
    // pointers themselves have memory addresses corresponding to the same number of bytes that the pointer variable type is declared as
        // i.e. int *pointer; << 4 bytes
        // i.e. char *pointer; << 1 byte

    // pointers are declared using * and should reference the variable type of the variable they are pointing to
        // int *pointer; << pointer that contains address for integer
    // variable addresses can be derived by prepending & to variable, i.e. x
        // int x = 10;
        // int *pointer = &x; << sets *pointer equal to memory address of variable x

    // consider the following pointer...
    // int *pointer = &x;
        // print pointer << returns memory address of variable x
        // print &pointer << returns memory address of variable pointer
        // print *pointer << returns value at memory address of x

    // Variable
    int num = 8;
    int *pntr = &num;

    cout << "We have an integer named num - num is an integer initialized with a value of: 8 [int num = 8]" << endl;
    cout << "num value: " << num << " | num address: " << &num << "\n" << endl;
    cout << "We have a pointer to integer called pntr - pntr has been initialized with the memory address of num" << endl;
    cout << "pntr: " << pntr << " Answer: address of num" << " | *pntr: " << *pntr << " Answer: value of num" << " | &pntr: " << &pntr << " Answer: address on pntr" << endl;


}
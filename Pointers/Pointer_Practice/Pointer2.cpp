#include<bits/stdc++.h>
using namespace std;


void Pointer_to_Pointer(){
    int x = 5;
    int *p = &x;
    cout << sizeof(p) << endl;
    cout << sizeof(int*) << endl;
    // The size of pointer is different from device to device and from compiler to compiler.
    // On 64-bit operating systems, a pointer has a size of 64 bits (8 bytes).
    // On 32-bit operating systems, a pointer has a size of 32 bits (4 bytes).

    // We need a pointer of particular type to store the address of a particular type of variable
    int **ptr = &p; // Pointer to Pointer
    cout << &p << endl;
    cout << ptr << endl;
    cout << *ptr << endl;
    cout << &x << endl;
    int ***q = &ptr;
    
    // q ptr p x -----> value = 5
    // q = &ptr;
    // *q = ptr = &p
    // **q = *ptr = p = &x
    // ***q = **ptr = *p = *(&x) = value(5)

    cout << q << ' ' << &ptr << endl;
    cout << *q << ' ' << ptr << ' ' << &p << endl;
    cout << **q << ' ' << *ptr << ' ' << p << ' ' << &x << endl;
    cout << ***q << ' ' << **ptr << ' ' << *p << ' ' << *(&x) << ' ' << 5 << endl;
}

void Increment1(int a){
    a = a + 1;
}

void Increment2(int *a){
    *a = *a + 1;
}


void Pointer_as_function_argument(){
    // Calling by reference
    // Each function has a stack frame
    // The stack is fixed in size.
    int a = 10;
    Increment1(a); // Calling by value
    Increment2(&a); // Calling by reference
    cout << a << endl;
}


void Pointers_and_Arrays(){
    int arr[] = {1, 2, 3, 4, 5};
    short *ptr = (short*)arr; // We don't use &arr because the array is a pointer and it's value is the first address of the whole array
    cout << arr << endl;
    cout << ptr << endl;
    for(int i = 0 ; i < 10;i++){
        cout << *ptr << ' ';
        ptr++;
    }
    // arr++: That is not valid , It's becuase array is treated as a constant pointer in the function it is declared.
    // There is a reason for it. Array variable is supposed to point to the first element in the array or first memeory instance of the block of the 
    // contiguous memeory locations which it is stored, So if we have the liberty to change(increment or decrement) the array pointer, it won't point to the first memeory location of the block. Thus it will loose it's purpose.
}

int main(){


    // Pointer_to_Pointer();


    // Pointer_as_function_argument();


    // Pointers_and_Arrays(); 


    int a = 1;
    cout << ++a + ++a << endl;


    return 0;
}
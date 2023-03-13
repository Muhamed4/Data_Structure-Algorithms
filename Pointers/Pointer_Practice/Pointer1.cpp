#include<bits/stdc++.h>
using namespace std;


void practice1(){
    int a = 11;
    int *p;
    // cout << p << endl;
    // cout << &p << endl;
    //cout << *p << endl; // it gives an error because p is not initialized
    p = &a;
    cout << &a << endl;
    cout << p << endl;
    cout << &p << endl;
    cout << *p << endl; // it gives us the value at the address pointed by p.
    cout << a << endl;
}


void Pointer_Arithmetic(){
    int a = 11;
    int *p = &a;
    cout << p << endl;
    cout << p + 1 << endl;
    // If p is an integer pointer incrementing by 1 unit takes us to the address of the next integer and because the size of integer is 4 byte so to go to the next address we need to skip 4 bytes
    char c = 'a';
    char *ptr = &c;
    cout << c << endl;
    cout << ptr << endl;
    string s = "aaa";
    string *pp = &s;
    cout << &s << endl;
    cout << pp + 1 << endl; // Actually we will add 32 byte to the address of string (s) because the size of string is 32 byte so we should skip 32 byte.
    cout << sizeof(string) << endl;
}


void Pointers_Types(){
    // Isn't that the pointer variables store the addresses of the variables? So why couldn't we have just one type, that will be some generic type to store the address of all kinds of variables?
    // Answer: We do not use the pointer variables only to store the memory addresses, we also use them to dereference these addresses so that we can access and modify the values in these addresses, and as we know data types have different sizes and each data type have different ranges
    // We know that each byte in memory is addressable
    // *ptr: We want to know the value at this pointer (particular address), then the machine sees that ptr is a pointer to integer, so we need to look at four bytes starting address (ptr), and the machine knows that how to extract the value of an integer data type.
    // if we declare a pointer to an integer it will look at address of the first byte of the four byte in memory.
    // if ptr was appointed to float, then although float is also stored in four bytes, but the way information is written for float in these four bytes is different than the way information is returned for an integer data type, so the value printed would have something else.
    int a = 98304 + pow(2, 18); // 360448
    int *ptr = &a;
    short *p = (short*)&a;
    cout << *p << endl;
    cout << *ptr << endl;
    *p = 65536;
    cout << a << endl;
    cout << *p << endl;
    cout << *ptr << endl;
    cout << endl << endl;
    cout << p << endl;
    cout << *p << endl;
    cout << p + 1 << endl; // It will increment the address by 2 unit and skip 2 byte in memory to go to the next short address and it's value will be 5
    cout << *(p + 1) << endl;


    int b = 0;
    short *ptr1 = (short*)&b;
    *ptr1 = 65538;
    cout << b << endl;
    int *ptr2 = (int*)ptr1;
    cout << *ptr2 << endl;
    cout << *ptr1 << endl;
    // ptr1++;
    // cout << *ptr1 << endl;
}


void Pointer_Void_Type(){
    int a = 1025;
    int *p = &a;
    void *ptr = p; // We don't need to write explicite casting because it is a generic pointer
    cout << *((int*)ptr) << endl; // And because this particular pointer type is not mapped to a particular data type we should indicate what it's type.
}

int main(){

    // Each Segment in memory has 1 byte of memory.
    // Each byte of the memeory has an address.
    // When we declare a variable and execute the program, the computer allocates some amount of memory for this variable.
    // How much memory allocates for this variable ? It depends on the data type and the compiler.
    // The Computer has an internal structure, a lookup table where it stores this information that there is a variable (name of varaible) , it's of type interger , and it is located at address (xxxxxxxxx) which is the starting address of the variable
    // Pointer are variable that store the address of another variable
    // If we put * before the pointer it gives us the value at the location that it point to, it is called dereferencing
    // The addresses is different than the previous when we run the programm because every time the programm runs afresh new addresses are located




    //practice1();
    
    //Pointer_Arithmetic();

    //Pointers_Types();

    //Pointer_Void_Type();



    // short x = 32768; /// Short is 2 byte and max value is pow(2, 15) - 1 because the last bit is used to indicate if it is positive or negative
    // x += 65536;
    // cout << x << endl;
    // cout << SHRT_MAX << endl;
    // cout << SHRT_MIN << endl;
    // int xx = 32767 + pow(2, 16) + pow(2, 18);
    // cout << xx << endl;

    return 0;
}
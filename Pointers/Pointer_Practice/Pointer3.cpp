#include<bits/stdc++.h>
using namespace std;

int Sum(int *a){
    // int a[] = int *a
    int sum = 0;
    int size = sizeof(a) / sizeof(a[0]);
    // When we pass the array as a function argument it does not copy the whole array, it just creates a pointer variable by the same name instead of creating the whole array  it just creates a pointer to the data type of the array, So in this case it will be pointed to integer and the compiler just copies the address of the first element in the array of the calling function 
    // The compiler actually interpreted the int a[] to int *a
    // The compiler do that because arrays can be really larg inside so it does not make much sense to create a new copy of the array each time it is unnecessarily using a lot of memeory 
    // This is call by reference.
    cout << sizeof(a) << endl;
    for(int i = 0 ; i < sizeof(a) / sizeof(a[0]);i++){
        sum += a[i]; // a[i] is interpreted as *(a + i)
    }
    return sum;
}


void Array_as_Function_Arguments(){
    int a[] = {1, 2, 3, 4, 5};
    int totalsum = Sum(a);
    cout << totalsum << endl;
    cout << a << endl;
    cout << &a[0] << endl;
}


void print_char(char* c){
    // The function does not know the whole array, it just know the base address of this array.
    int i = 0;
    while(*(c + i) != '\0'){
        cout << *(c + i);
        i++;
    }
    cout << '\n';
}


void Character_Arrays_and_Pointers1(){
    // 1- How to store strings:
    // Size of array >= number of characters in string + 1
    // Rule : a string has to be null terminated '\0'

    //char c[6] = "John\0"; // it must have the length of the string + 1 because the null terminator '\0'
    // cout << sizeof(c) << endl;
    // cout << c << endl;
    // char *ptr = c;
    // while(*ptr != '\0'){
    //     cout << *ptr << endl;
    //     ptr++;
    // }

    // char c[4];
    // c[0] = 'J';
    // c[1] = 'o';
    // c[2] = 'h';
    // c[3] = 'n';
    // cout << sizeof(c) << endl;
    // cout << c << endl;

    // char cc[4] = {'a', 'b', 'd', 'o'}; // the null terminator will not be implicit it must be explicit.
    // cout << sizeof(cc) << endl;
    // cout << cc << endl;


    char ccc[5] = "John";
    print_char(ccc);
    // cout << sizeof(ccc) << endl;
    // cout << ccc << endl;


    // char cccc[10] = {'a', 'b', 'd', 'o'};
    // cout << sizeof(cccc) << endl;
    // cout << cccc << endl;

    // char ccccc[] = "John";
    // cout << sizeof(ccccc) << endl;
    // cout << ccccc << endl;
    // cout << endl;

    char *ptr = ccc;
    ptr++;
    cout << ptr << endl;
    cout << ccc << endl;
    cout << &ccc << endl;
    cout << &ptr << endl;
    cout << &ccc[0] << endl;
    cout << ccc[0] << endl;
}


void oth_print(const char* c){
    while(*c != '\0'){
        cout << *c;
        c++;
    }
    cout << endl;
}
void Character_Arrays_and_Pointers2(){
    // Increment the pointer by one unit is increments the address by size of data type that the pointer point to
    int a[] = {1, 2, 3, 4};
    int *ptr = a;
    char cc[20] = "Hello"; // string gets stored in the space for array
    char *c = "Hello"; // string gets stored as compile time constant, it most probably will be stored in the text (code) segment of the application memeory, and it cannot be modefied
    // c[0] = 'm'; // compilation error
    // cout << c << endl;
    // cout << sizeof(c) << endl;
    const char* p = cc;
    cc[0] = 'M';
    // p[0] = 'H'; cannot modify the string because it is constant pointer.
    cout << p << endl;
    oth_print(cc);
}


int main(){

    // Array_as_Function_Arguments();

    // Character_Arrays_and_Pointers1();

    Character_Arrays_and_Pointers2();

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int Add(int a, int b){
    return a + b;
}

int* Add2(int a, int b){
    int *ptr = new int(10);
    return ptr;
}
void print(){
    cout << "Hello World" << endl;
}

void print2(char* name){
    cout << name << endl;
}

void Function_Pointer(){
    // Pointer can point to functions
    // To create pointer point to a fucntion
    // return type (*name_of_pointer)(the argument type of the function).
    int (*ptr)(int,int) = &Add;
    // cout << ptr << endl;
    int c = (*ptr)(2, 3); // We deference the pointer to get the function and then we pass the arguments
    int x = ptr(4, 5);
    // cout << x << endl;
    // cout << c << endl;
    void (*p)() = print;
    // (*p)();
    // p();

    void (*pp)(char*) = print2;
    //char c[] = "Morsi";
    pp("Morsi");
}

int main(){
    Function_Pointer();


    return 0;
}
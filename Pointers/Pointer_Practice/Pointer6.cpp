#include<bits/stdc++.h>
using namespace std;

void print(){
    cout << "Hello World" << endl;
}
int* Add(int* a, int* b){
    //int *c = (int*)malloc(sizeof(int));
    int c = (*a) + (*b);
    return &c; // This is wrong because i return the address of a local variable and this variable will be destroy after the return statment, so the address of this varaible will be dallocated in the memory.
}

void Pointer_as_Function_Return(){
    int a = 2, b = 4;
    int *ptr = (&a, &b);
    cout << *ptr << endl;
}

struct temp{
    int x;
    long long y;
    float z;
    string s;
};

int main(){

    // Pointer_as_Function_Return();
    vector<int>v;
    // cout << sizeof(vector<int>) << endl;
    // cout << &v << endl;

    temp res;
    cout << sizeof(temp) << endl;
    cout << sizeof(string) << endl;
    //cout << res << endl;
    //temp *ptr() = res;
    return 0;
}
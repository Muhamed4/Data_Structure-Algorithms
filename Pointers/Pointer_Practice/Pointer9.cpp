#include<bits/stdc++.h>
using namespace std;

int* get_value(int a, int b){
    int c = a + b;
    return &c;
}

int* Add(int* a, int* b){
    //int *c = (int*)malloc(sizeof(int));
    int c = (*a) + (*b);
    return &c; // This is wrong because i return the address of a local variable and this variable will be destroy after the return statment, so the address of this varaible will be dallocated in the memory.
}

int& oth_add(int a, int b){
    int c = a + b;
    return c; // This local variable will be destroyed
}

void Reference(){
    int x = 10, y = 20;
    // int &ref = x; // The reference must be of the same data type.
    // cout << ref << endl;
    // ref = &y; can't reassine it to a new address.
    // cout << ref << endl;
    int *ptr = Add(&x, &y);
    // cout << *ptr << endl

    int &ref = oth_add(x, y);
    // cout << ref << endl;

    map<int*,int>mp;
    mp[&x] = 1;
    mp[&y] = 6;
    // cout << mp[&x] << endl;
    // cout << mp[&y] << endl;
    // cout << x << ' ' << y << endl;
    // cout << *&mp[&x] << endl;
    int c = 10;
    int *pt;
    cout << &y << endl;
    cout << &pt << ' ' << pt << ' ' << *pt << endl;
    *pt = 100;
    cout << y << endl;
}

int main(){

    Reference();


    return 0;
}
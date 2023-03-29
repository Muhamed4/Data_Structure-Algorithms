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

void Pointer_and_Constant(){
    int val = 10;
    int val2 = 20;
    const int* ptr = &val;
    ptr = &val2;
    *ptr = 30; // Can't change the value that it point to.
    // cout << *ptr << endl;
    int* const ptr2 = &val;
    *ptr2 = 20;
    ptr2 = &val2; // Can't change it's value.
    // cout << *ptr2 << endl;
    const int* const ptr3 = &val; // const pointer to const
    // *ptr3 = 50; // Can't change data it points to
    // ptr3 = &val2; Can't change its value 
}

int main(){

    // Reference();

    Pointer_and_Constant();
    char str1[] = "belalX";
	char str2[] = "belalY";
 
	char *p1 { str1 };
	char *p2 { str2 };
 
	// cout << (p1 == p2) << " ";
	// cout << (*p1 == *p2);

    return 0;
}
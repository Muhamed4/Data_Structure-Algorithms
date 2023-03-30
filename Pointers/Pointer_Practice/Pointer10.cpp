#include<bits/stdc++.h>
using namespace std;


void fun(int &x){
    cout << x << endl;
    cout << &x << endl;
}

void fun2(const int& x){
    cout << x << endl;
}

void Pointer_Functions(){
    int x = 10;
    int *ptr = &x;
    // fun(*ptr);
    // int &ret = *ptr;
    // cout << &ret << endl;
    // cout << ptr << endl;
    vector<int>v = {1, 2, 3, 3, 2, 5, 6, 4, 6, 3};
    vector<int>*p = &v;
    // cout << &v << endl;
    // cout << v << endl; error, it is not like array.
    // cout << &v[0] << endl;
    // cout << &v[1] << endl;
    // cout << &v[2] << endl;
    // cout << v.capacity() << endl;
    fun2(10); // 10 creates temporary variable to be passed 
    // can only works in 2 cases:
    // void fun(int x);
    // void fun(const int& x);
}

void Dynamic_Memory(){
    // int n;cin >> n;
    // int arr[n];
    int *ptr = new int(10);
    delete ptr;
    ptr = nullptr;
    cout << *ptr << endl;

}
struct Employee
{
    int id = -1;
    string name;
    Employee(){

    }
    Employee(int id_, string name_){
        id = id_;
        name = name_;
    }
    void print(){
        cout << id << ' ' << name << endl;
    }
};

void Pointer_Struct(){
    Employee e1(10, "morsi");
    // e1.print();
    int *x {new int(10)};
    // cout << *x << endl;
    Employee* e2 {new Employee(11, "Abdo")};
    // (*e2).print();
    e2->print();
    Employee* e3 = e2;
    Employee* e4 = &e1;
    e4->print();
    e3->print();
    delete x;
    delete e2;
}


int main(){

    // Pointer_Functions();

    // Dynamic_Memory();

    Pointer_Struct();

    return 0;
}
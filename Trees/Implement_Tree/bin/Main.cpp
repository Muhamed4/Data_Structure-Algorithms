#include <bits/stdc++.h>

using namespace std;

class Test{
    public:
    int x;
    vector<int>v;
    Test(int _size){
        v = vector<int>(_size);
    }
    Test(const Test& oth){
        x = oth.x;
    }
    Test(const initializer_list<int>& in){
        cout << "Initializer_List" << endl;
        for(auto &it: in)v.push_back(it);
    }
    void Pirnt(){
        for(auto &it: v)cout << it << ' ';
        cout << '\n';
    }
};

int x = 10;
int& sol(){
    return x;
}

int main()
{
    // Test t;
    // Test x;
    // x = t;
    // cout << t.x << endl;
    // cout << t.a << endl;
    // cout << "===================================" << endl;
    // cout << x.x << endl;
    // cout << x.a << endl;


    // int a = sol();
    // cout << &a << endl;
    // cout << &sol() << endl;

    // Test temp{1, 2, 3, 4};
    // temp.Pirnt();
    // vector<int>v({1, 2, 3, 4, 5});
    // for(auto &it: v)cout << it << ' ';
    cout << string() << endl;
    return 0;
}
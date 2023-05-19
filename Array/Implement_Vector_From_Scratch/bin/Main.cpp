#include <iostream>
#include <vector>
#include "Vector.hpp"
using namespace DSA;
using namespace std;

int main()
{
    Vector<int>v(5), a(4);
    v[0] = 20;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    v[4] = 5;
    v.at(2) = 222;
    cout << v.at(2) << endl;
    // vector<int>x(2);
    // x.at(0) = 6;
    // cout << x.at(0) << endl;
    return 0;    
}
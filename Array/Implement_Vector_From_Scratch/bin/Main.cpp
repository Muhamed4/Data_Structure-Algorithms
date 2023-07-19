#include <iostream>
#include <vector>
#include "Vector.hpp"
using namespace DSA;
using namespace std;

int main()
{
    Vector<int>v{1, 2, 3, 4, 5};
    for(int i = 0; i < v.size();i++){
        cout << v[i] << ' ';
    }
    return 0;    
}
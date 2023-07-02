#include <bits/stdc++.h>
// #include "../include/HashMapChain.hpp"
#include "../include/HashMapChain.hpp"
using namespace DSA;
using namespace std;



int main()
{
    Unordered_map<string,int>mp;
    mp.add("ali", 1);
    mp.add("Muhamed", 2);
    mp.add("omar", 3);
    mp.add("amr", 44);
    cout << mp["ali"] << endl;
    cout << mp.get("Muhamed") << endl;
    cout << mp.get("omar") << endl;
    cout << mp.get("amr") << endl;
    mp.remove("amr");
    cout << mp["amr"] << endl;

    
    

    return 0;
}
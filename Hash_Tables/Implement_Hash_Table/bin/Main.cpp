#include <bits/stdc++.h>
// #include "../include/HashMapChain.hpp"
#include "../include/HashMapOpenAddressing.hpp"
using namespace std;



int main()
{
    HashMap hash;
    hash.put(1, 10);
    hash.put(2, 20);
    hash.put(3, 30);
    hash.put(4, 40);

    cout << hash.get(2) << endl;

    return 0;
}
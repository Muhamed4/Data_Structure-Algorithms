#include <bits/stdc++.h>

using namespace std;



int main()
{
    map<string,int>mp;
    mp["omar"] = 1;
    mp["ahmed"] = 2;
    mp["khaled"] = 3;
    mp["muhamed"] = 4;
    for(auto &it: mp)cout << it.first << ' ' << it.second << endl;

    return 0;
}
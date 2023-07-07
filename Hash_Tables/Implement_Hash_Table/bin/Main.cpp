#include <bits/stdc++.h>
// #include "../include/HashMapChain.hpp"
#include "../include/HashMapChain.hpp"
using namespace DSA;
using namespace std;



int main()
{
    // Unordered_map<string,int>mp;
    // mp.add("ali", 1);
    // mp.add("Muhamed", 2);
    // mp.add("omar", 3);
    // mp.add("amr", 44);
    // cout << mp["ali"] << endl;
    // cout << mp.get("Muhamed") << endl;
    // cout << mp.get("omar") << endl;
    // cout << mp.get("amr") << endl;
    // mp.remove("amr");
    // cout << mp["amr"] << endl;


    unordered_set<int>st;
    st.insert(4);
    st.insert(1);
    st.insert(2);
    st.insert(3);
    // cout << st.bucket_count() << endl;
    // for(int i = 0; i < 4;i++){
    //     cout << "bucket #" << i << ' ' << st.bucket_size(i) << endl;
    // }

    // cout << st.load_factor() << endl;
    // cout << st.size() << endl;
    // cout << st.bucket_count() << endl;

    // unordered_set<int>::iterator hasher;
    // hasher = st.hash_function();
    // cout << hasher(1000) << endl;

    // st.rehash(15);
    // cout << st.bucket_count() << endl;


    unordered_map<string,int>mp{{"Kai", 2019}, {"Honda", 2020}};
    // cout << mp["Honda"] << endl;
    // mp.insert({"Honda", 2222});
    // cout << mp["Honda"] << endl;

    cout << mp.bucket_count() << endl;

    for(int i = 0; i < mp.bucket_count();i++){
        cout << "buckect #" << ' ' << i << " contains:\n";
        for(auto it = mp.begin(i); it != mp.end(i);it++){
            cout << it->first << ' ' << it->second << endl;
        }
    }

    cout << mp.bucket_size(1) << endl;

    

    
    

    return 0;
}
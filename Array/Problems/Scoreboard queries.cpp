#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    #endif
    int t;cin >> t;
    while(t--){
        int n, t;cin >> n >> t;
        vector<int>v(n + 1);
        map<int,int>mp;
        set<int>st;
        for(int i = 1; i <= n;i++){
            cin >> v[i];
            mp[v[i]]++;
            st.insert(v[i]);
        }
        while(t--){
            int pos, val;cin >> pos >> val;
            mp[v[pos]]--;
            if(mp[v[pos]] == 0)st.erase(v[pos]);
            v[pos] = val;
            mp[val]++;
            st.insert(val);
            cout << (int)st.size() + 1 << '\n';
        }
    }
}
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
        int n, k;cin >> n >> k;
        map<int,long long>mp;
        for(int i = 0 ; i < n;i++){
            int x;cin >> x;
            mp[x] += x;
        }
        long long ans = 0;
        priority_queue<long long>p;
        for(auto it: mp)p.push(it.second);
        while(!p.empty() && p.top() > 0 && k--){
            ans += p.top();
            p.pop();
        }
        cout << ans << '\n';
    }

}
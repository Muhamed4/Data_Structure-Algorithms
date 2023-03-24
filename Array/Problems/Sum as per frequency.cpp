#include<bits/stdc++.h>
using namespace std;

long long solve(vector<long long>&prefix, int l, int r){
    return prefix[r] - prefix[l - 1];
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    #endif

    int n;cin >> n;
    map<int,int>mp;
    for(int i = 0 ; i < n;i++){
        int x;cin >> x;
        mp[x]++;
    }
    vector<long long>prefix(n + 1);
    for(auto it: mp){
        prefix[it.second] += (1ll*it.first * it.second);
    }
    for(int i = 1 ; i <= n;i++)prefix[i] += prefix[i - 1];
    int t;cin >> t;
    while (t--){
        int l, r;cin >> l >> r;
        cout << solve(prefix, l, r) << '\n'; // Don't use endl it will take more time and cause time limit because it flush the output.
    }
    
}
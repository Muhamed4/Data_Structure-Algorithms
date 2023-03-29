#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    #endif
    int n;cin >> n;
    vector<int>v(n);
    for(auto &it: v)cin >> it;
    int ans = 1;
    for(int i = 1; i < n;i++){
        if(v[i] != v[i - 1])ans++;
    }
    cout << ans << endl;
}
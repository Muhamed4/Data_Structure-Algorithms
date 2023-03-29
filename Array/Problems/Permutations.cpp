#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    #endif
    int n, t;cin >> n >> t;
    vector<int>v(n + 1), left(n + 2), right(n + 2);
    for(int i = 1; i <= n;i++)cin >> v[i];
    for(int i = 1; i <= n;i++)left[i] = max(left[i - 1], v[i]);
    for(int i = n; i >= 1;i--)right[i] = max(right[i + 1], v[i]);
    while(t--){
        int l, r;cin >> l >> r;
        cout << max(left[l - 1], right[r + 1]) << '\n';
    }

}
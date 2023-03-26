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
        vector<int>v(n);
        long long sum = 0;
        for(auto &it: v){
            cin >> it;
            sum += it;
        }
        long long l = n, r = 2e14, mid = 0, ans = 0;
        while(l <= r){
            mid = (l + r) / 2;
            long long res = sum / mid;
            if(res <= k){
                ans = mid - n;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        cout << ans << '\n';
    }
}
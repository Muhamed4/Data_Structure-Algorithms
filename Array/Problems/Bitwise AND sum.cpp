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
        int n;cin >> n;
        vector<int>v(n);
        vector<pair<int,int>>cnt(27);
        long long res = 1ll*n * (n + 1) / 2;
        for(int i = 0 ; i < 27;i++) cnt[i].first = 1e9, cnt[i].second = -1;
        for(int i = 0 ; i < n;i++){
            cin >> v[i];
            bitset<27>bit(v[i]);
            for(int j = 0 ; j < 27;j++){
                if(!bit[j]){
                    cnt[j].first = min(cnt[j].first, i);
                    cnt[j].second = max(cnt[j].second, i);
                }
            }
        }
        //for(auto it: cnt)cout << it.first << ' ' << it.second << endl;
        long long ans = 0;
        for(int i = 0 ; i < 27;i++){
            long long cost = (1 << i);
            if(cnt[i].second == -1){
                ans += ((res - 1) * cost);
                continue;
            }
            if(cnt[i].first == 0 && cnt[i].second == n - 1)continue;
            if(cnt[i].first > 0 && cnt[i].second < n - 1){
                long long x = cnt[i].first + 1, y = n - cnt[i].second;
                long long total = x * y - 1;
                ans += (total * cost);
            }
            else if(cnt[i].first == 0) ans += (1ll*(n - cnt[i].second - 1) * cost);
            else if(cnt[i].second == n - 1) ans += (1ll*cnt[i].first * cost);
        }
        cout << ans << '\n';
    }
}
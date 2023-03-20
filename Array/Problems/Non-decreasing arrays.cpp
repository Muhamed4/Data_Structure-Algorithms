#include<bits/stdc++.h>
// ordered set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(vector<long long>&v){
    long long first = v[0];
    for(auto &it: v){
        long long l = 1, r = first / it + 10, mid = 0, ans = 0;
        while(l <= r){
            mid = (l + r) / 2;
            long long res = 1ll*mid * it;
            if(res >= first){
                ans = res;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        cout << ans << ' ';
        first = ans;
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    #endif
	int t;cin >> t;
	while(t--){
        int n;cin >> n;
        vector<long long>v(n);
        for(auto &it: v)cin >> it;
        solve(v);
	}
	return 0;
}
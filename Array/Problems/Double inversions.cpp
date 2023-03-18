#include<bits/stdc++.h>
// ordered set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>;

vector<int> Inversion(vector<int>&a, vector<int>&b){
    vector<int>ans;
    int n = (int)a.size(), idx = n - 1;
    for(int i = 0; i < n;i++){
        int x = i, y = idx;
        if(a[i] > x || b[idx] > y){
            return {-1};
        }
        int res = n - a[i] - b[idx];
        ans.push_back(res);
        --idx;
    }
    map<int,int>mp;
    ordered_set<int>st;
    for(int i = 0 ; i < n;i++){
        st.insert(ans[i]);
        ++mp[ans[i]];
        int res = (int)st.size() - st.order_of_key(ans[i]) - mp[ans[i]];
        if(res != a[i])return {-1};
    }
    return ans;
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
		vector<int>a(n), b(n);
		for(auto &it : a)cin >> it;
		for(auto &it : b)cin >> it;
        for(auto it: Inversion(a, b))cout << it << ' ';
        cout << '\n';
	}
	return 0;
}
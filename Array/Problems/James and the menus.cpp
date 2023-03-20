#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    #endif
	int n, m;cin >> n >> m;
    vector<vector<int>>v(n, vector<int>(m));
    vector<long long>mx(m), sum(n);
    for(int i = 0 ; i < n;i++){
        for(int j = 0 ; j < m;j++){
            cin >> v[i][j];
            mx[j] = max(mx[j], 1ll*v[i][j]);
            sum[i] += v[i][j];
        }
    }
    set<pair<int,pair<long long,int>>>st;
    map<int,int>cur_ans;
    for(int i = 0; i < n;i++){
        st.insert({0,{sum[i], i}});
    }
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++){
            if(v[i][j] == mx[j]){
                pair<int,pair<long long,int>> p = {cur_ans[i], {sum[i], i}};
                st.erase(st.find(p));
                ++p.first;
                st.insert(p);
                cur_ans[i] = p.first;
            }
        }
    }
    cout << (*prev(st.end())).second.second + 1 << endl;
	return 0;
}
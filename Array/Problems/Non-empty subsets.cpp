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
        long long _or = 1e10;
        for(auto &it: v){
            cin >> it;
            _or = min(_or, 1ll*it);
        }
        cout << _or << endl;
	}
	return 0;
}
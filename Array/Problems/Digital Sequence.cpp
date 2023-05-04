#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    #endif
    int n;cin >> n;
    int *v = new int[n];
    map<int,int>mp;
    for(int i = 0; i < n;i++){
        cin >> v[i];
        int *frq = new int[10];
        for(int j = 0 ; j < 10;j++)frq[j] = 0;
        // memset(frq, 0, sizeof(frq));
        // for(int j = 0 ; j < 10;j++)cout << frq[j] << ' ';
        // cout << endl;
        //while(v[i] % 10 == 0)v[i] /= 10;
        while(v[i]){
            int x = v[i] % 10;
            if(!frq[x])mp[x]++;
            frq[x]++;
            v[i] /= 10;
        }
        delete[] frq;
    }
    int ans = 0;
    for(auto &it: mp){
        ans = max(ans, it.second);
        //cout << it.first << ' ' << it.second << endl;
    }
    cout << ans << endl;
    delete[] v;
}